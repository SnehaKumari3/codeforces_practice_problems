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
    cin >> t;
    while (t--)
    {
        int64_t n;
        cin >> n;
        n = 2 * n;
        vector<int64_t> b(n),tmp;
        int64_t d = 0, even = 0, odd = 0;
        rep(i, 0, n)
        {
            cin >> b[i];
            if (b[i] % 2 == 1)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        if (odd == even)
        {
            cout << 0;
        }
        else if (odd > even)
        {
            d = (odd - even) / 2;
            cout << d;
        }
        else
        {
            sort(all(b));
            d = (even - odd) / 2;
            int64_t cnt = 0,ans=0;

            rep(i, 0, n)
            {
                cnt=0;
                if (b[i] % 2 == 0)
                {
                    while (b[i] % 2 == 0)
                    {
                        cnt++;
                        b[i] /= 2;
                    }
                    tmp.pb(cnt);
                }
                
            }
            sort(all(tmp));
            rep(i, 0, sz(tmp))
            {
                d--;
                ans+=tmp[i];
                if (d == 0)
                {
                    break;
                }
            }
            cout << ans;
        }

        cout << endl;
    }
}