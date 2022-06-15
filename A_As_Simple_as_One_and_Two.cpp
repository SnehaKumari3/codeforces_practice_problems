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

ll fun(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

int main()
{
    FAST;
    // your code goes here

    ll t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin>>s;
        ll i=0;
        vl ans;
        ll cnt=0;
        while(i<s.length()){
            if(s[i]=='o'){
                if(i+2<s.length() && s[i+1]=='n' && s[i+2]=='e'){
                    ans.pb(i+2+cnt);
                    s.erase(s.begin()+i+1);
                    cnt++;
                }
            }
            else if(s[i]=='t'){
                if(i+4<s.length() && s[i+1]=='w' && s[i+2]=='o' && s[i+3]=='n' && s[i+4]=='e'){
                    ans.pb(i+3+cnt);
                    s.erase(s.begin()+i+2);
                    cnt++;
                }
                if(i+2<s.length() && s[i+1]=='w' && s[i+2]=='o'){
                    ans.pb(i+2+cnt);
                    s.erase(s.begin()+i+1);
                    cnt++;
                }
            }
            i++;
            
            
        }
        
        cout<<sz(ans)<<endl;
        rep(i,0,sz(ans)){
            cout<<ans[i]<<" ";
        }
        cout << endl;
    }
    return 0;
}