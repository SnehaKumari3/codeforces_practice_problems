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

ll fun(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

int main()
{
    FAST;
    // your code goes here

    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        if (n == 1)
        {
            cout << fun(k);
        }
        else if (k <= n)
        {
            cout << k;
        }
        else
        {

            ll tmp = 2,prev=1;
            ans += n;
            k -= n;
            while (k > 0)
            {
                prev=2*prev;
                if (k >= n * tmp)
                {
                    ans += n;
                    k -= n*tmp;
                }
                else
                {
                    ll t1 = k / tmp;
                    ans += t1;
                    if(k%tmp>0){
                        ans-=fun(prev-1);
                        ans+=fun(prev-1+k%tmp);
                    }
                    k = 0;
                }
                tmp *= 2;
            }
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}