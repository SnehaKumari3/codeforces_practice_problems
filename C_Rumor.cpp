#include <bits/stdc++.h>
#include <set>
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

ll n;
int64_t res=1e9+7,ans=0;
vl v(100005,0);
vector<ll> adj[100005]; 
vector<bool> vis(100005);

void dfs(ll v1) {
    vis[v1] = true;
    res=min(res,v[v1]);
    for (auto u : adj[v1]) {
        if (!vis[u])
            dfs(u);
    }
}

int main()
{
    FAST;
    // your code goes here
    ll m;
    cin>>n>>m;
    rep(i,1,n+1){
        cin>>v[i];
        vis[i]=false;
    }
    
    while(m>0){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        m--;
    }

    rep(i,1,n+1){
        if(!vis[i]){
            dfs(i);
            ans+=res;
            res=1e9+7;
        }
    }
    cout<<ans;

    // rep(i,0,n+1){
    //     for(auto j:adj[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    
    return 0;
}