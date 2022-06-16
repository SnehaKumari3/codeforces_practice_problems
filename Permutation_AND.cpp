#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<pair<p64,ll>> vpp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
typedef map<ll,ll> m64;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size()) 
 ll nearest_power_of_2(ll n)
{
    ll x=n&n-1;
    while(x)
    {
        x=n&n-1;

        if(x==0)
        return n;

        n=n&n-1;
    }
    return n;
}
ll lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}
 
void Gyani()  
{   
    
    ll a,b,c;
    ll n;
    cin>>n;
    v64 v,v1;
    if(n==1)
    cout<<"1\n1\n";
    else
    if(n%2==1)
    cout<<"-1\n";
    else
    {
        ll i=n;
        while(i>=1)
        {
            ll n=i;
            ll x=nearest_power_of_2(n);
            cout<<i<<" "<<x<<endl;
            x=x*2-1; 
            ll y=x^n;
            while(i>=y&&i>=1)
            {
                v.pb(i);
                ll p=i^x;
                v1.pb(p); 
                i--;
            } 
        }
        forn(i,n)
        cout<<v[i]<<" ";
        cout<<endl;
        forn(i,n)
        cout<<v1[i]<<" ";
        cout<<endl;
    }
} 
 
int main()
{
	fast_cin(); 
	 ll t=1; 
 	cin >> t; 
	while(t--){
         // cout<<"Case#i: ";
		Gyani();
	     }
	return 0;
}