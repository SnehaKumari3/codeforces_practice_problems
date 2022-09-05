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
    cin >> t;
    while (t--)
    {
        ll n, ans;
        cin >> n;
        vl v(n, 0);
        mll m;
        rep(i, 0, n)
        {
            cin >> v[i];
            m[v[i]]++;
        }

        int64_t alone = 0, tmp=0, tmp2 = 0;
        for (auto i : m)
        {
            if (i.se == 1)
            {
                alone++;
                tmp = i.fi;
            }
        }

        if (alone == 1)
        {
            ll mx = *max_element(all(v));
            if (mx == tmp)
            {
                for (auto i : m)
                {
                    if (i.se > 1 && i.fi<tmp)
                    {
                        tmp2=max(tmp2,i.se);
                    }
                    
                }
                if(tmp2 > 2){
                    ans=1;
                }
                else{
                    ans = 2;
                }
                
            }
            else
            {
                ans = (alone + 1) / 2;
            }
        }
        else
        {
            ans = (alone + 1) / 2;
        }
        cout << ans;
        cout << endl;
    }
}