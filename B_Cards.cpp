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
    // cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;
        string s;
        cin >> s;
        map<char, ll> m;
        rep(i, 0, n)
        {
            m[s[i]]++;
        }

        if (m.size() == 1)
        {
            cout << s[0];
        }
        else if (m.size() == 2)
        {
            ll a = 0, b = 0;
            string t = "";
            for (auto j : m)
            {
                t += j.fi;
                if (j.se == 1)
                {
                    if (a == 0)
                    {
                        a = 1;
                    }
                    else
                    {
                        b = 1;
                    }
                }
                if (j.se >= 2)
                {
                    if (a == 0)
                    {
                        a = 2;
                    }
                    else
                    {
                        b = 2;
                    }
                }
            }
            if (a == 1 && b == 1)
            {
                if (t == "BG")
                {
                    cout << "R";
                }
                else if (t == "GR")
                {
                    cout << "B";
                }
                else
                {
                    cout << "G";
                }
            }
            else if (a == 2 && b == 2)
            {
                cout<<"BGR";
            }
            else
            {
                string res="";
                if (t == "BG")
                {
                    res+="R";
                    if (m['B'] == 1)
                    {
                        res+= "B";
                    }
                    else
                    {
                        res+="G";
                    }
                }
                else if (t == "GR")
                {
                    res+="B";
                    if (m['G'] == 1)
                    {
                        res+="G";
                    }
                    else
                    {
                        res+="R";
                    }
                }
                else
                {
                    res+="G";
                    if (m['B'] == 1)
                    {
                        res+= "B";
                    }
                    else
                    {
                        res+= "R";
                    }
                }
                sort(all(res));
                cout<<res;
            }
        }
        else
        {
            cout<<"BGR";
        }
        cout << endl;
    }

    return 0;
}