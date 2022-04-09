#include<iostream>
#include<bits/stdc++.h>
#define lli long long int 
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ff first
#define ss second
#define endl '\n'
#define mod (int)1e9+7
using namespace std;


lli dp[1000001],inv[1000001];
lli power(lli a,lli n){
    lli res=1;
    while(n){
        if(n&1){
            res=(res*a)%mod;
        }
        n>>=1;
        a=(a*a)%mod;
    }
    return res;
}
void init(string s){
    
    lli p=31;
    lli p_power=1;
    inv[0]=1;
    dp[0]=(s[0]-'a'+1);

    for(int i=1;i<s.size();i++){
        char ch=s[i];
        p_power=(p_power*p)%mod;
        inv[i]=power(p_power,mod-2);
        dp[i]=(dp[i-1]+(ch-'a'+1)*p_power)%mod;
    }
}

lli substringHash(int L,int R){
    int res=dp[R];
    if(L>0){
        res=(res-dp[L-1]+mod)%mod;
       
    }
    res=(res*inv[L])%mod;
    return res;
}


int main(){
    string in_s;
    int t,L,R;
    cin>>in_s;
    init(in_s);
    cin>>t;
    while(t--){
        cin>>L>>R;
        cout<<substringHash(L,R)<<endl;
    }
}