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

bool isPrime(ll n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    rep(i, 2, n)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FAST;
    // your code goes here
    string s;
    cin >> s;
    map<char, ll> m;
    ll mn = 2, cnt = 0;
    vl p;
    rep(i, 0, sz(s))
    {
        if (isPrime(i + 1))
        {
            if((i+1)*2>s.length()){
                p.pb(i+1);
            }
            else{
                cnt+=1;
            }
        }
        else if(i>0){
            cnt+=1;
        }
        m[s[i]]++;
    }
    
    
    char ch;
    bool ok = false;
    for (auto j : m)
    {
        if (j.se >= cnt)
        {
            ch = j.fi;
            ok = true;
            m[j.fi]= j.se - cnt;
            break;
        }
    }

    if (ok)
    {
        vector<char> ans(s.length()+1,'#');
        cout<<"YES"<<endl;
        rep(i,2,sz(ans)){
            if(count(all(p),i)==0){
                ans[i]=ch;
            }
        }
        ll j=1;
        
        for(auto i:m){
            ll t=i.se;
            while(t--){

                while(j<s.length()+1 && ans[j]!='#'){
                    j++;
                }
                if(j<s.length()+1)
                ans[j]=i.fi;
                j++;
            }
        }

        rep(i,1,s.length()+1){
            cout<<ans[i];
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}