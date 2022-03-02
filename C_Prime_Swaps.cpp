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

ll n;
vector<bool> is_prime(n+1, true);
void sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
        }
    }
}

bool isSort(vl v){
    rep(i,2,sz(v)){
        if(v[i]<v[i-1])
        return false;
    }
    return true;
}
int main()
{
    FAST;
    // your code goes here
    cin>>n;
    sieve();
    vl v(n+1);
    rep(i,0,n)
    cin>>v[i+1];
    if(isSort(v))
    cout<<0;
    else{
        vpll ans;
        bool okay=false;
        while(!okay){
            rep(i,1,n){
                if(v[i]==i){
                    continue;
                }
                else{
                    ll tmp=v[i]-i+1;
                    if(is_prime[tmp]==true){
                        ans.pb({i,v[i]});
                        ll t1=v[v[i]];
                        v[v[i]]=v[i];
                        v[i]=t1;
                        i--;
                    }
                    else{
                        ll k=i;
                        repr(j,v[i],i){
                            if(is_prime[j-i+1] && is_prime[v[i]-j+1]){
                                k=j;
                                break;
                            }
                        }
                        ans.pb({i,k});
                        ans.pb({k,v[i]});
                        ll tmp=v[i];
                        ll tmp1=v[k];
                        v[k]=v[v[i]];
                        v[v[i]]=tmp;
                        v[i]=tmp1;
                    }
                }
            }
            okay=isSort(v);
        }
        cout<<sz(ans)<<endl;
        rep(i,0,sz(ans))
        cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    }
    return 0;
}