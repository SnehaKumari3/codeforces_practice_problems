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
        vector<string> v;
        map<string,ll> m,res;
        rep(i,0,n){
            string t;
            cin>>t;
            v.pb(t);
            m[t]++;
        }
        
        string ans="";
        for(auto i:m){
            bool flag=false;
            string x=i.fi;
            rep(i,0,sz(x)){
                string t1=x.substr(0,i);
                string t2=x.substr(i,sz(x)-i);
                if(m.find(t1)!=m.end() && m.find(t2)!=m.end()){
                    flag=true;
                    break;
                }
            }
            if(flag){
                res[x]++;
            }
            
        }
        rep(i,0,n){
            if(res[v[i]] >0){
                ans+='1';
            }
            else{
                ans+='0';
            }
        }
        cout<<ans;

        cout<<endl;
    }
}