#include <bits/stdc++.h>
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

ll find(ll n)
{
    ll cnt = 0;
    while (n % 2 == 0)
    {
        cnt++;
        n /= 2;
        if (cnt >= 15)
        {
            return 15;
        }
    }
    return cnt;
}

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vl v(n);
        rep(i,0,n){
            cin>>v[i];
        }
        sort(all(v));
        vl res;
        rep(i,0,n-1){
            ll d=v[n-1]-v[i];
            if(d>0){
                res.pb(d);
            }
        }
        sort(all(res));
        ll e=0,o=0;
        rep(i,0,sz(res)){
            e+=res[i]/2;
            o+=res[i]%2;
        }
        cout<<e<<" "<<o<<endl;
    }

    return 0;
}