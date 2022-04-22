#include <bits/stdc++.h>
#include "cmath"
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

vector<int> adj[10001];
vl c(10001,0);

int n; // number of vertices
ll ans=0;
vector<bool> visited(10001,false);

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]){
            if(c[u]!=c[v]){
                ans++;
            }
            dfs(u);
        }
    }
}


int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        cin>>n;
        adj[0].pb(1);
        rep(i,1,n){
            ll a;
            cin>>a;
            adj[i+1].pb(a);
            adj[a].pb(i+1);
        }
        // rep(i,1,n+1){
        //     rep(j,0,sz(adj[i])){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        rep(i,1,n+1){
            cin>>c[i];
        }
        dfs(1);
        cout<<ans+1;

    }
    return 0;
}