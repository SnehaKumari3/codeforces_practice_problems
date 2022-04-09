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
    FAST;
    // your code goes here
    ll n, k;
    cin >> n >> k;
    vpll v;
    rep(i, 0, n)
    {
        ll a;
        cin >> a;
        v.pb({a, i});
    }

    sort(all(v));
    reverse(all(v));
    ll ans = 0;
    vl res;
    rep(i, 0, k)
    {
        ans += v[i].fi;
        res.pb(v[i].se);
    }
    sort(all(res));
    cout << ans << endl;
    if (k == 1)
    {
        cout << n;
    }
    else
    {
        cout << res[0] + 1 << " ";
        k--;
        if (k > 0)
        {

            rep(i, 1, res.size() - 1)
            {
                cout << res[i] - res[i - 1] << " ";
                k--;
            }
        }
        if (k > 0)
            cout << n - 1 - res[res.size() - 2];
    }

    return 0;
}