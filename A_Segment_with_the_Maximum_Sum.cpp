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

struct Node
{
    long long pre=0, suf=0, sum=0, ans=0;
};

const int N = 100002;
long long a[N];
Node Tree[4 * N];

void construct(int node, int start, int end)
{
    if (start == end)
    {
        if (a[start] <= 0)
        {
            Tree[node].pre = 0;
            Tree[node].suf = 0;
            Tree[node].sum = a[start];
            Tree[node].ans = 0;
        }
        else
        {
            Tree[node].pre = a[start];
            Tree[node].suf = a[start];
            Tree[node].sum = a[start];
            Tree[node].ans = a[start];
        }
        return;
    }

    int mid = (start + end) / 2;
    construct(2 * node + 1, start, mid);
    construct(2 * node + 2, mid+1, end);

    long long summ = Tree[2 * node + 1].sum + Tree[2 * node + 2].sum;
    long long pref = max(Tree[2 * node + 1].pre, Tree[2 * node + 1].sum + Tree[2 * node + 2].pre);
    long long suff = max(Tree[2 * node + 2].suf, Tree[2 * node + 2].sum + Tree[2 * node + 1].suf);
    long long anss = max(Tree[2 * node + 1].suf + Tree[2 * node + 2].pre, Tree[2 * node + 1].ans);
    anss = max(anss, Tree[2 * node + 2].ans);

    Tree[node].pre = pref;
    Tree[node].suf = suff;
    Tree[node].sum = summ;
    Tree[node].ans = anss;
}


void update(int node, int start, int end,int index,int val)
{
    if (start == end)
    {
        if (a[start] <= 0)
        {
            Tree[node].pre = 0;
            Tree[node].suf = 0;
            Tree[node].sum = a[start];
            Tree[node].ans = 0;
        }
        else
        {
            Tree[node].pre = a[start];
            Tree[node].suf = a[start];
            Tree[node].sum = a[start];
            Tree[node].ans = a[start];
        }
        return;
    }

    int mid = (start + end) / 2;
    if(index <= mid)
    update(2 * node + 1, start, mid,index,val);
    else
    update(2 * node + 2, mid+1, end,index,val);

    long long summ = Tree[2 * node + 1].sum + Tree[2 * node + 2].sum;
    long long pref = max(Tree[2 * node + 1].pre, Tree[2 * node + 1].sum + Tree[2 * node + 2].pre);
    long long suff = max(Tree[2 * node + 2].suf, Tree[2 * node + 2].sum + Tree[2 * node + 1].suf);
    long long anss = max(Tree[2 * node + 1].suf + Tree[2 * node + 2].pre, Tree[2 * node + 1].ans);
    anss = max(anss, Tree[2 * node + 2].ans);

    Tree[node].pre = pref;
    Tree[node].suf = suff;
    Tree[node].sum = summ;
    Tree[node].ans = anss;
}

int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        rep(i, 0, n)
        {
            cin >> a[i];
        }

        construct(0,0,n-1);
        cout<<Tree[0].ans<<endl;
        while(q--){
            long long index,key;
            cin>>index>>key;
            a[index]=key;
            update(0,0,n-1,index,key);
            cout<<Tree[0].ans<<endl;
        }
        
    }
}