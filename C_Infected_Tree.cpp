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
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repr(i, n, b) for (ll i = n; i > b; i--)
#define repv(v) for (auto x : v)
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof a)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define sz(v) ll(v.size())
#define mod 1000000007



vector<int> adj[300005];
int dfs(int s,int p=-1){
    rep(i,0,sz(adj[s])){
        if(adj[s][i]==p){
            adj[s].erase(adj[s].begin()+i);
        }
    }
    if(adj[s].size()==0)
        return 1;
    if(adj[s].size()==1){
        return 2;
    }
    return min(dfs(adj[s][0],s),dfs(adj[s][1],s))+2;
}


int main()
{
    FAST;
    // your code goes here

    ll t = 1;
    cin >> t;
    while (t--)
    {
        rep(i,1,300006){
            adj[i].clear();
        }
        ll n;
        cin>>n;
        rep(i,1,n){
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        cout<<n-dfs(1,-1);
        cout<<endl;
    }
    return 0;
}
