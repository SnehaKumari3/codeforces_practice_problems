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
    ll a, b;
    cin >> a >> b;
    string ans = "";
    if (b >= a)
    {
        if (b - a >= 1)
        {
            ans += "110";
            b -= 2, a -= 1;
        }
        else
        {
            ans += "10";
            b -= 1, a -= 1;
        }
    }
    else
    {
        ans += "01";
        b -= 1, a -= 1;
    }
    
    while (a > 0 && b > 0)
    {
        ll j = sz(ans) - 1;
        if (ans[j] == '0')
        {
            if (b - a >= 1)
            {
                ans += "110";
                b -= 2, a -= 1;
            }
            else
            {
                ans += "10";
                b -= 1, a -= 1;
            }
        }
        else
        {
            ans += "01";
            b -= 1, a -= 1;
        }
    }
    bool ok = true;
    ll j = sz(ans) - 1;

    if(a>0){
        if(ans[j]=='1'&& a==1){
            ans+="0";
            a--;
        }
        else
        ok=false;
    }
    
    if(b>0){
        if(b==1){
            ans+="1";
            b--;
        }
        else if(b==2){
            ans+="11";
            b-=2;
        }
        else{
            ok=false;
        }
    }
    
    if (ok)
        cout << ans;
    else
        cout << -1;
    return 0;
}