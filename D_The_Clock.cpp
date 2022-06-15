#include <bits/stdc++.h>
#include <string>
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

    ll t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n;
        cin >> n;
        ll h = n / 60;
        ll m = n % 60;
        ll cnt = 0;
        string t1 = "";
        t1 += s[0];
        t1 += s[1];
        int H = stoi(t1);
        string t2 = "";
        t2 += s[3];
        t2 += s[4];
        int M = stoi(t2);
        if (t1.length() == 1)
        {
            t1 = "0" + t1;
        }
        if (t2.length() == 1)
        {
            t2 = "0" + t2;
        }
        map<pair<int, int>,int> ans;
        reverse(all(t2));
        if(t1==t2){

            cnt++;
        }
        
        bool ok=true;
        int time[24][60]={0};
        while(time[H][M]==0)
        {
            time[H][M]=1;
            int h1 = (H + h) % 24;
            int m1;
            if (m >= (60 - M))
            {
                h1 =(h1 + 1) % 24;
                m1 = m - (60 - M);
            }
            else
            {
                m1 = M + m;
            }
            string t1 = to_string(h1);
            string t2 = to_string(m1);
            if (t1.length() == 1)
            {
                t1 = "0" + t1;
            }
            if (t2.length() == 1)
            {
                t2 = "0" + t2;
            }
            
            reverse(all(t2));
            if (t1 == t2 && time[h1][m1]==0)
            {
                cnt++;
            }
            H = h1, M = m1;
        }

        cout << cnt;
        cout << endl;
    }
    return 0;
}