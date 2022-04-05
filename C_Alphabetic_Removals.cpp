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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vl v(26,0),t(26,0);
    rep(i,0,n){
        v[s[i]-'a']+=1;
    }
    ll i=0;
    while(k>0){
        if(v[i]>0){
            t[i]=min(k,v[i]);
            k-=t[i];
        }
        i++;
    }
    rep(j,0,n){
        if(t[s[j]-'a']>0){
            t[s[j]-'a']-=1;
        }
        else{
            cout<<s[j];
        }
    }
    return 0;
}