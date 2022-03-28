#include <bits/stdc++.h>
#include <algorithm>
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


bool compare(vl a,vl b){
    ll m1=*max_element(all(a));
    ll m2=*max_element(all(b));
    return m1>m2;
}

int main()
{
    FAST;
    // your code goes here
    ll t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>> v;
        rep(i,0,n){
            ll k;
            cin>>k;
            vl t;
            rep(j,0,k){
                ll a;
                cin>>a;
                t.pb(a);
            }
            v.pb(t);
        }
        vl res;
        sort(all(v),compare);
        rep(i,0,n){
            int mindex = std::max_element(v[i].begin(),v[i].end()) - v[i].begin();
            ll ans=*max_element(all(v[i]))+1-mindex;
            res.pb(ans);
        }
        sort(all(res));
        ll res1=res[0];
        rep(i,1,sz(res)){
            if((res1+v[i-1].size())<v[i]){
                
            }
        }

    }
     
    
    return 0;
}