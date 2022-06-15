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

int v[1000005];
int a[10][1000005];

ll pod(ll n){
    ll ans=1;
    while(n>0){
        ll r=n%10;
        if(r>0){
            ans*=r;
        }
        n/=10;
    }
    return ans;
}

ll g(ll n){
    if(n<10){
        return n;
    }
    return g(pod(n));
}

int main()
{
    FAST;
    // your code goes here
    
    ll t;
    cin>>t;
    rep(i,0,1000005){
        v[i]=g(i);
    }
    
    rep(i,1,10){
        rep(j,1,1000005){
            if(v[j]==i){
                a[i][j]=a[i][j-1]+1;
            }
            else
            a[i][j]=a[i][j-1];
        }
    }

    while(t--){
        ll l,r,k;
        cin>>l>>r>>k;
        cout<<a[k][r]-a[k][l-1];
        cout<<endl;
    }
    return 0;
}