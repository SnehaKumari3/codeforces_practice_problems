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
        vl v1(n);
        vl v2(n);
        rep(i,0,n){
            cin>>v1[i];
        }
        rep(i,0,n){
            cin>>v2[i];
        }
        sort(all(v1),greater<int>());
        sort(all(v2),greater<int>());
        rep(i,1,n){
            v1[i]+=v1[i-1];
        }
        rep(i,1,n){
            v2[i]+=v2[i-1];
        }
        ll t1=n-n/4;
        ll t2=t1;
        t1--;
        t2--;
        ll num=n;
        if(v1[t1]>=v2[t2]){
            cout<<0;
        }
        else{
            ll s1=0,s2=0;
            while(v1[t1]+s1<v2[t2]){
                s1+=100;
                n++;
                if(n%4==0){
                    if(t1!=0){
                        t1--;
                    }
                    else{
                        v1[0]=0;
                        t1=0;
                    }
                }
                else{
                    if(t2!=num-1){
                        t2++;
                    }
                }

            }
            cout<<n-num;
        }
        cout<<endl;
    }

    return 0;
}