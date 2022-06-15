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
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define repr(i, n, b) for (int i = n; i > b; --i)
#define repv(v) for (auto x : v)
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof a)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define sz(v) ll(v.size())
#define mod 1000000007



int t,n,m,ans,tmp,x,y,l[1000],r[1000];
char a[1000][1000];

int main()
{
    FAST;
    // your code goes here

    cin >> t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        char a[n][m];
        rep(i,0,n){
            l[i]=-1;
        }
        ans=1e9;
        rep(i,0,n){
            rep(j,0,m){
                cin>>a[i][j];
                if(a[i][j]=='B'){
                    if(l[i]==-1){
                        l[i]=j;
                    }
                    r[i]=j;
                }
            }
        }
        
        
        rep(i,0,n){
            rep(j,0,m){
                tmp=0;
                rep(k,0,n){
                    if(l[k]!=-1)
                    tmp=max(tmp,abs(k-i)+max(abs(l[k]-j),abs(r[k]-j)));
                }
                if(ans>tmp){
                    ans=tmp;
                    x=i,y=j;
                }
            }
        }
        
        cout<<x+1<<" "<<y+1;
        cout<<endl;
    }
    return 0;
}