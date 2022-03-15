#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repr(i, n, b) for (ll i = n; i > b; i--)
#define repv(v) for (auto x : v)
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof a)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define sz(v) ll(v.size())
#define mod 1000000007

bool isSort(vl v){
    rep(i,1,sz(v)){
        if(v[i]<v[i-1]){
            return false;
        }
    }
    return true;
}
int main()
{
    FAST;
    // your code goes here
    ll t=1;
    cin>>t;
    while(t--){
        ll n,m1,x;
        cin>>n>>m1>>x;
        vpll v;
        rep(i,0,n){
            ll a;
            cin>>a;
            v.pb({a,i});
        }
        sort(all(v));
        vl ans(n),m(m1,0);
        ll num=n,tmp=m1;
        while(num && tmp){
            ans[v[num-1].se]=tmp;
            m[tmp-1]+=v[num-1].fi;
            num--;
            tmp--;
            if(tmp==0){
                tmp=m1;
            }
            
        }
        sort(all(m));
        if(m[m1-1]-m[0]>x && m1>1){
            cout<<"NO";
        }
        else{
            cout<<"YES"<<endl;
            rep(j,0,n){
                cout<<ans[j]<<" ";
            }
        }
        
        cout<<endl;
    }
    
    return 0;
}