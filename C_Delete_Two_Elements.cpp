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

int binary_search(vl v, ll l, ll r, ll key)
{
    if (r >= l)
    {
        ll mid = l + (r - l) / 2;
        if (v[mid] == key)
        {
            return mid;
        }
        if (v[mid] > key)
        {
            return binary_search(v, 0, mid - 1, key);
        }

        return binary_search(v, mid + 1, r, key);
    }
    return -1;
}

int main()
{
    FAST;
    // your code goes here
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl v(n);
        mll m;
        ll s = 0;
        rep(i, 0, n)
        {
            cin >> v[i];
            m[v[i]]++;
            s += v[i];
        }
        sort(all(v));

        ll ans = 0;
        ll l = 0, r = n - 1;
        while (l < r)
        {
            ll cnt = 0;

            ll key = (2 * s) / n - v[l];
            while (v[r] == key && l < r)
            {
                cnt++;
                r--;
            }
            ll k = l + 1;
            while (v[k] == v[l] && l < n && l < r)
            {
                k++;
                cnt++;
                l = k;
            }
            l++;
            ans += cnt;
        }
        ans = (ans * (ans - 1)) / 2;
        cout << ans << endl;
    }

    return 0;
}