#include <bits/stdc++.h>
#include <algorithm>
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

bool palid(string s)
{
    ll i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j] && s[i] != '?')
        {
            return false;
        }
        i++, j--;
    }
    return true;
}
bool cnt(string s, ll a, ll b)
{
    rep(i, 0, sz(s))
    {
        if (s[i] == '0')
            a--;
        else
            b--;
    }
    if (a == 0 && b == 0)
        return true;
    return false;
}

int main()
{
    FAST;
    // your code goes here
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vl e,o;
        ll s1=0,s2=0;
        rep(i,0,n){
            ll a;
            cin>>a;
            if(a%2){
                o.pb(a);
                s1+=a;
            }
            else{
                e.pb(a);
                s2+=a;
            }
        }
        sort(all(e));
        sort(all(o));
        reverse(all(e));
        reverse(all(o));
        ll i=0,j=0,cnt=0;
        while(i<sz(e) && j<sz(o) && s1>0 && s2>0){
            if(cnt%2==0){
                if(s2>s1){
                    
                }
            }
        }

    }
    return 0;
}