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


int main()
{
    FAST;
    // your code goes here
    ll t,cnt=0;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vpll v;
        v.pb({0,0});
        rep(i,0,n){
            ll a,b;
            cin>>a>>b;
            v.pb({a,b});
        }
        sort(all(v));
        string ans="";
        bool ok=true;
        rep(i,1,n+1){
            ll d1=v[i].fi-v[i-1].fi;
            ll d2=v[i].se-v[i-1].se;
            if(d1<0 || d2<0){
                ok=false;
                break;
            }
            while(d1--){
                ans+='R';
            }
            while(d2--){
                ans+='U';
            }
        }
        if(ok){
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}