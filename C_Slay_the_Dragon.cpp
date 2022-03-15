#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;


#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

long long int search(long long int ar[],long long int l,long long int h,long long int e,long long int c)
{
    long long int r=e;
    while(l<=h)
    {
        long long int mid=l+(h-l)/2;
        if(ar[mid]>=c)
        {
            r=min(r,mid);
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return r;   
}

int main()
{
    FAST;
    long long int n;
    cin>>n;
    long long int ar[n];
    long long int sum=0;
    for(long long int i=0;i<n;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }
    sort(ar,ar+n);
    long long int m;
    cin>>m;
    for(long long int i=0;i<m;i++)
    {
        long long int s,l;
        long long int cnt=0;
        cin>>s>>l;
        long long int ind=search(ar,0,n,n,s);
        if(ind==0)
        {
            
            if(s>ar[ind])
            {
                cnt+=s-ar[ind];
            }
            if(l>(sum-ar[ind]))
            {
                cnt+=(l-(sum-ar[ind]));
            }
        }
        else if(ind==n)
        {
            if(s>ar[ind-1])
            {
                cnt+=s-ar[ind-1];
            }
            if(l>(sum-ar[ind-1]))
            {
                cnt+=(l-(sum-ar[ind-1]));
            }
        }
        else
        {
            long long int cnt1=0,cnt2=0;
            if(s>ar[ind])
            {
                cnt1+=s-ar[ind];
            }
            if(l>(sum-ar[ind]))
            {
                cnt1+=(l-(sum-ar[ind]));
            }
            if(s>ar[ind-1])
            {
                cnt2+=s-ar[ind-1];
            }
            if(l>(sum-ar[ind-1]))
            {
                cnt2+=(l-(sum-ar[ind-1]));
            }
            cnt=min(cnt1,cnt2);
        }
        cout<<cnt<<endl;
    }
}