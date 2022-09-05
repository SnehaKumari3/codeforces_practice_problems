#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

typedef int64_t ll;
typedef long double ld;
typedef double db;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<string, ll> msl;
typedef map<string, string> mss;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define pf push_front
#define pop pop_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define mem0(a) memset(a, 0, sizeof(a))
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repr(i, n, b) for (ll i = n; i > b; i--)
#define repv(v) for (auto x : v)
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof a)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define sz(v) ll(v.size())
#define mod 1000000007

const int N=1e5+2;
int64_t a[N];
pair<ll,ll> segTree[4*N];

void construct(int node,int start,int end){
    if(start==end) {
        segTree[node].fi=a[start];
        segTree[node].se=1;
        return;
    }

    int mid=(start+end)/2;
    construct(2*node+1,start,mid);
    construct(2*node+2,mid+1,end);

    if(segTree[2*node + 1].fi < segTree[2*node +2].fi){
        segTree[node].fi=segTree[2*node + 1].fi;
        segTree[node].se=segTree[2*node + 1].se;
    }
    if(segTree[2*node + 1].fi > segTree[2*node +2].fi){
        segTree[node].fi=segTree[2*node + 2].fi;
        segTree[node].se=segTree[2*node + 2].se;
    }
    if(segTree[2*node + 1].fi == segTree[2*node +2].fi){
        segTree[node].fi=segTree[2*node + 1].fi;
        segTree[node].se=segTree[2*node + 1].se + segTree[2*node + 2].se;
    }
    
}


void update(int node,int start,int end,int index){
    if(start==end && start==index) {
        segTree[node].fi=a[start];
        segTree[node].se=1;
        return;
    }

    if(index<start || end<index) return ;
    int mid=(start+end)/2;
    update(2*node+1,start,mid,index);
    update(2*node+2,mid+1,end,index);
    if(segTree[2*node + 1].fi < segTree[2*node +2].fi){
        segTree[node].fi=segTree[2*node + 1].fi;
        segTree[node].se=segTree[2*node + 1].se;
    }
    if(segTree[2*node + 1].fi > segTree[2*node +2].fi){
        segTree[node].fi=segTree[2*node + 2].fi;
        segTree[node].se=segTree[2*node + 2].se;
    }
    if(segTree[2*node + 1].fi == segTree[2*node +2].fi){
        segTree[node].fi=segTree[2*node + 1].fi;
        segTree[node].se=segTree[2*node + 1].se + segTree[2*node + 2].se;
    }
}

pair<ll,ll> query(int node,int start,int end,int left,int right){
    if(end<left || start>right) return {INT_MAX,0};

    if(start>=left && end<=right) return segTree[node];

    int mid=(start+end)/2;
    pair<ll,ll> t1=query(2*node + 1,start,mid,left,right);
    pair<ll,ll> t2=query(2*node+2,mid+1,end,left,right);
    if(t1.fi < t2.fi){
        return t1;
    }
    if(t1.fi > t2.fi){
        return t2;
    }
    pair<ll,ll> t3;
    t3.fi=t1.fi;
    t3.se=t1.se+t2.se;
    return t3;
}




int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n,q;
        cin >> n>>q;
        rep(i,0,n){
            cin>>a[i];
        }
        construct(0,0,n-1);
        
        while(q--){
            ll t,l,r;
            cin>>t>>l>>r;
            if(t==1){
                a[l]=r;
                update(0,0,n-1,l);
            }
            else{
                pair<ll,ll> x=query(0,0,n-1,l,r-1);
                cout<<x.fi<<" "<<x.se<<endl;
            }
        }
        cout << endl;
    }
}