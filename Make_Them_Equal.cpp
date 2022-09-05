#include <bits/stdc++.h>

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
ll rem(ll a, ll b, ll c)
{
    return a % 2 + b % 2 + c % 2;
}

string fun(ll a, ll b, ll c)
{
    if (a == b && b == c)
        return "YES";
    if (a + b + c == 1)
        return "NO";
    if (rem(a, b, c) == 0 || rem(a, b, c) == 3)
        return "NO";

    if (a % 2 == b % 2)
        c++;
    else if (c % 2 == b % 2)
        a++;
    else if (c % 2 == a % 2)
        b++;
    a = a >> 1;
    b = b >> 1;
    c = c >> 1;
    return fun(a, b, c);
}
int main()
{
    FAST;
    // your code goes here
    ll t;
    cin >> t;
    while (t--)
    {
        vl v(3);
        rep(i, 0, 3)
        {
            cin >> v[i];
        }
        cout << fun(v[0], v[1], v[2]);
        cout << endl;
    }
    return 0;
}