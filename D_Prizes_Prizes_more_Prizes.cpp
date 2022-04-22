#include <bits/stdc++.h>
#include "cmath"
#include <cmath>
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
int id(vpll p, ll s)
{
    repr(i, 4, -1)
    {
        if (s >= p[i].fi)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl v(n);
        rep(j, 0, n)
        {
            cin >> v[j];
        }
        vl ans(5, 0);
        vpll p;
        rep(i, 0, 5)
        {
            ll t;
            cin >> t;
            p.pb({t, 0});
        }
        sort(all(p));
        ll i = 0;
        ll s = 0;
        while (i < n)
        {
            s += v[i];
            if (s >= p[0].fi)
            {
                ll index = id(p, s);
                while (index != -1)
                {
                    p[index].se += s / p[index].fi;
                    s -= ((s / p[index].fi) * p[index].fi);
                    index = id(p, s);
                }
            }
            i++;
        }
        if (s >= p[0].fi)
        {
            ll index = id(p, s);
            while (index != -1)
            {
                p[index].se += s / p[index].fi;
                s -= ((s / p[index].fi) * p[index].fi);
                index = id(p, s);
            }
        }
        rep(i, 0, 5)
        {
            cout << p[i].se << " ";
        }
        cout << endl;
        cout << s;
    }
    return 0;
}