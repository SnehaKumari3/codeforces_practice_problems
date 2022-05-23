#include <bits/stdc++.h>
#include <algorithm>
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
#define INF 10007


int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        vpll v;
        ll a[n];
        rep(i,0,n){
            cin>>a[i];
            v.pb({a[i],i});
        }
        sort(all(v));
        if(k>=n){
            cout<<0;
        }
        else{
            ll j=n-1,k1=k;
            vl tmp;
            while(k1--){
                tmp.pb(v[j].se);
                j--;
            }
            sort(all(tmp));
            k1=1;
            rep(i,0,sz(tmp)){
                if(tmp[i]+1<n){
                    a[tmp[i]+1]+=k1;
                }
                k1++;
            }
            ll ans=0;
            k1=0;
            rep(i,0,n){
                if(k1<k && i==tmp[k1]){
                    k1++;
                }
                else{
                    ans+=a[i];
                }
            }
            cout<<ans;
        }
        cout<<endl;
    }
    return 0;
}