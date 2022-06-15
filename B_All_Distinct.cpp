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
        ll n;
        cin>>n;
        vl v(n);
        mll m;
        rep(i,0,n){
            cin>>v[i];
            m[v[i]]++;
        }
        if(sz(m)==n){
            cout<<n;
        }
        else{
            ll cnt=0;
            for(auto i:m){
                if(i.se>1){
                    if(i.se%2==1){
                        m[i.fi]=1;
                    }
                    else{
                        m[i.fi]=2;
                    }
                }
            }
            ll c1=0,c2=0;
            for(auto i:m){
                if(i.se==2){
                    c1++;
                }
                if(i.se==1){
                    c2++;
                }
            }
            if(c1%2==0){
                cout<<m.size();
            }
            else{
                
                if(c2>0){
                    cout<<c1+c2-1;
                }
                else{
                    cout<<c1-1;
                }
            }
        }
        
        cout<<endl;
    }
    return 0;
}