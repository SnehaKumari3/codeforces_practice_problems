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

bool LCS_Topdown_dp(string s, string t, ll n, ll m)
{
    string lcs = "";
    int dp[n + 1][m + 1];
    rep(i, 0, n + 1)
    {
        rep(j, 0, m + 1)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }

    rep(i, 1, n + 1)
    {
        rep(j, 1, m + 1)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    ll i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            lcs.pb(t[j - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(all(lcs));
    if (lcs == t)
    {
        return false;
    }
    return true;
}

int main()
{
    FAST;
    // your code goes here
    ll t;
    t = 1;
    while (t--)
    {
        ll n;
        cin >> n;
        ll v[7][2] = {0};
        ll s1 = 0, s2 = 0;
        rep(i, 0, n)
        {
            ll a, b;
            cin >> a >> b;
            if (a % 2 == 1 && b % 2 == 1)
            {
                v[a][0] += 0;
                v[b][1] += 0;
            }
            else
            {
                v[a][0] += 1;
                v[b][1] += 1;
            }
            s1 += a;
            s2 += b;
        }

        if (s1 % 2 == 0 && s2 % 2 == 0)
        {
            cout << 0;
        }
        else 
        {
            ll cnt1 = 0, cnt2 = 0;
            if (v[1][0] % 2 == 1)
            {
                cnt1++;
            }
            if (v[1][1] % 2 == 1)
            {
                cnt2++;
            }
            if (v[3][0] % 2 == 1)
            {
                cnt1++;
            }
            if (v[3][1] % 2 == 1)
            {
                cnt2++;
            }
            if (v[5][0] % 2 == 1)
            {
                cnt1++;
            }
            if (v[5][1] % 2 == 1)
            {
                cnt2++;
            }

            if(cnt1%2==1 && cnt2%2==1){
                cout<<1;
            }
            else{
                cout<<-1;
            }
        }
    }
    return 0;
}