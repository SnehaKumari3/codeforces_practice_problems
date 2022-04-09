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

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n;
        cin >> n;
        ll k = n;
        ll candy = 0, snow = 0, cnt = 0;
        rep(i, 0, s.length())
        {
            if (s[i + 1] == '*' && i + 1 < s.length())
            {
                snow++;
                i++;
            }
            else if (s[i + 1] == '?' && i + 1 < s.length())
            {
                candy++;
                i++;
            }
            else
            {
                cnt++;
            }
        }
        string ans = "";
        if (cnt > n)
        {
            cout << "Impossible";
        }
        else if (cnt == n)
        {
            rep(i, 0, s.length())
            {
                if (s[i + 1] == '*' && i + 1 < s.length())
                {
                    i++;
                }
                else if (s[i + 1] == '?' && i + 1 < s.length())
                {
                    i++;
                }
                else
                {
                    ans += s[i];
                }
            }
            cout << ans;
        }
        else
        {
            n -= cnt;
            if (snow > 0)
            {
                rep(i, 0, s.length())
                {
                    if (s[i + 1] == '*' && i + 1 < s.length())
                    {
                        while (n > 0)
                        {
                            ans += s[i];
                            n--;
                        }
                        i++;
                    }
                    else if (s[i + 1] == '?' && i + 1 < s.length())
                    {
                        i++;
                    }
                    else
                    {
                        ans += s[i];
                    }
                }
            }
            else
            {
                rep(i, 0, s.length())
                {
                    if (s[i + 1] == '?' && i + 1 < s.length())
                    {
                        if (n > 0)
                        {
                            ans += s[i];
                            n--;
                        }
                        i++;
                    }
                    else
                    {
                        ans += s[i];
                    }
                }
            }
            if (ans.length() == k)
            {
                cout << ans;
            }
            else
            {
                cout << "Impossible";
            }
        }
    }

    return 0;
}