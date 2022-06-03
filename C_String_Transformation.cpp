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

bool issubsequence(string &s1, string &s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return i == n;
}
int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    // cin>>n;
    while (t--)
    {
        string s;
        cin >> s;
        string tmp = "abcdefghijklmnopqrstuvwxyz";
        if (s.length() < 26)
        {
            cout << -1;
        }

        else if (issubsequence(tmp,s))
        {
            cout << s;
        }

        else
        {
            string ans = "";
            bool ok = true;
            char ch = 'a', t;
            ll i = 0;
            while (i < sz(s))
            {
                if (s[i] == 'a')
                {
                    ans += s[i];
                    i++;
                    break;
                }
                ans += s[i];
                i++;
            }

            ch = 'b', t = ch - 1;

            while (i < sz(s))
            {
                if (s[i] == 'z')
                {
                    ans += s[i];
                }
                else if (s[i] == ch && ch <= 'z')
                {
                    ans += ch;
                    ch++;
                    t = ch - 1;
                }
                else if (s[i] <= t && t <= 'y')
                {
                    ans += ch;
                    ch++;
                    t = ch - 1;
                }
                else
                {
                    ans += s[i];
                }
                i++;
            }

            if (issubsequence(tmp,ans))
            {
                cout << ans;
            }
            else
            {
                cout << -1;
            }
        }
    }

    return 0;
}