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
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        ll ans = 0;
        if (v[0] % 2 == 0 && v[n - 1] % 2 == 0)
        {
            ll i = 0, j;
            while (i < n)
            {
                j = i + 1;
                while (j < n && v[j] % 2 != 0)
                {
                    j++;
                }
                i = j;
                ans++;
                if (i == (n - 1))
                {
                    break;
                }
            }
        }
        else if (v[0] % 2 == 1 && v[n - 1] % 2 == 1)
        {
            ll i = 0, j;
            while (i < n)
            {
                j = i + 1;
                while (j < n && v[j] % 2 != 1)
                {
                    j++;
                }
                i = j;
                ans++;
                if (i == (n - 1))
                {
                    break;
                }
            }
        }
        else
        {
            vl res(n, INF);
            queue<ll> q;
            ll i, j, k;
            q.push(0);
            res[0]=0;
            while (!q.empty())
            {
                i = q.front();
                q.pop();
                j = i + 1;
                while (j < n && v[j] % 2 != 1)
                {
                    j++;
                }
                k = i + 1;
                while (k < n && v[k] % 2 != 0)
                {
                    k++;
                }
                ll t = res[i] + 1;

                if (res[j] > t && j < n)
                {
                    res[j] = t;
                    q.push(j);
                }
                if (res[k] > t && k < n)
                {
                    res[k] = t;
                    q.push(k);
                }
            }

            ans = res[n - 1];
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}