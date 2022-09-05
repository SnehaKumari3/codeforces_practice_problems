#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    n=12;
    int ans=1;
    while(n>0){
        int r=n%10;
        if(r==9){
            ans=ans*2;
        }
        else{
            ans=ans*3;
        }
        n=n/10;
    }
    cout<<ans;

    return 0;
}