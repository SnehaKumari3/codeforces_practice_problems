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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string s, ans;
        cin >> s;
        ans = s;
        ll cnt = 0;
        vl c(n, 0);
        rep(i, 0, n)
        {
            if (i < (n - k + 1))
            {
                if (i == 0)
                {
                    if (s[i] == '1')
                    {
                        cnt++;
                    }
                }
                else
                {
                    ll tmp = c[i - 1];
                    if (i - k >= 0)
                    {
                        tmp -= c[i - k];
                    }

                    if (tmp % 2)
                    {
                        if (s[i] == '0')
                        {
                            cnt++;
                        }
                    }
                    else
                    {
                        if (s[i] == '1')
                        {
                            cnt++;
                        }
                    }
                }
            }

            c[i] = cnt;
        }

        rep(i, 0, n)
        {
            ll tmp=c[i];
            if(i-k>=0){
                tmp-=c[i-k];
            }

            if(tmp%2){
                if(s[i]=='1'){
                    cout<<"0";
                }
                else{
                    cout<<"1";
                }
            }
            else{
                cout<<s[i];
            }
            
        }
        
        cout << endl;
    }

    return 0;
}