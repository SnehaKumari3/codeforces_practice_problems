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

char g[52][52];

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    cin >> t;
    while (t--)
    {
        memset(g, '.', sizeof(g));
        ll n, m;
        cin >> n >> m;
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                cin >> g[i][j];
            }
        }
        bool ans = true;
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                if (g[i][j] == '*')
                {
                    int cnt = 0;
                    int p = 0;
                    int q = 0;
                    for (int k = -1; k < 2; k++)
                    {
                        for (int l = -1; l < 2; l++)
                        {
                            if (0 <= i + k && i + k < n && 0 <= j + l && j + l < m && g[i + k][j + l] == '*')
                            {
                                cnt++;
                                p += k;
                                q += l;
                            }
                        }
                    }
                    if (cnt != 3 || !p || !q)
                        ans = false;
                }
            }
        }
        if (ans)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}