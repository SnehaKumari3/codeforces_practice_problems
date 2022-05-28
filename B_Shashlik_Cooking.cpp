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
    // cin >> t;
    while (t--)
    {

        ll n,k;
        cin >> n>>k;
        vl ans;
        ll d=n/(2*k+1);
        ll r=n%(2*k+1);
        
        ll i=d;
        if(r>0){
            i++;
        }
        ll index=1;
        while(i--){
            ll t;
            if(r>0){
                if(r>k){
                    t=r-k+1;
                }
                else{
                    t=1;
                }
                index=t+(k)+1;
                r=0;
            }
            else{
                t=index+k;
                index+=2*(k)+1;
            }
            if(t<=n){
                ans.pb(t);
            }
            else{
                ans.pb(n);
            }
        }
        cout<<ans.size()<<endl;
        rep(i,0,sz(ans)){
            cout<<ans[i]<<" ";
        }
        
        cout<<endl;
    }

    return 0;
}