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
// ll fact(ll n)
// {
//     if (n < 2)
//         return 1;
//     return n * fact(n - 1);
// }

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    // cin >> t;
    while (t--)
    {

        ll n, m, k;
        cin >> n >> m >> k;
        char a[n][m];
        rep(i, 0, n)
        {
            rep(j, 0, m)
            {
                cin >> a[i][j];
            }
        }

        if (n == 1)
        {
            ll ans = 0, l = 0, t = 0;
            rep(i, 0, n)
            {
                l = 0;
                rep(j, 0, m)
                {
                    if (a[i][j] == '.')
                    {
                        l++;
                    }
                    else
                    {
                        if (l >= k)
                        {
                            t = l - k + 1;
                            ans += t;
                        }
                        l = 0;
                    }
                }
                if (l >= k)
                {
                    t = l - k + 1;
                    ans += t;
                }
            }
            cout << ans;
        }
        else if (m == 1)
        {
            ll ans = 0, l = 0, t = 0;
            rep(j, 0, m)
            {
                ll l = 0;
                rep(i, 0, n)
                {
                    if (a[i][j] == '.')
                    {
                        l++;
                    }
                    else
                    {
                        if (l >= k)
                        {
                            t = l - k + 1;
                            ans += t;
                        }
                        l = 0;
                    }
                }
                if (l >= k)
                {
                    t = l - k + 1;
                    ans += t;
                }
            }
            cout << ans;
        }
        else
        {
            ll cnt = 0;
            ll ans = 0, l = 0, t = 0;
            rep(i, 0, n)
            {
                l = 0;
                rep(j, 0, m)
                {
                    if (a[i][j] == '.')
                    {
                        l++;
                        cnt++;
                    }
                    else
                    {
                        if (l >= k)
                        {
                            t = l - k + 1;
                            ans += t;
                        }
                        l = 0;
                    }
                }
                if (l >= k)
                {
                    t = l - k + 1;
                    ans += t;
                }
            }

            rep(j, 0, m)
            {
                ll l = 0;
                rep(i, 0, n)
                {
                    if (a[i][j] == '.')
                    {
                        l++;
                    }
                    else
                    {
                        if (l >= k)
                        {
                            t = l - k + 1;
                            ans += t;
                        }
                        l = 0;
                    }
                }
                if (l >= k)
                {
                    t = l - k + 1;
                    ans += t;
                }
            }
            if (k == 1)
            {
                cout << cnt;
            }
            else
                cout << ans;
        }
        cout << endl;
    }

    return 0;
}