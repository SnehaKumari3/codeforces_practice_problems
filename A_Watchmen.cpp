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


int main()
{
    FAST;
    // your code goes here
    ll n,s=0;
    cin>>n;
    vpll v;
    mll mx,my;
    map<pll,ll> m;
    rep(i,0,n){
        ll a,b;
        cin>>a>>b;
        m[{a,b}]++;
        v.pb({a,b});
        mx[a]++;
        my[b]++;
    }
    
    ll ans=0;
    rep(i,0,n){
        auto it1 = mx.find(v[i].fi);
        auto it2 = my.find(v[i].se);
        if ( it1 == mx.end() && it2==my.end() ){
            continue;
        }
        else{
            
            if(it1->se > 1){
                ans+=(it1->se-1);
            }
            if(it2->se > 1){
                ans+=(it2->se-1);
            }
            it1->se--;
            it2->se--;
        }
        
    }
    for(auto i:m){
        if(i.se>1){
            ll t=i.se-1;
            s+=(t*(t+1))/2;
        }
    }
    
    cout<<ans-s;
    
    return 0;
}