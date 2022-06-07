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
    
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vpll v;
        mll m;
        rep(i,0,n){
            ll a;
            cin>>a;
            m[a]++;
            v.pb({a,i});
        }
        bool ok=true;
        for(auto i:m){
            if(i.se==1){
                ok=false;
                break;
            }
        }
        if(ok){
            sort(all(v));
            vpll ans;
            ll start=0,i;
            for(i=1;i<n;i++){
                if(v[i].fi==v[i-1].fi){
                    ans.pb({v[i].se,v[i-1].se +1});
                }
                else{
                    ans.pb({v[start].se,v[i-1].se +1});
                    start=i;
                }
            }
            ans.pb({v[start].se,v[i-1].se +1});
            sort(all(ans));
            rep(i,0,sz(ans)){
                cout<<ans[i].se<<" ";
            }
        }
        else{
            cout<<-1;
        }
        cout<<endl;
    }
    
    
    return 0;
}