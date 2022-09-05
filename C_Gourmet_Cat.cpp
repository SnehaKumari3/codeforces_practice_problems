#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
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
        ll a,b,c;
        cin>>a>>b>>c;
        ll w=a/3;
        w=min(w,b/2);
        w=min(w,c/2);
        c=c-w*2;
        a=a-w*3;
        b=b-w*2;
        w=w*7;
        vvl cnt;
        cnt.pb({1,0,0});
        cnt.pb({1,0,0});
        cnt.pb({0,1,0});
        cnt.pb({0,0,1});
        cnt.pb({1,0,0});
        cnt.pb({0,0,1});
        cnt.pb({0,1,0});
        ll ans=0;
        
        for(int i=0;i<=6;i++){
            ll tmp=0;
            ll a1=a,a2=b,a3=c;
            for(int j=i;j<=i+6;j++){
                ll ind=j%7;
                a1-=cnt[ind][0];
                a2-=cnt[ind][1];
                a3-=cnt[ind][2];
                if(a1>=0 && a2>=0 && a3>=0){
                    tmp++;
                }
                else{
                    break;
                }
            }
            ans=max(ans,tmp);
        }
        cout<<w+ans;
    }
}