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

bool issort(vl v){
    rep(i,1,sz(v)){
        if(v[i]<=v[i-1]){
            return false;
        }
    }
    return true;
}

int main()
{
    FAST;
    // your code goes here
    ll n,k;
    cin>>n>>k;
    vl v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    sort(all(v));
    if(issort(v)){
        cout<<v[n/2]+k;
    }
    else{
        ll d;
        rep(i,n/2,n-1){
            d=v[i+1]-v[i];
            if(d<=k){
                k-=d;
                v[i]+=d;
            }
            else{
                break;
            }
        }
        ll cnt=0;
        while(k>0){
            if(k>=(n/2)+1){
                cnt++;
                k-=(n/2+1);
            }
            else{
                ll j=n/2;
                while(k-- && j<n){
                    v[j++]+=1;
                }
            }
        }
        sort(all(v));
        cout<<v[n/2]+cnt;
    }
    return 0;
}