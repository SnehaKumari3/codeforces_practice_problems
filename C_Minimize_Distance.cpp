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
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vl v1,v2;
        v1.pb(0);
        v2.pb(0);
        rep(i,0,n){
            ll a;
            cin>>a;
            if(a>0){
                v1.pb(a);
            }
            else{
                v2.pb(-1*a);
            }
        }
        sort(all(v1));
        sort(all(v2));
        ll m1=*max_element(all(v1));
        ll m2=*max_element(all(v2));
        int64_t c=0;
        if(m2>m1){
            ll i=sz(v2)-1;
            c+=v2[i];
            i-=k;
            while(i>=0){
                c+=2*v2[i];
                i-=k;
            }
            i=sz(v1)-1;
            while(i>=0){
                c+=2*v1[i];
                i-=k;
            }
        }
        else{
            ll i=sz(v1)-1;
            c+=v1[i];
            i-=k;
            while(i>=0){
                c+=2*v1[i];
                i-=k;
            }
            i=sz(v2)-1;
            while(i>=0){
                c+=2*v2[i];
                i-=k;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}