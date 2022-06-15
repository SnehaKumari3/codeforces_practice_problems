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




int main()
{
    FAST;
    // your code goes here
    ll t=1;
    // cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        vl a(n),b(n);
        rep(i,0,n){
            cin>>a[i];
        }
        rep(i,0,n){
            cin>>b[i];
        }
        ll ans=0;
        bool ok=true;
        while(ok){
            ll t=INT_MAX;
            rep(i,0,n){
                t=min(t,b[i]/a[i]);
            }
            if(t==0){
                rep(i,0,n){
                    if(b[i]<a[i]){
                        ll d=a[i]-b[i];
                        if(d>k){
                            ok=false;
                        }
                        else{
                            b[i]=a[i];
                            k-=d;
                        }
                    }
                }
            }
            else{
                ans+=t;
                rep(i,0,n){
                    b[i]-=a[i]*t;
                }
            }
        }
        cout<<ans;
        cout<<endl;
    }
    return 0;
}
