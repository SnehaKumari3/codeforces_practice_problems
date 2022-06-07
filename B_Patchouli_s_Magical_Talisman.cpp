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
#define pp pop_back
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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        int64_t n, s = 0;
        cin >> n;
        ll o = 0, e = 0;
        vector<int64_t> v;
        rep(i, 0, n)
        {
            int64_t a;
            cin >> a;
            v.pb(a);
            s += a;
            if (a % 2 == 1)
            {
                o++;
            }
            else
            {
                e++;
            }
        }
        if (e == 0)
        {
            cout << 0;
        }
        else if (o == 0)
        {

            int64_t ans1 = n - 1;
            while (s % 2 == 0)
            {
                s /= 2;
                ans1++;
            }
            int64_t ans2 = -1;
            rep(i, 0, sz(v))
            {
                if (v[i] % 2 == 0)
                {
                    int64_t t = 0;
                    while (v[i] % 2 == 0)
                    {
                        v[i] /= 2;
                        t++;
                    }
                    if (ans2 == -1)
                    {
                        ans2 = t;
                    }
                    else
                    {
                        ans2 = min(ans2, t);
                    }
                }
            }

            if (ans2 != -1)
            {

                e -= 1;
                if (e > 0)
                {
                    ans2 += e;
                }
                ans1 = min(ans2, ans1);
            }
            cout << ans1;
        }
        else
        {
            cout << e;
        }
        cout << endl;
    }

    return 0;
}