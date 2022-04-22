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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, r, b;
        cin >> n >> r >> b;
        string s = "";
        ll cnt = r / (b+1);
        ll tmp=r-(cnt*(b+1));
        ll cnt1;
        if(tmp>0){
            cnt1=cnt+1;
        }
        while (r > 0 && b > 0)
        {
            ll t = cnt;
            if(tmp>0){
                t=cnt1;
                tmp--;
            }
            while (t > 0 && r > 0)
            {
                s += 'R';
                t--;
                r--;
            }
            if (b > 0)
            {
                s += 'B';
                b--;
            }
        }
        while (r > 0)
        {
            s += 'R';
            r--;
        }
        cout << s << endl;
    }
    return 0;
}