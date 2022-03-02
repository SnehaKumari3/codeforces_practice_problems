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
    int64_t n,k,d;
    cin>>n>>k>>d;
    if(d==1){
        if(k<n){
            cout<<-1;
        }
        else{
            
            rep(i,0,d){
                ll i1=1,j1=k;
                rep(j,0,i){
                    cout<<j<<" ";
                    j1--;
                }
                rep(j,i,n){
                    cout<<i1<<" ";
                    i1++;
                }
            }

        }
    }
    else{
        vl v,ans;
        ll k1=1;
        rep(i,0,n){
            v.pb(k1);
            k1++;
            if(k1>k){
                k1=1;
            }
        }
        k1=1;
        ll tmp=n,cnt=0;
        while(tmp--){
            ans.pb(k1);
            cnt++;
            if(cnt==k){
                cnt=0;
                k1++;
            }
            if(k1>k){
                k1=1;
            }
        }
        bool okay=true;
        rep(i,1,n){
            if(ans[0]==ans[i] && v[0]==v[i]){
                okay=false;
                break;
            }
        }
        if(!okay){
            cout<<-1;
        }
        else{
            rep(i,0,d-1){
                rep(j,0,n)
                cout<<v[j]<<" ";
                cout<<endl;
            }
            rep(i,0,sz(ans))
            cout<<ans[i]<<" ";
        }
    }

    return 0;
}