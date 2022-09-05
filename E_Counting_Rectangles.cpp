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


ll dp[1010][1010];

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    cin >> t;
    while (t--)
    {
        memset(dp,0,sizeof(dp));
        ll n,q;
        cin>>n>>q;
        rep(i,0,n){
            ll x,y;
            cin>>x>>y;
            dp[x][y]+=x*y;
        }
        for(int i=1;i<=1000;i++){
            for(int j=1;j<=1000;j++){
                dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }

        while(q--){
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            cout<<dp[c-1][d-1]+dp[a][b]-dp[c-1][b]-dp[a][d-1]<<endl;
        }
        
    }
    
    return 0;
}