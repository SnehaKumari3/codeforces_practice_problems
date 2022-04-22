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

bool issort(vl v)
{
    rep(i, 1, sz(v))
    {
        if (v[i] < v[i - 1])
        {
            return false;
        }
    }
    return true;
}

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
        vl v(n + 1, 0);
        rep(i, 1, n + 1)
        {
            cin >> v[i];
        }
        bool ok = true;
        ll t = count(all(v), 1);
        if (t > 1)
        {
            ok = false;
        }
        t = count(all(v), n);
        if (t == 0)
        {
            ok = false;
        }
        if (!issort(v))
        {
            cout << -1;
        }
        else if (ok)
        {
            vl ans(n + 1, 0), av(n + 1, 0);
            ans[1] = v[1];
            ll key = ans[1];
            av[ans[1]] = -1;
            rep(i, 2, n + 1)
            {
                if (v[i] > key)
                {
                    ans[i] = v[i];
                    key = ans[i];
                    av[ans[i]] = -1;
                }
            }
            ll k = 1;
            key = 1;
            ok = true;
            rep(i, 1, n + 1)
            {
                if (ans[i] == 0)
                {
                    while (av[k] == -1 && k < n)
                    {
                        k++;
                    }
                    ans[i] = k;
                    k++;
                }
                if (ans[i] > key)
                {
                    key = ans[i];
                }
                if (v[i] != key)
                {
                    ok = false;
                }
            }
            if (ok)
            {
                rep(i, 1, n + 1)
                {
                    cout << ans[i] << " ";
                }
            }
            else
            {
                cout << -1;
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}