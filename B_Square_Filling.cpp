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

bool isValid(ll x,ll y,ll n,ll m){
    if(x-1>=0 && y-1>=0){
        if(a[x-1][y-1]==1 && a[x-1][y]==1 && a[x][y-1]==1 && a[x][y]==1){
            b[x][y]=1;
        }
    }
    else if(x-1>=0 && y-1>=0){
        if(a[x-1][y-1]==1 && a[x-1][y]==1 && a[x][y-1]==1 && a[x][y]==1){
            b[x][y]=1;
        }
    }
}
int main()
{
    FAST;
    // your code goes here
    ll t = 1;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        int a[n][m], b[n][m];
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                cin >> a[i][j];
                b[i][j] = 0;
            }
        }
        set<pair<int, int>> s;
        bool ok = true;
        repr(i, n-1, 0)
        {
            rep(j, m-1, 0)
            {
                if (a[i][j] == b[i][j])
                {
                    continue;
                }
                else
                {
                    if (a[i][j] == 1)
                    {
                        ll x = i-1, y = j-1;
                        s.insert({x + 1, y + 1});
                        b[x][y] = 1;
                        b[x][y + 1] = 1;
                        b[x + 1][y] = 1;
                        b[x + 1][y + 1] = 1;
                    }
                }
            }
        }
        for (ll i = 0; i < n && ok; i++)
        {
            for (ll j = 0; j < m && ok; j++)
            {
                if(a[i][j]!=b[i][j]){
                    ok=false;
                }
            }
        }

        if (ok)
        {
            cout << s.size() << endl;
            for (auto i : s)
            {
                cout << i.fi << " " << i.se << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}