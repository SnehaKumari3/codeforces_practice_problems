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
        ll n,ans=1;
        cin >> n;
        vl v(n);
        mll m;
        rep(i,0,n){
            cin>>v[i];
            m[v[i]]++;
        }
        ll ind=1;
        vl cnt(100001,0);
        sort(all(v));
        for(auto x:m){
            ll tmp=x.se;
            ll j=0;
            while(tmp > 0){
                if(x.fi > cnt[j]){
                    ll d=x.fi-cnt[j];
                    cnt[j]+=min(d,tmp);
                    tmp-=min(tmp,d);
                    j++;
                }
                else{
                    while(x.fi <= cnt[j]){
                        j++;
                    }
                }
            }
        }
        ll c=count(all(cnt),0);
        ans=100001-c;
        cout<<ans;
        cout << endl;
    }
}