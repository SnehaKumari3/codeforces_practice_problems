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
        ll n;
        cin >> n;
        vl v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        vl a(n,0),b(n,0);
        a[0]=v[0];
        rep(i,1,n){
            a[i]=v[i]+a[i-1];
        }
        b[n-1]=v[n-1];
        repr(i,n-2,-1){
            b[i]=v[i]+b[i+1];
        }
        ll ans=0,i=0,j=n-1;
        while(i<=j){
            while(a[i]!=b[j] && i<n && j>=0 && i<=j){
                i++,j--;
            }
            if(a[i]==b[j]){
                ans+=(i+1+n-j);
                i++,j--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}