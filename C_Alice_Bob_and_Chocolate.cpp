#include <bits/stdc++.h>
#include <cmath>
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

ll find(ll n)
{
    ll cnt = 0;
    while (n % 2 == 0)
    {
        cnt++;
        n /= 2;
        if (cnt >= 15)
        {
            return 15;
        }
    }
    return cnt;
}

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vl v(n);
        rep(i,0,n){
            cin>>v[i];
        }
        ll i=0,j=n-1,t1=0,t2=0,c1=0,c2=0;
        while(i<=j){
            if(t1==t2){
                if(i==j){
                    t1+=v[i];
                    c1++;
                    i++;
                }
                else{
                    t1+=v[i];
                    t2+=v[j];
                    i++,j--;
                    c1++,c2++;
                }
            }
            else if(t1>t2){
                t2+=v[j];
                j--,c2++;
            }
            else{
                t1+=v[i];
                i++,c1++;
            }
        }
        cout<<c1<<" "<<c2;
    }
    return 0;
}