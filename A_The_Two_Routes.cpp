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
ll n,m;
vl t[407];
vl b[407];
ll v1[401], d1[401],v2[401], d2[401];


void BFS1(int src)
{
    queue<int> q;
    q.push(src);
    v1[src] = 1;
    d1[src] = 0;
 
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
 
        for(int child: t[curr])
        {
            if(v1[child]==0)
            {
                q.push(child);
                d1[child] = d1[curr] + 1;
                v1[child] = 1;
            }
        }
    }
}

void BFS2(int src)
{
    queue<int> q;
    q.push(src);
    v2[src] = 1;
    d2[src] = 0;
 
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
 
        for(int child: b[curr])
        {
            if(v2[child]==0)
            {
                q.push(child);
                d2[child] = d2[curr] + 1;
                v2[child] = 1;
            }
        }
    }
}

int main()
{
    FAST;
    // your code goes here
    cin>>n>>m;
    rep(i,0,m){
        ll a,b;
        cin>>a>>b;
        t[a].pb(b);
        t[b].pb(a);
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(count(all(t[i]),j)==0){
                b[i].pb(j);
                b[j].pb(i);
            }
        }
    }
    BFS1(1);
    BFS2(1);
    if(d1[n]==0 || d2[n]==0){
        cout<<-1;
    }
    else{
        cout<<max(d1[n],d2[n]);
    }
    return 0;
}