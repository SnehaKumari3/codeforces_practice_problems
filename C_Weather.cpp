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
    // cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vl v(n),pre_pos(n,0),suf_neg(n,0);
        rep(i,0,n){
            cin>>v[i];
        }
        rep(i,0,n){
            if(v[i]>=0){
                pre_pos[i]+=1;
            }

            if(i>0){
                pre_pos[i]+=pre_pos[i-1];
            }
        }
        repr(i,n-1,-1){
            if(v[i]<=0){
                suf_neg[i]+=1;
            }
            if(i<n-1){
                suf_neg[i]+=suf_neg[i+1];
            }
        }
        

        ll ans=INT_MAX;
        for(int i=1;i<n-1;i++){
            ll p=pre_pos[i-1];
            ll n=suf_neg[i+1];
            if(v[i]==0){
                ans=min(ans,p+n+1);
            }
            else {
                ans=min(ans,p+n);
            }
        }
        if(v[0]<0){
            ans=min(ans,suf_neg[1]);
        }
        if(v[n-1]>0){
            ans=min(ans,pre_pos[n-2]);
        }
        
        cout<<ans;
        cout << endl;
    }
}