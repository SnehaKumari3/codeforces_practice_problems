#include <bits/stdc++.h>
#include <algorithm>
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
#define mem0(a) memset(a, 0, sizeof(a))
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repr(i, n, b) for (ll i = n; i > b; i--)
#define repv(v) for (auto x : v)
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof a)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define sz(v) ll(v.size())
#define mod 1000000007

const int N=200001;
vl adj[N];
int color[N];
bool ok=true;

void dfs(int s,int c){
    if(!ok) return;
    color[s]=c;
    for(auto child:adj[s]){
        if(color[child]==0){
            dfs(child,-c);
        }
        else{
            if(color[child] != -c){
                ok=false;
                return;
            }
        }
    }
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        ok=true;
        rep(i,0,n+1){
            adj[i].clear();
            color[i]=0;
        }
        rep(i,0,n){
            ll u,v;
            cin>>u>>v;
            adj[u].pb(v),adj[v].pb(u);
        }
        rep(i,1,n+1){
            if(adj[i].size()>2){
                ok=false;
                break;
            }
        }

        if(ok){
            rep(i,1,n+1){
                if(color[i]==0 && ok){
                    dfs(i,1);
                }
            }
        }


        if(ok){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }

        cout << endl;
    }
}