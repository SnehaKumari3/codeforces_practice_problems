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


int main()
{
    FAST;
    // your code goes here
    ll t=1;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        ll i=0;
        while(i<(n-1)){
            if(a[i]!=b[i]){
                if(a[i+1]==b[i])
                    a[i]=a[i+1];
                else if(b[i]==b[i+1] && a[i]!='z'){
                    a[i]=a[i+1];
                }
            }
            i++;
        }
        vl a1(n,0),b1(n,0);
        i=1;
        a1[0]=1,b1[0]=1;
        bool ok=true;
        
        while(i<n){
            if(a[i]==a[i-1]){
                a1[i]=a1[i-1]+1;
            }
            else{
                a1[i]=1;
            }

            if(a1[i]>k){
                a1[i]=1;
            }
            i++;
        }
        i=1;
        
        while(i<n){
            if(b[i]==b[i-1]){
                b1[i]=b1[i-1]+1;
            }
            else{
                b1[i]=1;
            }

            if(b1[i]>k){
                b1[i]=1;
            }

            if(a1[i]==b1[i] && a[i]!='z'){
                i++;
                continue;
            }
            else{
                ok=false;
                break;
            }
            i++;
        }
        
        if(ok){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}