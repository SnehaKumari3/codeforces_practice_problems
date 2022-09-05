#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
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
#define pop pop_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define mem0(a) memset(a, 0, sizeof(a))
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repr(i, n, b) for (ll i = n; i > b; i--)
#define repv(v) for (auto x : v)
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof a)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define sz(v) ll(v.size())
#define mod 1000000007

vl adj[100001];
vl vis(100001, 0);
vl res(100001, 0);
vl result;

void dfs(int curr)
{
    vis[curr] = 1;
    bool ok = true;

    for (auto child : adj[curr])
    {
        if (res[child] == 0)
        {
            ok = false;
        }
        if (vis[child] == 0)
        {
            dfs(child);
        }
    }

    if (res[curr]==1 && ok)
    {
        result.pb(curr);
    }
}

int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, x, par = 0;

        cin >> n;

        rep(i, 1, n + 1)
        {
            cin >> x >> res[i];
            if (x == -1)
            {
                par = i;
            }
            else
            {
                adj[x].pb(i);
            }
        }

        

        dfs(par);
        
        if (result.size() ==0  || n==1)
        {
            cout << -1;
        }
        else
        {
            sort(all(result));
            for (auto x : result)
            {
                cout << x << " ";
            }
        }
    }
}