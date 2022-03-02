#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef set<ll> sl;
typedef vector<sl> vsl;
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

bool check(ll x,sl v){
    while(x){
        ll r=x%10;
        if(v.find(r)!=v.end()){
            return true;
        }
        x/=10;
    }
    return false;
}
int main()
{
    FAST;
    // your code goes here
    ll x;
    cin>>x;
    ll tmp=x;
    sl v;
    while(tmp){
        ll r=tmp%10;
        v.insert(r);
        tmp/=10;
    }

    sl d;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            d.insert(i);
            d.insert(x/i);
        }
    }
    ll ans=0;
    for(auto i:d){
        if(check(i,v)){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}