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

bool compare(pair<char,ll> a,pair<char,ll> b){
    return b.se<a.se;
}

int main()
{
    string s;
    cin>>s;
    ll n;
    cin>>n;
    map<char,ll> m;
    rep(i,0,sz(s)){
        m[s[i]]++;
    }
    // for(auto j:m){
    //     cout<<j.fi<<" "<<j.se<<endl;
    // }
    if(m.size()>n){
        cout<<-1;
    }
    else if(m.size()==n){
        ll mx=-1;
        for(auto i:m){
            mx=max(i.se,mx);
        }
        cout<<mx<<endl;
        for(auto i:m){
            cout<<i.fi;
        }
    }
    else{
        string ans="";
        vector<pair<char,ll>> v;
        for(auto j:m){
            v.pb({j.fi,j.se});
        }
        sort(all(v),compare);
        ll d=n-sz(m);
        map<char,ll> m1;
        rep(i,0,sz(v)){
            
            ans+=v[i].fi;
            m1[v[i].fi]++;
            if(d>0){
                ans+=v[i].fi;
                m1[v[i].fi]++;
                d--;
            }
        }
        ll res=-1;
        for(auto j:m1){
            ll d=m[j.fi]/j.se;
            ll r=m[j.fi]%j.se;
            if(r==0){
                res=max(res,d);
            }
            else{
                res=max(res,d+1);
            }
        }
        cout<<res<<endl<<ans;
    }
}