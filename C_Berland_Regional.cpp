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
        vl c(n), s(n);
        rep(i, 0, n)
        {
            cin >> c[i];
        }
        rep(i, 0, n)
        {
            cin >> s[i];
        }
        vl v[n + 1];
        rep(i, 0, n)
        {
            v[c[i]].pb(s[i]);
        }
        rep(i, 0, n + 1)
        {
            sort(all(v[i]));
            rep(j, 1, sz(v[i]))
            {
                v[i][j] = v[i][j] + v[i][j - 1];
            }
        }
        ll res=
        rep(k, 1, n + 1)
        {
            ll ans = 0;
            rep(i, 1, n + 1)
            {
                if (v[i].size() >= k)
                {
                    ll r = (v[i].size()) % k;
                    if (r > 0)
                    {
                        ans += v[i][sz(v[i]) - 1] - v[i][r-1];
                    }
                    else{
                        ans += v[i][sz(v[i]) - 1];
                    }
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}