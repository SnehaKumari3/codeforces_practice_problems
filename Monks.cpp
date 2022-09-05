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
#define pop pop_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define mem0(a) memset(a, 0, sizeof(a))
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
    ll t = 1;
    cin >> t;

    while (t--)
    {
        ll n;
        cin>>n;
        vl v(n);
        rep(i,0,n){
            cin>>v[i];
        }
        sort(all(v));
        vl s(n,0);
        vl suff(n,0);
        suff[n-1]=v[n-1];
        ll i=1;
        while(i<n){
            if(v[i]>v[i-1]){
                s[i]=i*(v[i]-v[i-1]) + s[i-1];
            }
            else{
                s[i]+=s[i-1];
            }
            i++;
        }
        
        repr(i,n-2,-1){
            suff[i]=suff[i+1]+v[i];
        }
        
        ll ans=0;
        if(s[n-1]!=0){
            ans=1;
            repr(i,n-2,0){
                if(suff[i+1]>=s[i]){
                    break;
                }
                else{
                    ans++;
                }
            }
        }
        
        cout<<ans;
        cout<<endl;
    }
}