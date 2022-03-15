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
    ll i=0;
    while(i<sz(s)-2){
        if(s[i]==s[i+1]){
            for(char ch='a';ch<='z';ch++){
                if(ch!=s[i+2] && ch!=s[i]){
                    s[i+1]=ch;
                    break;
                }
            }
        }
        i++;
    }
    ll l=sz(s);
    if(s[l-1]==s[l-2] && l-2>=0){
        for(char ch='a';ch<='z';ch++){
                if(ch!=s[l-1]){
                    s[l-1]=ch;
                    break;
                }
            }
    }
    cout<<s;
    
    return 0;
}