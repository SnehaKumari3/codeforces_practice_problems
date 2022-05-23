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

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[n][m];
        vvl v;
        rep(i, 0, n)
        {
            vl t;
            rep(j, 0, m)
            {
                cin >> a[i][j];
                t.pb(a[i][j]);
            }
            sort(all(t));
            v.pb(t);
        }
        ll row = 0, index = -1;
        bool ok = true;
        while (row < n && ok)
        {
            rep(i, 0, m)
            {
                if (a[row][i] != v[row][i])
                {
                    ok = false;
                    index = i;
                    break;
                }
            }
            if (ok)
                row++;
        }
        if (row == n && ok)
        {
            cout << 1 << " " << 1;
        }
        else
        {
            ll index1 = -1;
            repr(i, m - 1, -1)
            {
                if (a[row][i] != v[row][i])
                {
                    index1 = i;
                    break;
                }
            }
            rep(i, 0, n)
            {
                ll tmp = a[i][index];
                a[i][index]= a[i][index1];
                a[i][index1] = tmp;
            }
            row = 0;
            ok = true;
            while (row < n && ok)
            {
                rep(i, 0, m)
                {
                    if (a[row][i] != v[row][i])
                    {
                        ok = false;
                        break;
                    }
                }
                    row++;
            }
            if(ok){
                cout<<index+1<<" "<<index1+1;
            }
            else{
                cout<<-1;
            }

        }
        cout<<endl;
        // rep(i, 0, n)
        // {
        //     rep(j, 0, m)
        //     {
        //         cout<< a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }
    return 0;
}