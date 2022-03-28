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
int ROW ,COL;
int dRow[] = { 0, 1, 0, -1 };
int dCol[] = { -1, 0, 1, 0 };
bool isValid(bool vis[][COL],
             int row, int col)
{
    if (row < 1 || col < 1
        || row > ROW || col > COL)
        return false;
    if (vis[row][col])
        return false;
    return true;
}

void DFS(int row, int col,
         int grid[][COL],
         bool vis[][COL])
{
    stack<pair<int, int> > st;
    st.push({ row, col });
 
    while (!st.empty()) {
        pair<int, int> curr = st.top();
        st.pop();
        int row = curr.first;
        int col = curr.second;
 
        if (!isValid(vis, row, col))
            continue;
 
        vis[row][col] = true;
        int t[2]={0};
        if(row+1)
 
        
        for (int i = 0; i < 4; i++) {
            int adjx = row + dRow[i];
            int adjy = col + dCol[i];
            st.push({ adjx, adjy });
        }
    }
}


int main()
{
    FAST;
    // your code goes here
    ll t=1;
    cin>>t;
    while(t--){
        ll n,m,x1,y1,x2,y2;
        cin>>n>>m;
        ll a[n+1][m+1];
        rep(i,0,n+1){
            rep(j,0,m+1){
                a[i][j]=0;
            }
        }
        cin>>x1>>y1>>x2>>y2;
        a[x1][y1]=1;
        a[x2][y2]=2;
        bool vis[ROW][COL];
        memset(vis, false, sizeof vis);
        DFS(0, 0, a, vis);
        rep(i,1,n+1){
            rep(j,1,m+1){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    
    return 0;
}