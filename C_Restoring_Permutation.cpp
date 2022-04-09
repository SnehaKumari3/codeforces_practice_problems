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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl v(2 * n + 1, 0);
        vpll v1;
        rep(i, 0, n)
        {
            ll a;
            cin >> a;
            v[a] = 1;
            v1.pb({i, a});
        }

        if (v[1] == 0 || v[2 * n] == 1)
        {
            cout << -1;
        }
        else
        {
            vl ans[2 * n + 1];
            vl res;
            ll i = 0, j = 1;
            while (i < n)
            {
                j=v1[i].se+1;
                while (v[j] != 0 && j <= 2 * n)
                {
                    j++;
                }
                if (j <= 2 * n)
                {
                    ans[v1[i].fi].pb(v1[i].se);
                    ans[v1[i].fi].pb(j);
                    v[j]=1;
                }
                i++;
            }
            rep(i, 0, 2 * n + 1)
            {
                rep(j, 0, sz(ans[i]))
                    res.pb(ans[i][j]);
            }
            if(res.size()==2*n){
                rep(i,0,sz(res)){
                    cout<<res[i]<<" ";
                }
            }
            else{
                cout<<-1;
            }
        }
        cout << endl;
    }
}