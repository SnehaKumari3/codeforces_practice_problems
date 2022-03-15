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


int main()
{
    FAST;
    // your code goes here
    ll t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vl a(n),b(n);
        rep(i,0,n){
            cin>>a[i];
        }
        rep(i,0,n){
            cin>>b[i];
        }
        ll mna1,mna2,mnb1,mnb2;
        mna1=abs(b[0]-a[0]);
        rep(i,1,n){
            mna1=min(mna1,abs(b[i]-a[0]));
        }
        mna2=abs(b[0]-a[n-1]);
        rep(i,1,n){
            mna2=min(mna2,abs(b[i]-a[n-1]));
        }
        mnb1=abs(a[0]-b[0]);
        rep(i,1,n){
            mnb1=min(mnb1,abs(a[i]-b[0]));
        }
        mnb2=abs(a[0]-b[n-1]);
        rep(i,1,n){
            mnb2=min(mnb2,abs(a[i]-b[n-1]));
        }
        ll r=abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
        r=min(r,abs(a[0]-b[n-1])+abs(b[0]-a[n-1]));
        r=min(r,abs(a[0]-b[0])+mna2+mnb2);
        r=min(r,abs(a[n-1]-b[n-1])+mna1+mnb1);
        r=min(r,abs(a[0]-b[n-1])+mnb1+mna2);
        r=min(r,abs(b[0]-a[n-1])+mna1+mnb2);
        r=min(r,mna1+mna2+mnb1+mnb2);
        cout<<r<<endl;

    }
    
    return 0;
}