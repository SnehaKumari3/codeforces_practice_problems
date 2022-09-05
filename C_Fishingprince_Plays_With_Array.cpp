#include <bits/stdc++.h>

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
#define pp pop_back
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

ll rem(ll a, ll b, ll c)
{
    return a % 2 + b % 2 + c % 2;
}

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vl a(n,0);
        mll m1,m2;
        
        rep(i,0,n){
            cin>>a[i];
        }
        cin>>n;
        vl b(n,0);
        rep(i,0,n){
            cin>>b[i];
        }
        vpll v1,v2,v3,v4;
        rep(i,0,sz(a)){
            ll t=a[i];
            while(t%m==0){
                t/=m;
            }
            if(a[i]%m==0){
                v1.pb({t,a[i]/t});
            }
            else{
                v1.pb({a[i],1});
            }
            // cout<<v1.back().fi<<" "<<v1.back().se<<endl;
        }
        
        rep(i,0,sz(b)){
            ll t=b[i];
            while(t%m==0){
                t/=m;
            }
            if(b[i]%m==0){
                v2.pb({t,b[i]/t});
            }
            else{
                v2.pb({b[i],1});
            }
        }

        // sort(all(v1)),sort(all(v2));

        v3.pb(v1[0]);
        rep(i,1,sz(v1)){
            if(v1[i].fi==v3.back().fi){
                v3.back().se+=v1[i].se;
            }
            else{
                v3.pb(v1[i]);
            }
        }

        v4.pb(v2[0]);
        rep(i,1,sz(v2)){
            if(v2[i].fi==v4.back().fi){
                v4.back().se+=v2[i].se;
            }
            else{
                v4.pb(v2[i]);
            }
        }

        if(v3==v4){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
        

        cout << endl;
    }
    return 0;
}