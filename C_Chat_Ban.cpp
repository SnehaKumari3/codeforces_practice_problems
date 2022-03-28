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

ll solve(ll a,ll s,ll d,ll k){
    ll i=1,j=k;
    ll ans=k;
    while(i<=j){
        ll mid=i+(j-i)/2;
        ll sum=(mid*(2*a+(mid-1)*d))/2;
        
        if(sum<=s){
            i=mid+1;
        }
        else{
            ans=min(ans,mid);
            j=mid-1;
        }
    }
    return ans;
}

int main()
{
    FAST;
    // your code goes here
    ll t=1;
    cin>>t;
    while(t--){
        ll k,x;
        cin>>k>>x;
        ll ans=0;
        int64_t m1=k*k;
        int64_t m2=(k*(k+1))/2;
        if(x>=m1){
            ans=(2*k)-1;
        }
        else if(x>m2){
            ans+=k;
            x-=m2;
            ll t=solve(k-1,x,-1,k-1)-1;
            x-=(t*(2*(k-1)+(t-1)*-1))/2;
            ans+=t;
            if(x>0){
                ans++;
            }
        }
        else{
            ll t=solve(1,x,1,k)-1;
            x-=(t*(2+(t-1)))/2;
            ans+=t;
            if(x>0){
                ans++;
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}