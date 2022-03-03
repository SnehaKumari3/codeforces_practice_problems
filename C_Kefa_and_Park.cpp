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

vl v[100007];
int a[100007],c[100007];
vl r;
int visited[100007];
ll n,m;
 
 
void BFS1(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    if(a[src]==1){
        c[src]=1;
    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        bool ok=false;
        for(int child: v[curr])
        {
            
            if(visited[child]==0)
            {
                q.push(child);
                if(c[curr]>m){
                    c[child]=m+1;
                }
                else if(a[child]==1 && a[curr]==1){
                    c[child]=c[curr]+1;
                }
                else if(a[child]==1 && a[curr]==0){
                    c[child]=1;
                }
                else if(a[child]==0 && a[curr]==1){
                    c[child]=c[curr];
                }
                else{
                    c[child]=0;
                }
                visited[child] = 1;
                ok=true;
            }
        }
        if(!ok){
        r.pb(curr);
    }
    }
}



int main()
{
    FAST;
    // your code goes here
    cin>>n>>m;
    rep(i,1,n+1){
        cin>>a[i];
    }
    rep(i,1,n){
        ll a1,b1;
        cin>>a1>>b1;
        v[a1].pb(b1);
        v[b1].pb(a1);
    }

    if(a[1]==1){
        c[1]=1;
    }
    else{
        c[1]=0;
    }
    BFS1(1);
    ll rest=0;
    
    rep(i,0,sz(r)){
        if(c[r[i]]<=m){
            rest++;
        }
    }
    cout<<rest;
    return 0;
}