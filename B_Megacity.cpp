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
bool compare(vl v1,vl v2){
    return (v1[0]*v1[0] + v1[1]*v1[1])<(v2[0]*v2[0] + v2[1]*v2[1]);
}

int main()
{
    FAST;
    // your code goes here
    ll n,s,sum=0;
    cin>>n>>s;
    vvl v;
    rep(i,0,n){
        ll a,b,c;
        cin>>a>>b>>c;
        sum+=c;
        a=abs(a),b=abs(b),c=abs(c);
        vl v1;
        v1.pb(a);
        v1.pb(b);
        v1.pb(c);
        v.pb(v1);;
    }
    sort(all(v),compare);
    if((s+sum)<1000000){
        cout<<-1;
    }
    else{
        ll j,k;
        rep(i,0,n){
            s+=v[i][2];
            if(s>=(1000000)){
                j=v[i][0];
                k=v[i][1];
                break;
            }
        }

        ld ans=j*j + k*k;
        ans=sqrt(ans);
        cout << fixed << setprecision(7) << ans;
    }

    return 0;
}