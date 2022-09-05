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
        ll n, ans = 0, ind1, ind2;
        cin >> n;
        vl v(n + 1, 0);
        rep(i, 1, n + 1)
        {
            cin >> v[i];
            if (v[i] == 1)
            {
                ind1 = i;
            }
            if (v[i] == n)
            {
                ind2 = i;
            }
        }
        if (ind1 != 1)
        {
            repr(i, ind1, 1)
            {
                ll tmp = v[i - 1];
                v[i - 1] = v[i];
                v[i] = tmp;
                ans++;
                if (v[i] == n)
                {
                    ind2 = i;
                }
            }
        }
        if (ind2 != n)
        {
            rep(i, ind2, n)
            {
                ll tmp = v[i + 1];
                v[i + 1] = v[i];
                v[i] = tmp;
                ans++;
            }
        }
        cout << ans;
        cout << endl;
    }
}