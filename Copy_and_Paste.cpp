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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n,m,cnt=0,ans=0,d=0,r=0;
        string s;
        cin>>n>>m;
        cin>>s;
        cout<<s<<endl;
        for(ll i=0;i<n;i++){
            if(s[i]=='1') cnt++;
        }
        
        if((cnt*m)%2==1){
            cout<<0;
        }
        else{
            d=(n*m)/(2*cnt);
            r=(n*m)%(2*cnt);
            for(ll i=r;i<n;i++){
                if(s[i]=='1') {
                    break;
                }
                else{
                    ans++;
                }

            }
            cout<<ans;
        }
        
        cout<<endl;
    }

    return 0;
}