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
#define pop pop_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define mem0(a) memset(a, 0, sizeof(a))
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
    ll t = 1;
    cin >> t;
    cout<<(4^6)<<endl;
    while (t--)
    {
        int64_t n, ans;
        cin >> n;
        string s;
        cin >> s;
        if (n == 1)
        {
            cout << "YES";
        }
        else if(n>=2 && s[0]!=s[1]){
            cout<<"NO";
        }
        else
        {
            ll j=n;
            if(n%2==1){
                j-=1;
            }
            bool flag = true;
            string t=s.substr(0,j);
            while(t.length()>1){
                ll sz=t.length();
                string tmp1=t.substr(0,sz/2);
                string tmp2=t.substr(sz/2);
                if(tmp1!=tmp2){
                    flag=false;
                }
                sz/=2;
                if(sz>2 && sz%2==1){
                    sz-=1;
                }
                t=t.substr(0,sz);
            }
            
            if (flag)
                cout << "YES";
            else
                cout << "NO";
        }
        cout << endl;
    }
}