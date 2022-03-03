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
    ll n,k;
        cin>>n>>k;
        vl t(n+1,0);
        vl c(n+1,0);
        rep(i,1,n+1){
            cin>>t[i];
            t[i]+=t[i-1];
        }
        rep(i,1,n+1){
            cin>>c[i];
            c[i]+=c[i-1];
        }

        vl dp(n+1,-1e18);
        rep(i,1,n+1){
            rep(j,i,n+1){
                ll tmp1=(t[j]-t[i-1])/(c[j]-c[i-1]);
                ll tmp2=(t[j]-t[i-1])%(c[j]-c[i-1]);
                if(tmp2==0 && tmp1==k){
                dp[j-i+1]=max(dp[j-i+1],t[j]-t[i-1]);
                }
            }
        }
        
        ll ans=*max_element(all(dp));
        if(ans>0){
            cout<<ans;
        }
        else{
            cout<<-1;
        }

    return 0;
}