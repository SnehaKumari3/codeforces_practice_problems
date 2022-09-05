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

int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m, q;
        cin >> n >> m >> q;
        ll a, b;
        vector<pll> inner, outer;
        for (ll i = 1; i <= n; i++)
        {
            a = 100 * i, b = n;
            ll g = __gcd(a, b);
            inner.pb({a / g, b / g});
        }
        for (ll i = 1; i <= m; i++)
        {
            a = 100 * i, b = m;
            ll g = __gcd(a, b);
            outer.pb({a / g, b / g});
        }

        set<pll> s;
        ll j = 0, i = 0;
        for (; i < inner.size();)
        {
            if (inner[i].fi == inner[j].fi && outer[i].se == outer[j].se)
            {
                s.in({i + 1, j + 1});
                i++, j++;
            }
            else
            {
                if (t1 < t2)
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }


        for (auto x : s)
        {
            cout << x.fi << " " << x.se << endl;
        }
        
        while (q--)
        {
            
        }
    }
}