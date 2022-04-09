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

int main()
{
    FAST;
    // your code goes here
    ll k;
    cin >> k;
    ll k1 = k;
    string s;
    cin >> s;
    vl index(26, 0);
    vl ans;
    rep(i, 0, s.length())
    {
        if (index[s[i] - 'a'] == 0)
        {
            ans.pb(i);
            index[s[i] - 'a'] = 1;
        }
    }
    if (sz(ans) >= k)
    {
        cout << "YES" << endl;
        ll i = 1;
        while (k > 0)
        {
            if (k == 1)
            {
                rep(j, ans[i - 1], s.length())
                {
                    cout << s[j];
                }
            }
            else
            {
                rep(j, ans[i - 1], ans[i])
                {
                    cout << s[j];
                }
            }
            cout << endl;
            i++;
            k--;
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}