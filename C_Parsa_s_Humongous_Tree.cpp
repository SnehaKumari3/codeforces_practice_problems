#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
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
ll rem(ll a, ll b, ll c)
{
    return a % 2 + b % 2 + c % 2;
}

vl adj[100005];
int vis[100005];
ll ans=0;
void dfs(int s,int p,vpll &v){
    vis[s]=1;
    int sz=0;
    for(auto x:adj[s]){
        if(vis[x]==0){
            sz++;
            dfs(x,s,v);
            if(sz>0){
                vpll tmp;
                tmp.pb({abs(v[s].fi-v[x].fi),v[s].fi});
                tmp.pb({abs(v[s].se-v[x].fi),v[s].se});
                tmp.pb({abs(v[s].fi-v[x].se),v[s].fi});
                tmp.pb({abs(v[s].se-v[x].se),v[s].se});
                sort(all(tmp));
                ans+=tmp[3].fi;
                v[s].fi=tmp[0].se;
                v[s].se=tmp[3].se;
            }
        }
    }
}


int main()
{
    FAST;
    // your code goes here
    ll t=1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vpll v;
        ans=0;
        v.pb({0,0});
        rep(i,0,100005){
            adj[i].clear();
            vis[i]=0;
        }
        rep(i,0,n){
            ll a,b; cin>>a>>b; v.pb({a,b});
        }
        rep(i,0,n-1){
            ll u,v; cin>>u>>v;
            adj[u].pb(v),adj[v].pb(u);
        }

        dfs(1,-1,v);
        cout<<ans;
        cout << endl;
    }
    return 0;
}