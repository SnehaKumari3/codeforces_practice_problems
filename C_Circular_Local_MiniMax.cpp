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

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    cin >> t;

    while (t--)
    {

        ll n;
        cin >> n;
        vl v(n);
        mll m;
        rep(i, 0, n)
        {
            cin >> v[i];
            m[v[i]]++;
        }
        if (n % 2 == 1)
        {
            cout << "NO";
        }
        else
        {
            sort(all(v));
            vl res;
            ll i = 0, j = n / 2;
            while (i < n/2 && j<n)
            {
                res.pb(v[i]);
                res.pb(v[j]);
                i ++, j ++;
            }

            bool ok = true;
            rep(i, 0, res.size())
            {
                ll pr = res[(i - 1 + n) % n];
                ll nt = res[(i + 1) % n];

                if (pr > res[i] && nt > res[i])
                {
                    continue;
                }
                else if (pr < res[i] && nt < res[i])
                {
                    continue;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                cout << "YES" << endl;
                rep(i, 0, sz(res))
                {
                    cout << res[i] << " ";
                }
            }
            else
            {
                cout << "NO";
            }
        }

        cout << endl;
    }

    return 0;
}