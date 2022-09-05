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
        ll n,q1;
        cin>>n>>q1;
        vl v(n+1,0);
        vl q;
        rep(i,1,n+1){
            cin>>v[i];
            q.pb(i);
        }
        vl adj[n+1];
        ll cnt=1;
        while(v[q[0]]!=n && cnt<n){
            if(v[q[0]] > v[q[1]]){
                int tmp1=q[0];
                int tmp2=q[1];
                q.erase(q.begin()+1);
                q.pb(tmp2);
                adj[tmp1].pb(cnt);
            }
            else{
                int tmp1=q[0];
                int tmp2=q[1];
                q.erase(q.begin());
                q.pb(tmp1);
                adj[tmp2].pb(cnt);
            }
            cnt++;
        }
        
        while(q1>0){ 
            ll ind,r;
            cin>>ind>>r;
            ll left=0,right=adj[ind].size()-1;
            while(left < right){
                ll mid=(left+right)/2;
                if(adj[ind][mid] == r){
                    left=mid;
                    break;
                }
                else if(adj[ind][mid] > r){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            ll ans=left;
            if(v[ind]==n){
                ans+=r-left+1;
            }
            cout<<ans<<endl;
            q1--;
        }
    }
    return 0;
}