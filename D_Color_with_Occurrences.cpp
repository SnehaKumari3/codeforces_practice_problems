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

int n,ans,r,res[101][2];
string s,a[11];
int main()
{
    FAST;

    ll t = 1;
    cin >> t;
    while (t--)
    {
        ans=0,r=0;
        cin>>s>>n;
        rep(i,0,n){
            cin>>a[i];
        }
        while(r<s.length()){
            int lr=r;
            for(int i=0;i<=lr && r<s.length();i++){
                for(int k=0;k<n;++k){
                    bool ok=1;
                    if(i + a[k].size()>s.length() || i+a[k].size()<=r){
                        ok=0;
                    }

                    if(ok){
                        for(int j=0;j<a[k].size() && ok;j++){
                            if(s[i+j]!=a[k][j]) ok=0;
                        }
                    }
                    if(ok){
                        r=i+a[k].size();
                        res[ans][0]=k+1;
                        res[ans][1]=i+1;
                    }

                }
            }

            if(lr==r){
                break;
            }
            ++ans;

        }

        if(r<s.length()){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
            rep(i,0,ans){
                cout<<res[i][0]<<" "<<res[i][1]<<endl;
            }
        }
    }

    return 0;
}