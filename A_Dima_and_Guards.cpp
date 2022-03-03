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
bool compare(vl a,vl b){
    return a[0]+a[1]<b[0]+b[1];
}

int main()
{
    FAST;
    // your code goes here
    ll n;
    cin>>n;
    vvl v;
    rep(i,0,4){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a=min(a,b);
        c=min(c,d);
        vl t;
        t.pb(a),t.pb(c),t.pb(i+1);
        v.pb(t);
    }
    sort(all(v),compare);
    if((v[0][0]+v[0][1])==n){
        cout<<v[0][2]<<" "<<v[0][0]<<" "<<v[0][1];
    }
    else if((v[0][0]+v[0][1])<n){
        cout<<v[0][2]<<" "<<v[0][0]<<" "<<n-v[0][0];
    }
    else{
        cout<<-1;
    }
    return 0;
}