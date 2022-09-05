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

    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl v(n);
        rep(i, 0, n) cin >> v[i];
        bool flag = true;
        rep(i, 0, n)
        {
            if (v[i] % 10 == 0)
            {
                flag = false;
                continue;
            }
            else if (v[i] % 10 == 5)
            {
                flag = false;
                v[i] += 5;
            }
            else
            {
                while (v[i] % 10 != 2)
                {
                    v[i] += v[i] % 10;
                }
            }
            
        }

        sort(all(v));
        bool ok = true;

        if (flag)
        {
            rep(i, 1, n)
            {
                if ((v[i] - v[i - 1]) % 20 != 0)
                {
                    ok = false;
                    break;
                }
            }
        }
        else
        {
            rep(i,1,n){
                if(v[i]!=v[0]) ok=false;
            }
        }

        if (ok)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }

    return 0;
}