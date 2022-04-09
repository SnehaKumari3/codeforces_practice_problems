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
    for(int i=0;i<5;i++){
        if(key==a[i]){
            cout<<"elment is found at "<<i+1<<" position."<<endl;
            temp=1;
            break;
        }
    }
    if(temp==0){
        cout<<"element not found!"<<endl;
    }
    return 0;
}