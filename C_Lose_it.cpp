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

int index(ll a){
    if(a==4)
        return 0;
    if(a==8)
        return 1;
    if(a==15)
        return 2;
    if(a==16)
        return 3;
    if(a==23)
        return 4;
    return 5;
}


int main()
{
    FAST;
    // your code goes here
    ll n;
    cin>>n;
    vl v(6,0);
    rep(i,0,n){
        ll a;
        cin>>a;
        ll id=index(a);
        if(id==0){
            v[id]+=1;
        }
        else{
            if(v[id]<v[id-1]){
                v[id]+=1;
            }
        }
    }
    ll ans=6*v[5];
    cout<<n-ans;

    return 0;
}