//CodeChef Starters 28 Division 2 (question 3)

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

void solve(){
    cin>>n>>m;
    g.resize(n);
}
int main()
{
    FAST;
    // your code goes here
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vl v[n+1];
        rep(i,0,m){
            ll a,b;
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        vl vis(n+1,0);
        vl d(n+1,0);
        queue<int> q;
        q.push(1);
        d[0]=0;
        vis[0]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto child : v[curr]){
                if(vis[child]==0){
                    q.push(child);
                    vis[child]=1;
                    d[child]=d[curr]+1;
                }
            }
        }
        ll nc=1;
        rep(i,1,n+2){
            if(vis[i]==1){
                nc=i;
            }
        }  
        ll res=(n-nc);
        cout<<res<<endl;
    }

    return 0;
}