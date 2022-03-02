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
    string s;
    cin>>s;
    ll n;
    cin>>n;
    vvl v;
    ll x=0,y=0,z=0;
    rep(i,0,s.length()){
        if(s[i]=='x')
        x++;
        else if(s[i]=='y')
        y++;
        else 
        z++;
        vl v1;
        v1.pb(x);
        v1.pb(y);
        v1.pb(z);
        v.pb(v1);
    }
    while(n--){
        ll a,b;
        cin>>a>>b;
        if((b-a+1)<3){
            cout<<"YES";
        }
        else{
            ll x1,y1,z1;
            if(a==1){
                x1=v[b-1][0];
                y1=v[b-1][1];
                z1=v[b-1][2];
            }
            else{
                x1=v[b-1][0]-v[a-2][0];
                y1=v[b-1][1]-v[a-2][1];
                z1=v[b-1][2]-v[a-2][2];

            }
            ll mx=max3(x1,y1,z1);
            ll mn=min3(x1,y1,z1);
            if(mx-mn<=1){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }

        }
        cout<<endl;
    }

    return 0;
}