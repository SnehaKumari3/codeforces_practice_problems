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
#define pp pop_back
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

bool cmp(vl a,vl b){
    if(a[1]==b[1]){
        return a[0]>b[0];
    }
    return a[1]<b[1];
}

int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vvl q;
        
        rep(i,1,n+1){
            ll x;
            cin>>x;
            if(x==0){
                ll tmp=i+1;
                q.pb({tmp,n,i});
            }
            else{
                ll tmp=(i/(x+1))+1;
                q.pb({tmp,i/x,i});
            }
        }
        sort(all(q),cmp);
        vl ans(n+1,0);
        set<ll> s;
        rep(i,1,n+1) s.in(i);
        rep(i,0,sz(q)){
            auto x=q[i];
            ll tmp=*s.lower_bound(x[0]);
            ans[x[2]]=tmp;
            s.erase(tmp);
        }
        
        rep(i,1,n+1){
            cout<<ans[i]<<" ";
        }
        cout << endl;
    }
}