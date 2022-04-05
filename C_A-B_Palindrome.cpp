#include <bits/stdc++.h>
#include <algorithm>
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

bool palid(string s)
{
    ll i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j] && s[i] != '?')
        {
            return false;
        }
        i++, j--;
    }
    return true;
}
bool cnt(string s, ll a, ll b)
{
    rep(i, 0, sz(s))
    {
        if (s[i] == '0')
            a--;
        else
            b--;
    }
    if (a == 0 && b == 0)
        return true;
    return false;
}

int main()
{
    FAST;
    // your code goes here
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll z = a, o = b;
        string s;
        cin >> s;
        ll n = s.length();
        rep(i, 0, n)
        {
            if (s[i] != s[n - 1 - i])
            {
                if (s[i] == '?' && s[n - 1 - i] == '1')
                {
                    s[i] = '1';
                }
                else if (s[i] == '?' && s[n - 1 - i] == '0')
                {
                    s[i] = '0';
                }
                else if (s[i] == '0' && s[n - 1 - i] == '?')
                {
                    s[n - 1 - i] = '0';
                }
                else if (s[i] == '1' && s[n - 1 - i] == '?')
                {
                    s[n - 1 - i] = '1';
                }
            }
        }

        rep(i, 0, sz(s))
        {
            if (s[i] == '0')
                z--;
            if (s[i] == '1')
                o--;
        }

        rep(i, 0, n)
        {
            if (s[i] == '?')
            {
                if (z >= o && z >= 1)
                {
                    s[i] = s[n - 1 - i] = '0';
                    z -= 2;
                }
                else if (o >= z && o >= 1)
                {
                    s[i] = s[n - 1 - i] = '1';
                    o -= 2;
                }
            }
        }

        if (palid(s) && cnt(s, a, b))
        {
            cout << s << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}