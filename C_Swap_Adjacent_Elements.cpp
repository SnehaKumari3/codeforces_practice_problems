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

vector<ll> adj[200005]; 
vector<bool> vis(200005);
vl t;
void dfs(ll v1) {
    vis[v1] = true;
    for (auto u : adj[v1]) {
        if (!vis[u]){
            t.pb(u);
            dfs(u);
        }
    }
}

int main()
{
    FAST;
    // your code goes here
    ll n;
    cin>>n;
    vl v(n+1);
    rep(i,1,n+1){
        cin>>v[i];
        vis[i]=false;
    }
    string s="z",inp;
    cin>>inp;
    s+=inp;
    vl ans;
    rep(i,1,sz(s)){
        if(s[i]=='1'){
            adj[v[i]].pb(v[i+1]);
            adj[v[i+1]].pb(v[i]);
        }
    }
    rep(i,1,sz(s)){
        
        if(s[i]=='1'){
            if(!vis[v[i]]){
                t.pb(v[i]);
                dfs(v[i]);
                sort(all(t));
                rep(i,0,sz(t)){
                    ans.pb(t[i]);
                }
                i+=sz(t)-1;
                t.clear();
            }
        }
        else{
            ans.pb(v[i]);
        }
    }
    if(sz(ans)<n){
        ans.pb(v[n]);
    }
    
    bool ok=true;
    rep(i,0,sz(ans)){
        if(ans[i]!=i+1){
            ok=false;
            break;
        }
    }
    if(ok){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}