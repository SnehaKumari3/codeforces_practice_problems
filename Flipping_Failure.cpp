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

vector<int> adj[1000001];
int vis[1000001];
int deg[1000001];

int minimumColors(int n)
{
 
    vector<int> colors(n+1, 1);
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            Q.push(i);
        }
    }
 
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
 
        for (auto x : adj[u]) {
            deg[x]--;
            if (deg[x] == 0) {
                Q.push(x);
            }
 
            if (colors[x] <= colors[u]) {
                colors[x] = 1 + colors[u];
            }
        }
    }
 
    int minColor = -1;
 
    for (int i = 1; i <= n; i++) {
        minColor = max(minColor, colors[i]);
    }
    return minColor;
}


int main()
{
    FAST;
    // your code goes here
    ll t = 1;

    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        
        rep(i, 0, n - 1)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
        }
        ll ans=minimumColors(n);

        if(ans >= c){
            cout<<0;
        }
        else{
            cout<<ans;
        }

        cout << endl;
    }

    return 0;
}