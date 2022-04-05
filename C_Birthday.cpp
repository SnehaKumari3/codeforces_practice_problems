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
#define mod 998244353

int main()
{
    FAST;
    // your code goes here
    ll n;
    cin >> n;
    mll m;
    rep(i, 0, n)
    {
        ll a;
        cin >> a;
        m[a]++;
    }
    vpll v;
    for (auto i : m)
    {
        v.pb({i.fi, i.se});
    }
    list<ll> l;
    ll k = sz(v) - 1;
    for (ll i = sz(v) - 1; i >= 0; i--)
    {
        ll t = v[i].se;
        if (t > 1)
        {
            ll cnt = 0;
            while (t--)
            {
                if (cnt % 2)
                {
                    l.push_front(v[i].fi);
                }
                else
                {
                    l.push_back(v[i].fi);
                }
                cnt++;
            }
        }
        else
        {
            ll d1=l.front();
            ll d2=l.back();
            d1=abs(v[i].fi-d1);
            d2=abs(v[i].fi-d2);
            if(d1>d2){
                l.push_front(v[i].fi);   
            }
            else{
                l.push_back(v[i].fi);
            }

        }
    }
    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";

    cout << endl;
    return 0;
}