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
set<int> s;
vl ans;

void bfs(int s)
{
    queue<pair<int, int>> q;
    int l = 1;
    q.push({s, l});
    while (!q.empty())
    {
        int curr = q.front().first;
        int l = q.front().second;
        vis[curr] = 1;
        q.pop();
        if (l % 2 == 1)
        {
            if(o%2==1){
                if(a[curr]==0){
                    a[curr]=1;
                }
                else{
                    a[curr]=0;
                }
            }
        }
        else
        {
            if(e%2==1){
                if(a[curr]==0){
                    a[curr]=1;
                }
                else{
                    a[curr]=0;
                }
            }
        }
        if (a[curr] != b[curr])
        {
            ans.pb(curr);
            s.insert(l+2);
        }

        for (auto u : adj[curr])
        {
            if (vis[u] == 0)
            {
                q.push({u, l + 1});
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
        ll res = ans.size();
        cout << res << endl;
        rep(i, 0, res)
        {
            cout << ans[i] << endl;
        }
        cout << endl;
    }

    return 0;
}