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

bool compare(pll a, pll b)
{
    return a.se > b.se;
}


int p[200006][3];
int l[200006]={0};
// int solve(int n,int m){
//     rep(i,0,n+1){
//         rep(j,0,m+1){
//             if(i==0 || j==0){
//                 a[i][j]=0;
//             }
//         }
//     }
// }
int main()
{
    FAST;
    // your code goes here
    ll n, m1;
    cin >> n;
    mll m;
    rep(i,0,200006){
        rep(j,0,200006){
            p[i][j]=0;
        }
    }
    rep(i, 0, n)
    {
        ll a;
        cin >> a;
        l[a]+=1;
    }
    cin >> m1;
    ll a[m1][2];
    rep(i, 0, m1)
    {
        cin >> a[i][0];
    }
    rep(i, 0, m1)
    {
        cin >> a[i][1];
    }
    rep(i,0,m1){
        p[a[i][0]][2]=a[i][0];
        p[a[i][0]][0]+=l[a[i][0]];
        p[a[i][0]][1]+=l[a[i][1]];
    }
    
    return 0;
}