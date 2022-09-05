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
        ll n, m;
        cin >> n >> m;
        int a[] = {1, 0, 0, 1};
        int b[] = {0, 1, 1, 0};
        vvl ans;
        rep(i, 0, n)
        {
            vl t;
            if (ans.size() == 0)
            {
                rep(j, 0, m)
                {
                    t.pb(a[j % 4]);
                }
                ans.pb(t);
            }
            else if (ans.size() == 1)
            {
                rep(j, 0, m)
                {
                    t.pb(b[j % 4]);
                }
                ans.pb(t);
            }
            else
            {
                ll sz = ans.size() - 1;
                bool ok = true;
                rep(j, 0, m)
                {
                    if (ans[sz][j] != ans[sz - 1][j])
                    {
                        ok = false;
                    }
                }

                if (ok)
                {
                    rep(j, 0, m)
                    {
                        if(ans[sz][j]==1)
                        t.pb(0);
                        else
                        t.pb(1);
                    }
                    ans.pb(t);
                }
                else
                {
                    rep(j, 0, m)
                    {
                        t.pb(ans[sz][j]);
                    }
                    ans.pb(t);
                }
            }
        }

        rep(i,0,n){
            rep(j,0,m){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}