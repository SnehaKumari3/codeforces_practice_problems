#include <bits/stdc++.h>
#include <algorithm>
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
#define INF 10007
vl adj[100005];

int vis[100005], a[100005], b[100005];
ll n;
vl ans;
void bfs1(int s)
{
    int v[n+1];
    rep(i, 1, n+1)
    {
        v[i] = vis[i];
    }
    queue<pair<int, int>> q1;
    int cnt = 1;
    q1.push({s, cnt});
    
    while (!q1.empty())
    {
        int curr = q1.front().first;
        int rel = q1.front().second;
        
        v[curr] = 1;
        q1.pop();
        cnt=rel+1;
        for (auto u : adj[s])
        {

            if (vis[u] == 0)
            {
                if (rel % 2 == 1)
                {
                    if (a[u] == 0)
                        a[u] = 1;
                    else
                        a[u] = 0;
                }
                q1.push({u, cnt});
            }
        }
    }
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        
        int curr = q.front();
        vis[curr] = 1;
        q.pop();
        if (a[curr] != b[curr])
        {
            ans.pb(curr);
            bfs1(curr);
        }
        for (auto u : adj[curr])
        {
            if (vis[u] == 0)
            {
                q.push(u);
            }
        }
    }
}

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    // cin >> t;
    while (t--)
    {

        cin >> n;
        rep(i, 0, n - 1)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        rep(i, 1, n + 1)
        {
            cin >> a[i];
        }
        rep(i, 1, n + 1)
        {
            cin >> b[i];
        }
        bfs(1);
        ll res=ans.size();
        cout<<res<<endl;
        rep(i,0,res){
            cout<<ans[i]<<endl;
        }
        cout << endl;
    }

    return 0;
}