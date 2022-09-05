#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
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


bool isPalid(ll n){
    string s="";
    while(n>0){
        s+=to_string(n%10);
        n/=10;
    }
    
    rep(i,0,(sz(s)+1)/2){
        if(s[i]!=s[sz(s)-1-i]){
            return false;
        }
    }
    return true;
}

string fun1(ll d){
    string num="1";
    while(d>0){
        num+='0';
        d--;
    }
    return num;
}
string fun2(ll d){
    string num="9";
    while(d>0){
        num+='9';
        d--;
    }
    return num;
}

int main()
{
    FAST;
    // your code goes here
    ll t=1;
    cin >> t;
    while (t--)
    {
        ll s;
        string n;
        cin>>s>>n;
        string mn=fun1(s-1);
        string mx=fun2(s-1);
        cout<<mn<<" "<<mx<<endl;
        for(ll i=mn;i<=mx;i++){
            string tmp=add_str(n,i);
            if(isPalid(tmp)){
                cout<<i;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}