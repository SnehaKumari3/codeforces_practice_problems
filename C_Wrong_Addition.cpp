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
#define mod 998244353


int main()
{
    FAST;
    // your code goes here
    ll t;
    cin>>t;
    while(t--){
        int64_t a,s;
        cin>>a>>s;
        vl v;
        bool ok=true;
        while(s>0){
            ll r1=s%10;
            s/=10;
            ll r2=a%10;
            a/=10;
            if(r2>r1){
                r1=(s%10)*10+r1;
                s/=10;
            }
            if(r2>r1){
                ok=false;
                break;
            }
            v.pb(r1-r2);
        }
        if(a>0){
            ok=false;
        }

        if(ok){
            string res="";
            for(ll i=sz(v)-1;i>=0;i--){
            if(v[i]>9){
                ok=false;
                break;
            }
            else{
                res+=to_string(v[i]);
            }
            }
            if(ok){
            ll i=0;
            bool flag=true;
            while(i<res.size()){
                if(res[i]=='0' && flag){
                    i++;
                    continue;
                }
                else{
                    flag=false;
                    cout<<res[i++];
                }
            }
            }
            else{
                cout<<-1;
            }
        }
        else{
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}