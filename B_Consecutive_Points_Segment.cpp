#include <bits/stdc++.h>
#include <algorithm>
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
#define INF 10007

bool valid(vl v){
    rep(i,1,v.size()){
        if(v[i]-v[i-1]!=1){
            return false;
        }
    }
    return true;
}
int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vl v(n);
        rep(i,0,n){
            cin>>v[i];
        }
        if(valid(v)){
            cout<<"YES";
        }
        else{
            vl ans;
            rep(i,1,n){
                ans.pb(v[i]-v[i-1]);
            }
            ll m=*max_element(all(ans));
            if(m>3){
                cout<<"NO";
            }
            else if(m==3){
                ll cnt1=count(all(ans),3);
                ll cnt2=count(all(ans),2);
                if(cnt1>1){
                    cout<<"NO";
                }
                else if(cnt2>0 && cnt1>0){
                    cout<<"NO";
                }
                else{
                    cout<<"YES";
                }
            }
            else if(m==2){
                ll cnt=count(all(ans),2);
                if(cnt>2){
                    cout<<"NO";
                }
                else{
                    cout<<"YES";
                }
            }
            else{
                cout<<"YES";
            }
        }
        
        cout<<endl;
    }
    return 0;
}