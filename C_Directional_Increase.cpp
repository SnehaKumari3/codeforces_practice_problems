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

ll lcm(ll a, ll b)
{
    return a / (__gcd(a, b)) * b;
}

void fun(ll n,vl v){
    vl t=v;
    sort(all(t));
    if(t[0]==t[n-1] && t[0]==0){
        cout<<"Yes";
        return;
    }

    // if(v[0]==0){
    //     cout<<"No";
    //     return;
    // }
    ll s=0,index=-1;
    repr(i,n-1,-1){
        if(v[i]!=0){
            index=i;
            break;
        }
    }
    
    rep(i,0,n){
        s+=v[i];
        if(s<0){
            cout<<"No";
            return;
        }
        if(s==0 && i<index){
            cout<<"No";
            return;
        }
    }
    if(s==0){
        cout<<"Yes";
        return;
    }
    cout<<"No";

}
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
        vl v(n,0);
        rep(i,0,n){
            cin>>v[i];
        }
        fun(n,v);
        cout << endl;
    }
    return 0;
}