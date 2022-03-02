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
#define mod 1000000007


int main()
{
    FAST;
    // your code goes here
    ll n,m,k;
    cin>>n>>m>>k;
    vl ans;
    if(n==2 && m==2 && k==1){
        cout<<4<<endl;
        cout<<"1 2 3 4";

    }
    
    else if(n>1){
        vl v;
        rep(i,0,k){
            v.pb(1);
        }
        v.pb(n);
        rep(i,0,k-1){
            v.pb(n+1);
        }
        if(n-m==k && k==1){
            v.pb(n+1);
        }
        else if(n==m && k==1){
            v.pb(n+m-1);
        }
        else if(n==m){
            v.pb(n+2);
        }
        cout<<sz(v)<<endl;
        rep(i,0,sz(v))
        cout<<v[i]<<" ";
    }
    else{
        cout<<0;
    }
    return 0;
}