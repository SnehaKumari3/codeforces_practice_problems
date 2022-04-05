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

int dp[200005];
int solve(string &s,int i){
    if(i>=sz(s))
        return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    if(i==sz(s)-1)
        return 1;
    if(i+1<sz(s) && s[i]==s[i+1])
        return solve(s,i+2);
    else{
        int j=i+1;
        for(;j<sz(s);j++){
            if(s[i]==s[j]){
                break;
            }
        }
        if(j==sz(s)){
            return 1+solve(s,i+1);
        }
        else{
            int c1=j-i-1 + solve(s,j+1);
            int c2=1 + solve(s,i+1);
            return dp[i]=min(c1,c2);
        }
    }
}

int main()
{
    FAST;
    // your code goes here
    int t=1;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        rep(i,0,sz(s)){
            dp[i]=-1;
        }
        int ans=solve(s,0);
        cout<<ans<<endl;
    }
    return 0;
}