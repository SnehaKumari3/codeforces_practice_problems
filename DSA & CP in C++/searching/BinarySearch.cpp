#include<iostream>
using namespace std;

int main()
{
    int a[5];
    cout<<"enter the 5 elements of the array: ";
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    int key,temp=0;
    cout<<"enter the element you want to searh: ";
    cin>>key;
    int first=0,last=4;
    int mid;
    while(first<=last){
        mid=(first+last)/2;
        if(a[key]==a[mid]){
            break;
        }
        else if(a[key]<a[mid]){
            last=mid-1;
        }
        else{
            first=mid+1;
        }
    }
    cout<<"elment found at "<<mid<<" index"<<endl;

    return 0;
}