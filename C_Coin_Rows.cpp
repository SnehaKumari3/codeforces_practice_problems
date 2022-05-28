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
        ll m;
        cin>>m;
        ll a[2][m],b[2][m];
        rep(i,0,2){
            rep(j,0,m){
                cin>>a[i][j];
                b[i][j]=a[i][j];
            }
        }
        rep(i,2,m){
            a[0][i]+=a[0][i-1];
        }
        rep(i,1,m-1){
            a[1][i]+=a[1][i-1];
        }
        // rep(i,0,2){
        //     rep(j,0,m){
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        ll i=m-1,j=m-2;
        if(m==1){
            cout<<0;
        }
        else if(m==2){
            cout<<min(b[0][1],b[1][0]);
        }
        else{
            repr(i,m-2,0){
                b[0][i]+=b[0][i+1];
            }
            ll ans=min(a[0][m-1],a[1][m-2]);
            ll i=m-1,j=m-3;
            while(j>=0){
                ll t=max(b[0][i],a[1][j]);
                ans=min(ans,t);
                i--,j--;
            }
            cout<<ans;
        }
        cout<<endl;

    }
    
    return 0;
}