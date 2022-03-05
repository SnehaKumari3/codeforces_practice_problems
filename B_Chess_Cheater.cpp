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

ll score(string s){
    ll ans=0;
    if(s[0]=='W'){
        ans+=1;
    }
    rep(i,1,s.length()){
        if(s[i]=='W' && s[i-1]=='W')
        ans+=2;
        else if(s[i]=='W' && s[i-1]=='L')
        ans+=1;
    }
    return ans;
}

int main()
{
    FAST;
    // your code goes here
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        
        ll w=0,l=0;
        rep(i,0,n){
            if(s[i]=='L'){
                l++;
            }
            else{
                w++;
            }
        }

        if(k==0){
            cout<<score(s);
        }
        else if(l<=k){
            cout<<1+2*(n-1);
        }
        else if(w==0){
            cout<<1+2*(k-1);
        }
        else{
            ll ans=score(s);
            l=0;
            ll index=-1;
            vl v1;
            rep(i,0,n){
                if(s[i]=='W'){
                    index=i;
                    break;
                }
            }
            
            rep(i,index+1,n){
                if(s[i]=='L'){
                    l++;
                }
                else{
                    if(l>0){
                        v1.pb(l);
                        l=0;
                    }
                }
            }
            ll key=l;
            sort(all(v1));
            rep(i,0,sz(v1)){
                
                if(v1[i]<=k && v1[i]>0){
                    ans+=(2*v1[i])+1;
                    k-=v1[i];
                }
                else{
                    ans+=(2*k);
                    k=0;
                }
                if(k==0){
                    break;
                }
            }
            if(k>0){
                key=min(key,k);
                ans+=2*key;
                k-=key;
            }
            if(k>0){
                ans+=(2*k);
            }
            cout<<ans;
        }
        cout<<endl;
    }

    return 0;
}