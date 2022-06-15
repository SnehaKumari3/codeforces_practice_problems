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
#define pp pop_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define repr(i, n, b) for (int i = n; i > b; --i)
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
    // cin >> t;
    while (t--)
    {
        ll n,k,g=0,t,x,y,z,p;
        cin>>n>>k;
        vl a(n),b(n);
        rep(i,0,n){
            cin>>a[i];
            g=max(g,a[i]);
        }
        rep(i,0,n){
            cin>>b[i];
        }
        x=0;
        y=2000000000/g;
        while(x<y){
            z=(x+y+1)/2;
            p=k;
            rep(i,0,n){
                p-=max(ll(0),a[i]*z-b[i]);
            }

            if(p<0){
                y=z-1;
            }
            else{
                x=z;
            }
        }
        cout<<x<<endl;
        
        cout<<endl;
    }
    return 0;
}