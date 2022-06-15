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

int v[1000005];
int a[10][1000005];

int main()
{
    FAST;
    // your code goes here

    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n, b, a, s;
        cin >> n >> a >> b;
        string s1;
        cin >> s1;
        ll ans = 0;
        ll i = 0;
        while (i < n)
        {
            if (s1[i] == '.' )
            {
                s = 0;
                while (i < n && s1[i] == '.')
                {
                    i++;
                    s++;
                }
                
                ll mn = s / 2;
                ll mx = s - mn;
                if (a > b)
                {
                    ll tmp = min(mx, a);
                    ans += tmp;
                    a -= tmp;
                    tmp = min(mn, b);
                    ans += tmp;
                    b -= tmp;
                }
                else
                {
                    ll tmp = min(mx, b);
                    ans += tmp;
                    b -= tmp;
                    tmp = min(mn, a);
                    ans += tmp;
                    a -= tmp;
                }
            }
            else
            {
                s=0;
                i++;
            }
        }
        

        cout << ans;
    }
    return 0;
}