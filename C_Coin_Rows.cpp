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
    ll t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll v[3][n+1];
        rep(i,0,n){
            cin>>v[1][i+1];
        }
        rep(i,0,n){
            cin>>v[2][i+1];
        }
        ll ans1=0,ans2=0;
        ll a[3][n+1];
        rep(i,0,n+2){
            a[0][i]=0;
            a[1][i]=0;
            a[2][i]=0;
        }
        a[1][1]=0;
        rep(i,1,3){
            rep(j,1,n+1){
                if(i+1<=n){
                    a[i+1][j]=max(a[i+1][j],v[i+1][j]+a[i][j]);
                }
                if(j+1<=n){
                    a[i][j+1]=max(a[i][j+1],v[i][j+1]+a[i][j]);
                }
            }
        }
        ll s=0;
        rep(i,1,3){
            rep(j,1,n+1){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<s-a[2][n]<<endl;

    }
    
    return 0;
}