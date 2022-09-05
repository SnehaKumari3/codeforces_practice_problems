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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n,m;
        cin >> n>>m;
        vl v(m);
        rep(i,0,m){
            cin>>v[i];
        }
        sort(all(v));
        vl d;
        ll tmp=v[0]-1+n-v[m-1];
        d.pb(tmp);
        rep(i,1,m){
            d.pb(v[i]-v[i-1]-1);
        }
        sort(all(d));
        reverse(all(d));
        ll prot=0;
        ll cnt=0;
        rep(i,0,sz(d)){
            ll t=d[i]-2*cnt;
            cnt+=2;
            if(t==1){
                prot++;
                break;
            }
            else{
                t=max((ll)0,t-1);
                prot+=t;
            }
            
        }
        cout<<(n-prot);
        cout<<endl;
    }

    return 0;
}