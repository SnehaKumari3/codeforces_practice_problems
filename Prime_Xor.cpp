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
vl ans;
ll a, b, c;
void solve1(ll x, ll y)
{
    a = 2;
    b = 2 ^ x;
    c = b ^ y;
    ans.pb(a), ans.pb(b), ans.pb(c);
    ll cnt = 0;
    rep(i, 0, 3)
    {
        if (ans[i] % 2 == 0)
        {
            cnt++;
        }
    }

    if (cnt != 1)
    {
        ans.clear();
    }
}
void solve2(ll x, ll y)
{
    b = 2;
    a = b ^ x;
    c = b ^ y;
    ans.pb(a), ans.pb(b), ans.pb(c);
    ll cnt = 0;
    rep(i, 0, 3)
    {
        if (ans[i] % 2 == 0)
        {
            cnt++;
        }
    }

    if (cnt != 1)
    {
        ans.clear();
    }
}
void solve3(ll x, ll y)
{
    c = 2;
    b = c ^ y;
    a = x ^ b;
    ans.pb(a), ans.pb(b), ans.pb(c);
    ll cnt = 0;
    rep(i, 0, 3)
    {
        if (ans[i] % 2 == 0)
        {
            cnt++;
        }
    }

    if (cnt != 1)
    {
        ans.clear();
    }
}

int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        a = 0, b = 0, c = 0;
        ll x, y;
        cin >> x >> y;
        ans.clear();
        solve1(x, y);
        if (ans.size() == 3)
        {
            sort(all(ans));
            rep(i, 0, 3)
            {
                cout << ans[i] << " ";
            }
        }
        else
        {
            ans.clear();
            solve2(x, y);
            if (ans.size() == 3)
            {
                sort(all(ans));
                rep(i, 0, 3)
                {
                    cout << ans[i] << " ";
                }
            }
            else
            {
                ans.clear();
                solve3(x, y);
                sort(all(ans));
                rep(i, 0, 3)
                {
                    cout << ans[i] << " ";
                }
            }
        }
        cout<<endl;
    }
}