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
#define mem0(a) memset(a, 0, sizeof(a))
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
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vl a(n), b(m), c(n + m);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, m) cin >> b[i];
        ll i = 0, j = 0, k = 0;

        while (i < n && j < m)
        {
            if (a[i] <= b[j])
            {
                c[k] = a[i];
                k++, i++;
            }
            else
            {
                c[k] = b[j];
                k++, j++;
            }
        }
        while (i < n)
        {
            c[k] = a[i];
            k++, i++;
        }
        while (j < m)
        {
            c[k] = b[j];
            k++, j++;
        }
        rep(i,0,sz(c)){
            cout<<c[i]<<" ";
        }
    }
}