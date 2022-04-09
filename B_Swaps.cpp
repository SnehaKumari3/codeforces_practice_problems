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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vpll o, e;
        rep(i, 0, n)
        {
            ll a;
            cin >> a;
            o.pb({a, i});
        }
        rep(i, 0, n)
        {
            ll a;
            cin >> a;
            e.pb({a, i});
        }
        if (o[0].fi < e[0].fi)
        {
            cout << 0 << endl;
        }
        else
        {

            ll index1 = 0, index2 = 0;
            rep(i, 0, n)
            {
                if (o[i].fi < e[0].fi)
                {
                    index1 = i;
                    break;
                }
            }
            rep(i, 0, n)
            {
                if (e[i].fi > o[0].fi)
                {
                    index2 = i;
                    break;
                }
            }
            ll ans = min(index1, index2);
            sort(all(o));
            sort(all(e));

            rep(i, 0, n)
            {
                ans = min(ans, o[i].se + e[i].se);
            }
            cout << ans << endl;
        }
    }
}