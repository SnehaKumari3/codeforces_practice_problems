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
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        ll swp=0;
        
        if(s1==s2){
            cout<<"YES";
        }
        else if(n==1){
            cout<<"NO";
        }
        else{

            ll z1=0,o1=0;
            vpll cnt;
            rep(i,0,s1.length()){
                if(s1[i]=='0')
                    z1++;
                else
                    o1++;
                cnt.pb({z1,o1});
            }
            n--;
            bool ok=true;
            while(n>=0 && ok){
                if(swp%2==0){
                    if(s1[n]!=s2[n]){  
                        if(cnt[n].fi==cnt[n].se)
                            swp++;
                        else
                            ok=false;
                    }
                    
                }
                else{
                    if(s1[n]==s2[n]){
                        if(cnt[n].fi==cnt[n].se)
                            swp++;
                        else
                            ok=false;
                    }

                }
                n--;
            }

            if(ok){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
        }
        cout<<endl;
    }
    return 0;
}