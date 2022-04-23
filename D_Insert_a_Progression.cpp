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
        ll n, x;
        cin >> n >> x;
        vl v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        rep(i, 1, x+1)
        {
            ll c = count(all(v), i);
            if (c > 0)
            {
                continue;
            }
            else
            {
                vector<ll>::iterator l, u;
                l = lower_bound(v.begin(), v.end(), i);
                u = upper_bound(v.begin(), v.end(), i);
                
                ll d1 = abs(v[l - v.begin()] - i);
                ll d2 = abs(v[u - v.begin()] - i);
                if (d1 <= d2)
                {
                    v.insert(l, i);
                }
                else
                {
                    v.insert(u, i);
                }
            }
        }
        ll ans = 0;
        
        rep(i, 1, v.size())
        {
            ans += abs(v[i] - v[i - 1]);
        }

        cout << ans;
        cout << endl;
    }
    return 0;
}