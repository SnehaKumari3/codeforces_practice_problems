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

ll findGCD(vector<ll> v)
{
    ll result = v[0];
    for (ll i = 1; i < v.size(); i++)
    {
        result = __gcd(v[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

bool allsame(vl v){
    rep(i,1,sz(v)){
        if(v[i]%2!=v[0]%2)
        return false;
    }
    return true;
}

int main()
{
    FAST;
    // your code goes here
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll i=0;
        ll prev=-1;
        ll ans=0;
        while(i<n){
            if(s[i]=='0'){
                if(prev!=-1){
                    ll d=i-prev;
                    if(d==1){
                        ans+=2;
                    }
                    else if(d==2){
                        ans+=1;
                    }
                }
                prev=i;
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}