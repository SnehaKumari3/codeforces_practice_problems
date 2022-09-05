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

int main()
{
    FAST;
    // your code goes here

    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll a,b;
        cin >> a>> b;
        map<char,ll> m;
        ll d,r;
        m['0']=a;
        m['1']=b;
        if(a<=b){
            d=b/(a+1);
            r=b%(a+1);
        }
        else{
            d=a/(b+1);
            r=a%(b+1);
        }

        string s="";
        for(ll i=0;i<(a+b);){
            ll tmp=d;
            if(r>0){
                tmp+=1;
            }

            if(a<=b){
                for(ll j=0;j<tmp && i<(a+b);j++){
                    s+='1';
                    i++;
                }
                if(i<(a+b)){
                    s+='0',i++;
                }
                
            }
            else{
                for(ll j=0;j<tmp && i<(a+b);j++){
                    i++;
                    s+='0';
                }
                if(i<(a+b)){
                    s+='1',i++;
                }
            }
            r--;
        }
        cout<<s;

        cout << endl;
    }
    return 0;
}