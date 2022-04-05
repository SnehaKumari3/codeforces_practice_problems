#include <bits/stdc++.h>
#include<algorithm>
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

ll solve(vl v,ll l,ll r){
    ll ans=0;
    for(int i=0;i<l;i++){
        if(v[i]==1){
            ans++;
        }
    }
    for(int i=l;i<=r;i++){
        if(v[i]==0){
            ans++;
        }
    }
    for(int i=r+1;i<sz(v);i++){
        if(v[i]==1){
            ans++;
        }
    }
    return ans;
}
int main()
{
    FAST;
    // your code goes here
    ll n;
    cin>>n;
    vl v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    vpll ans;
    ll z=0,o=0;
    ll res=0;
    rep(i,0,n){
        if(v[i]==0){
            z++;
        }
        else{
            o++;
        }
        ans.pb({z,o});
    }
    
    rep(i,0,sz(ans)){
        rep(j,i,sz(ans)){
            res=max(res,solve(v,i,j));
        }
    }
    cout<<res;
    return 0;
}