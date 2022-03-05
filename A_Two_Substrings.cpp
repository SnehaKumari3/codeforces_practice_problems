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

    string str1 = "AB";
    string str2 = "BA";
    ll pos = 0;
    ll index;
    vl a,b;
    while((index = s.find(str1, pos)) != string::npos) {
        a.pb(index);
        pos = index + 1; 
    }
    pos=0;
    while((index = s.find(str2, pos)) != string::npos) {
        b.pb(index);
        pos = index + 1; 
    }

    if(sz(a)==0 || sz(b)==0){
        cout<<"NO";
    }
    else{
        ll t1=*min_element(all(a));
        ll t2=*max_element(all(a));
        ll t3=*min_element(all(b));
        ll t4=*max_element(all(b));
        if((t4-t1)>1){
            cout<<"YES";
        }
        else if((t2-t3)>1){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
    return 0;
}