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
int a[N],segTree[4*N];

void construct(int node,int start,int end){
    if(start==end) {
        segTree[node]=a[start];
        return;
    }

    int mid=(start+end)/2;
    construct(2*node+1,start,mid);
    construct(2*node+2,mid+1,end);
    segTree[node]=segTree[2*node +1] + segTree[2*node +2];
}


void update(int node,int start,int end,int index){
    if(start==end && start==index) {
        segTree[node]=a[index];
        return;
    }

    
    int mid=(start+end)/2;
    if(index<=mid)
    update(2*node+1,start,mid,index);
    else 
    update(2*node+2,mid+1,end,index);
    segTree[node]=segTree[2*node +1] + segTree[2*node +2];
}
//descend the segTree
int query(int node,int start,int end,int k){
    if(start==end){
        return start;
    }
    
    int mid=(start+end)/2;
    if(k < segTree[2*node +1]){
        return query(2*node+1,start,mid,k);
    }
    return query(2*node+2,mid+1,end,k-segTree[2*node +1]);
}


int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        int64_t n,q;
        cin >> n>>q;
        rep(i,0,n){
            cin>>a[i];
        }
        construct(0,0,n-1);
        
        while(q--){
            ll t,l,r;
            cin>>t>>l;
            if(t==1){
                a[l]=!a[l];
                update(0,0,n-1,l);
            }
            else{
                cout<<query(0,0,n-1,l)<<endl;
            }
        }
        cout << endl;
    }
}