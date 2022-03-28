#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
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


int main()
{
    FAST;
    // your code goes here
    ll t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vl v(n);
        rep(i,0,n){
            cin>>v[i];
        }
        if(n==1){
            cout<<"YES"<<endl;
        }
        else{
            ll s=0;
            mll m;
            rep(i,0,n){
                s+=v[i];
                m[v[i]]++;
            }
            priority_queue<ll> q;
            q.push(s);
            while(q.size()<n){
                ll t=q.top();
                q.pop();
                ll x=t/2,y=(t+1)/2;
                if(m.count(x)){
                    m[x]--,n--;
                }
                else{
                    q.push(x);
                }
                
                if(m[x]==0){
                    m.erase(x);
                }
                if(m.count(y)){
                    m[y]--,n--;
                }
                else{
                    q.push(y);
                }
                
                if(m[y]==0){
                    m.erase(y);
                }
            }
            if(q.size()==0)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;

        }
    }
     
    
    return 0;
}