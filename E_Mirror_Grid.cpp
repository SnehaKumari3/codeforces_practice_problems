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

ll solve(string a,string b,string c,string d){
    ll res=0;
    rep(i,0,sz(a)-1){
        ll tmp=0;
        if(a[i]=='1'){
            tmp++;
        }
        if(b[i]=='1'){
            tmp++;
        }
        if(c[i]=='1'){
            tmp++;
        }
        if(d[i]=='1'){
            tmp++;
        }
        res+=min(tmp,4-tmp);
    }
    return res;
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<vector<char>> v;
        rep(i,0,n){
            vector<char> t(n);
            rep(j,0,n){
                cin>>t[j];
            }
            v.pb(t);
        }
        ll ans=0,rf=0,re=n-1,cf=0,ce=n-1;
        while(rf<re){
            ll tmp=INT_MAX;
            string a="",b="",c="",d="";
            rep(j,cf,ce+1){
                a+=v[rf][j];
            }
            rep(j,cf,ce+1){
                b+=v[re][j];
            }
            reverse(all(b));
            rep(i,rf,re+1){
                c+=v[i][cf];
            }
            reverse(all(c));
            rep(i,rf,re+1){
                d+=v[i][ce];
            }
            tmp=min(tmp,solve(a,b,c,d));
            // ll tmp_cnt=0;
            // if(v[rf][cf]=='1'){
            //     tmp_cnt++;
            // }
            // if(v[re][cf]=='1'){
            //     tmp_cnt++;
            // }
            // if(v[rf][ce]=='1'){
            //     tmp_cnt++;
            // }
            // if(v[re][ce]=='1'){
            //     tmp_cnt++;
            // }
            // tmp_cnt=min(tmp_cnt,4-tmp_cnt);
            rf++,re--,cf++,ce--;
            ans+=tmp;
            // ans+=tmp_cnt;
        }
        cout<<ans;
        
        cout<<endl;
    }
}