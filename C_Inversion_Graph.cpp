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
    vl t;
    t=v;
    sort(all(t));
    rep(i, 0, sz(v))
    {
        if (v[i]!=t[i])
        {
            return false;
        }
    }
    return true;
}

bool isReverse(vl v)
{
    vl t;
    t=v;
    sort(all(t));
    reverse(all(t));
    rep(i, 0, sz(v))
    {
        if (v[i]!=t[i])
        {
            return false;
        }
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
        vvl adj;
        ll n;
        cin >> n;
        vl a(n);
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        if(isSorted(a)){
            cout << n;
        }
        else if (isReverse(a))
        {
            cout << 1;
        }
        else
        {
            ll i = 0;
            ll mx = a[0];
            while (i < n)
            {
                vl t;
                t.pb(a[i]);
                i++;
                while (i < n && a[i] <= mx)
                {
                    t.pb(a[i]);
                    i++;
                }
                if (i < n)
                    mx = max(mx, a[i]);
                adj.pb(t);
            }
            // rep(i,0,sz(adj)){
            //     rep(j,0,adj[i].size()){
            //         cout<<adj[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            vl ans;
            ans.pb(*max_element(all(adj[0])));

            ll cnt = 1;
            rep(i, 1, sz(adj))
            {
                ll t = *min_element(all(adj[i]));
                ll mx = *max_element(all(ans));
                ans.pb(*max_element(all(adj[i])));
                if (t < mx)
                {
                    continue;
                }
                else
                {
                    cnt++;
                }
            }
            vl ans1;
            ans1.pb(*min_element(all(adj[adj.size() - 1])));
            ll cnt1 = 1;
            repr(i, sz(adj) - 2, -1)
            {
                ll t = *max_element(all(adj[i]));
                ll mn = *min_element(all(ans1));
                ans1.pb(*min_element(all(adj[i])));
                // cout<<t<<" "<<mn<<endl;
                if (t > mn)
                {
                    continue;
                }
                else
                {
                    cnt1++;
                }
            }
            cout << min(cnt, cnt1);
        }
        cout << endl;
    }
    return 0;
}