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


int main()
{
    FAST;
    // your code goes here
    ll t=1;
    cin>>t;
    while(t--){
        ll n,q,tmp=0;
        cin>>n>>q;
        string s,t;
        cin>>s>>t;
        vl ps(n+1,0);
        rep(i,1,n+1){
            if(s[i-1]==t[i-1]){
                tmp=0;
            }
            else if(t[i-1]>s[i-1]){
                tmp=t[i-1]-s[i-1];
            }
            else{
                tmp=26 + t[i-1]-s[i-1];
            }
            if(i%2==0){
                tmp*=-1;
            }
            
            ps[i]=ps[i-1]+tmp;
            ps[i]=(ps[i]+26)%26;
        }
        
        while(q--){
            ll l,r;
            cin>>l>>r;
            if(ps[r]-ps[l-1]==0){
                cout<<"Yes";
            }
            else{
                cout<<"No";
            }
            cout<<endl;
        }
         
    }
    
    return 0;
}