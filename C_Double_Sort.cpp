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
#define INF 10007

bool isSorted(vl v)
{
    rep(i, 1, sz(v))
    {
        if (v[i] < v[i - 1])
            return false;
    }
    return true;
}

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
        vl a(n), b(n), a1(n), b1(n);
        rep(i, 0, n)
        {
            cin >> a[i];
            a1[i] = a[i];
        }
        rep(i, 0, n)
        {
            cin >> b[i];
            b1[i] = b[i];
        }
        sort(all(a1));
        sort(all(b1));
        if (isSorted(a) && isSorted(b))
        {

            cout << 0 << endl;
        }
        else
        {
            set<pair<ll, ll>> s;
            bool ok=true;
            rep(i, 0, n)
            {
                if (a[i] == a1[i] && b[i] == b1[i])
                {
                    continue;
                }
                else
                {
                    ll index = i;
                    rep(j, i + 1, n)
                    {
                        if (a[j] == a1[i] && b[j] == b1[i])
                        {
                            index = j;
                            break;
                        }
                    }
                    if (index < n)
                    {
                        ll t = a[index];
                        a[index] = a[i];
                        a[i] = t;
                        s.insert({i, index});
                        t = b[index];
                        b[index] = b[i];
                        b[i] = t;
                    }
                    else{
                        ok=false;
                        break;
                    }
                }
            }

            if (isSorted(a) && isSorted(b) && ok)
            {
                cout << s.size() << endl;
                for (auto i : s)
                {
                    cout << i.fi + 1 << " " << i.se + 1 << endl;
                }
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}