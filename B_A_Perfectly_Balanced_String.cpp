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
#define INF 10007

int main()
{
    FAST;
    // your code goes here
    ll t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        map<char, ll> m;
        rep(i, 0, s.length())
        {
            m[s[i]]++;
        }
        bool ok = true;
        rep(i, 1, s.length())
        {
            if (s[i] == s[i - 1])
            {
                ok = false;
                break;
            }
        }
        if (m.size() == 1 || s.length() == 2)
        {
            cout << "YES";
        }
        else if (s.length() == m.size())
        {
            cout << "YES";
        }
        else if(ok){
            vl v(26,0);
            rep(i,0,s.length()){
                v[s[i]-'a']+=1;
                ll mx=0,mn=s.length()+1;
                for(auto i:m){
                    if(v[i.fi-'a']<mn){
                        mn=v[i.fi-'a'];
                    }
                    if(v[i.fi-'a']>mx){
                        mx=v[i.fi-'a'];
                    }
                }
                if(mx-mn>1){
                    ok=false;
                    break;
                }
            }
            if(ok){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
        }
        else{
            cout<<"NO";
        }

        cout << endl;
    }
    return 0;
}