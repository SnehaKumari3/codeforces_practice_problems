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
    ll n, m;
    cin >> n >> m;
    vl v1(n + 1, 0);
    ll mn=1,mx=n;
    while (m--)
    {
        vector<string> s(5);
        rep(i, 0, 5)
        {
            cin >> s[i];
        }
        ll t = stoi(s[4]);
        v1[t]=-1;
        if (s[2] == "right")
        {
            mn = max(mn, t);
        }
        else
        {
            mx = min(mx, t);
        }
    }
    ll cnt = 0;
    rep(i, mn, mx + 1)
    {
        if (v1[i] == 0)
        {
            cnt++;
        }
    }

    if (cnt > 0)
    {

        cout << cnt;
    }
    else
    {
        cout << -1;
    }
    return 0;
}