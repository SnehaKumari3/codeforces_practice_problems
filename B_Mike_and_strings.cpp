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

ll shift(string a, string b)
{
    ll mx = a.length() - 1;
    rep(i, 0, mx + 1)
    {
        bool f = true;
        rep(j, 0, a.length())
        {
            if (a[j] != b[(j + i) % a.length()])
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    FAST;
    // your code goes here

    ll n;
    cin >> n;
    vector<string> t;
    map<string, ll> m;
    rep(i, 0, n)
    {
        string tmp;
        cin >> tmp;
        m[tmp]++;
        sort(all(tmp));
        t.pb(tmp);
    }
    bool ok = true;
    rep(i, 1, n)
    {
        if (t[i] != t[0])
        {
            ok = false;
            break;
        }
    }

    if (ok)
    {
        ll ans = -1;
        for (auto i : m)
        {
            ll res = 0;
            for (auto j : m)
            {
                if (i.fi != j.fi)
                {
                    ll t1 = shift(i.fi, j.fi);
                    if (t1 == -1)
                    {
                        ok = false;
                    }
                    else
                    {
                        res += t1 * j.se;
                    }
                }
            }
            if (ok)
            {
                if (ans == -1)
                {
                    ans = res;
                }
                else
                {
                    ans = min(ans, res);
                }
            }
            else{
                break;
            }
        }
        if(ok)
        cout << ans;
        else
        cout<<-1;
    }
    else
    {
        cout << -1;
    }

    return 0;
}