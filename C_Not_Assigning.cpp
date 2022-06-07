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
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        mll m;
        vector<pll> adj[n + 1];
        rep(i, 0, n - 1)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb({v, i});
            adj[v].pb({u, i});
        }

        int sz = 1, curr;
        rep(i, 1, n + 1)
        {
            if (adj[i].size() > 2)
            {
                sz = 0;
            }
            if (adj[i].size() == 1)
            {
                curr = i;
            }
        }
        if (sz)
        {
            vl ans(n - 1, 0);
            vl vis(n + 1, 0);
            int w = 2;
            while (vis[curr] == 0)
            {

                vis[curr] = 1;
                for (auto j : adj[curr]){
                    if (vis[j.fi] == 0)
                    {
                        ans[j.se] = w;
                        w ^= 1;
                        curr = j.fi;
                        break;
                    }
                }
                    
            }
            rep(i,0,n-1){
                cout<<ans[i]<<" ";
            }
        }
        else
        {
            cout << -1;
        }
        cout<<endl;
    }
    
    return 0;
}