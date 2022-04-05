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
#define mod 998244353

int main()
{
    FAST;
    // your code goes here
    ll n,k,x;
    cin>>n>>k>>x;
    vl v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    sort(all(v));
    vl ans;
    rep(i,1,n){
        ll d=v[i]-v[i-1];
        if(d>x){
            ans.pb(d);
        }
    }
    sort(all(ans));
    ll i=0;
    while(k && i<ans.size()){
        ll d=ans[i]/x;
        ll r=ans[i]%x;
        if(r==0){
            k-=d-1;
        }
        else{
            k-=d;
        }
        if(k<0){
            break;
        }
        i++;
    }
    cout<<ans.size()-i+1;
    return 0;
}