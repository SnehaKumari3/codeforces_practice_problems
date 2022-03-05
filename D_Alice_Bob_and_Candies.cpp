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
        vl v(n);
        rep(i,0,n){
            cin>>v[i];
        }
        vl a(n,0),b(n,0);
        a[0]=v[0];
        b[n-1]=v[n-1];
        rep(i,1,n){
            a[i]=a[i-1]+v[i];
        }
        repr(i,n-2,-1){
            b[i]=b[i+1]+v[i];
        }
        
        ll i=0,j=n-1,cnt=1,ta=0,tb=0;
        ll sa=0,sb=0;
        bool ok=true;
        ta=a[i];
        sa=a[i];
        i++;
        while(i<=j && ok){
            if(cnt%2){
                if((b[j]-tb)>sa){
                    sb=b[j]-tb;
                    tb=b[j];
                    j--;
                    cnt++;
                }
                else{
                    while((b[j]-tb)<=sa && j>i){
                        j--;
                    }
                    if(j==i){ 
                    sb=b[j]-tb;
                    tb=b[j];
                    j--;
                    cnt++;
                    ok=false;
                    break;
                    }
                    sb=b[j]-tb;
                    tb=b[j];
                    j--;
                    cnt++;
                }
            }
            else{
                if((a[i]-ta)>sb){
                    sa=a[i]-ta;
                    ta=a[i];
                    i++;
                    cnt++;
                }
                else{
                    while((a[i]-ta)<=sb && i<j){
                        i++;
                    }
                    if(i==j){    
                        sa=a[i]-ta;
                        ta=a[i];
                        i++;
                        cnt++;
                        ok=false;
                        break;
                    }
                    sa=a[i]-ta;
                    ta=a[i];
                    i++;
                    cnt++;
                }

            }
        }
        cout<<cnt<<" "<<ta<<" "<<tb<<endl;
    }

    return 0;
}