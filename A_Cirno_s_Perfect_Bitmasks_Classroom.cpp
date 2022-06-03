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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << 3;
        }
        else
        {
            vl v;
            ll index = -1, cnt = 0;
            while (n > 0)
            {
                if (n % 2 == 1)
                {
                    cnt++;
                }
                v.pb(n % 2);
                n /= 2;
            }
            reverse(all(v));
            // rep(i,0,sz(v)){
            //     cout<<v[i];
            // }
            // cout<<endl;
            repr(i, sz(v) - 1, -1)
            {
                if (v[i] == 1)
                {
                    index = i;
                    break;
                }
            }
            if (cnt > 1)
            {
                rep(i, 0, sz(v))
                {
                    if (i != index)
                    {
                        v[i] = 0;
                    }
                }
            }
            else
            {
                bool ok = true;
                repr(i, sz(v) - 1, -1)
                {
                    if (v[i] == 0 && ok)
                    {
                        v[i] = 1;
                        ok = false;
                    }
                    else if (i != index)
                    {
                        v[i] = 0;
                    }
                }
            }
            // rep(i,0,sz(v)){
            //     cout<<v[i];
            // }
            // cout<<endl;
            int64_t ans = 0;
            ll j = 0;
            repr(i, sz(v) - 1, -1)
            {
                ans += pow(2, j) * v[i];
                j++;
            }
            cout << ans;
        }
        cout << endl;
    }

    return 0;
}