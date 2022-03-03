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

ll fac(ll n)
{
    
    return (n==1 || n==0) ? 1: n * fac(n-1);
}

int main()
{
    FAST;
    // your code goes here
    ll n;
    cin>>n;
    ll k1;
    cin>>k1;
    queue<ll> q1,q2;
    queue<ll> t1,t2;
    rep(i,0,k1){
        ll t;
        cin>>t;
        q1.push(t);
        t1.push(t);
    }
    cin>>k1;
    rep(i,0,k1){
        ll t;
        cin>>t;
        q2.push(t);
        t2.push(t);
    }
    ll c1=0,c2=0;
    bool ok=true;
    while(!t1.empty() && !t2.empty() && ok){
        ll n1=t1.front();
        ll n2=t2.front();
        t1.pop();
        t2.pop();
        if(n1>n2){
            t1.push(n2);
            t1.push(n1);
            c1++;
        }
        else{
            t2.push(n1);
            t2.push(n2);
            c2++;
        }
        
        if((c1+c2)==fac(n+1)){
            ok=false;
        }
    }

    if(ok){
        if(c1>c2){
            cout<<c1+c2<<" "<<1;
        }
        else{
            cout<<c1+c2<<" "<<2;
        }
    }
    else{
        cout<<-1;
    }

    return 0;
}