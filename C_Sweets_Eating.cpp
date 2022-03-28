#include <bits/stdc++.h>
#include <algorithm>
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


bool compare(vl a,vl b){
    ll m1=*max_element(all(a));
    ll m2=*max_element(all(b));
    return m1>m2;
}

int main()
{
    FAST;
    // your code goes here
    ll t=1;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        vl v(n+1),s(n+1,0);
        rep(i,1,n+1){
            cin>>v[i];
            
        }
        sort(all(v));
        ll k=1;
        rep(i,1,n+1){
            s[i]=s[i-1]+v[i];
        }
        while(k<=n){
            ll ans=0;
            ll d=k/m;
            ll r=k%m;
            ll cnt=1;
            if(r==0){
                while(d>0){
                    ans+=d*(s[m*cnt]-s[m*(cnt-1)]);
                    cnt++;
                    d--;
                }
            }
            else{

                ans+=(d+1)*(s[r]);
                while(d>0){
                    ans+=d*(s[m*cnt + r]-s[m*(cnt-1)+r]);
                    cnt++;
                    d--;
                }
            }
            cout<<ans<<" ";
            k++;
        }

        cout<<endl;
    }
     
    
    return 0;
}