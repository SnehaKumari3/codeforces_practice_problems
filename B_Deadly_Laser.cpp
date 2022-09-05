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
ll x,y,d,step=0,n,m;
// int vis[10001][10001]={0};
// bool ok=false;
// bool isValid(ll i,ll j){
//     if(i>=1 && i<=n && j>=1 && j<=m){
//         return true;
//     }
//     return false;
// }
// int dx[5]={0,1,0,-1,0};
// void dfs(int i,int j){
//     vis[i][j]=1;
//     if(ok) return;
//     if(i==n && j==m){
//         ok=false;
//         return ;
//     }
//     step++;
//     for(int k=0;k<4;k++){
//         if(isValid(i+dx[k],j+dx[k+1]) && vis[i+dx[k]][j+dx[k+1]]==0){
//             ll dis=abs(x-(i+dx[k]))+abs(y-(j+dx[k+1]));
//             if(dis > d){
//                 dfs(i+dx[k],j+dx[k+1]);
//             }
//             else{
//                 vis[i+dx[k]][j+dx[k+1]]=-1;
//             }
//         }
//     }
// }
int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    cin >> t;
    while (t--)
    {
        
        cin>>n>>m>>x>>y>>d;
        bool f1=true,f2=true,f3=true,f4=true;
        ll step=n+m-2;
        for(ll i=2;i<=n;i++){
            ll dis=abs(x-i)+abs(y-1);
            if(dis <= d){
                f1=false;
                break;
            }
        }
        for(ll i=2;i<=m;i++){
            ll dis=abs(x-n)+abs(y-i);
            if(dis <= d){
                f2=false;
                break;
            }
        }
        for(ll i=2;i<=m;i++){
            ll dis=abs(x-1)+abs(y-i);
            if(dis <= d){
                f3=false;
                break;
            }
        }
        for(ll i=2;i<=n;i++){
            ll dis=abs(x-i)+abs(y-m);
            if(dis <= d){
                f4=false;
                break;
            }
        }
        if((f1 && f2 ) || (f3 && f4)){
            cout<<step;
        }
        else{
            cout<<-1;
        }
        
        cout << endl;
    }

    return 0;
}