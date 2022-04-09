#include<iostream>
using namespace std;

class Stack{
    public:
    int count;
    int a[5];
    Stack(){
        for(int i=0;i<5;i++){
            count=-1;
            a[i]=0;
        }
    }
    bool isEmpty(){
        if(count==-1){
            return true;
        }
        else 
        return false;
    }
    bool isFull(){
        if(count==4){
            return true;
        }
        else 
        return false;
    }

    void push(int val){
        if(isFull()){
            cout<<"stack is full"<<endl;
        }
        else{
            count++;
            a[count]=val;
            cout<<"value pushed."<<endl;
        }
    }
    int pop(){
        if(isEmpty()){
            cout<<"stack is empty, nothing to delete."<<endl;
            return 0;
        }
        else{
            int x=a[count];
            a[count]=0;
            count--;
            cout<<"value poped."<<endl;
            return x;
        }
    }
    int search(int data){
        int c=-1;
        for(int i=0;i<count;i++){
            if(a[i]==data)
            c=i;
        }
        return c;
    }
    int Count(){
        return count+1;
    }
    void display(){
        cout<<"displaying the elment:"<<endl;
        for(int i=0;i<5;i++){
            cout<<a[i]<<" ";
        }
    }
};
int main()
{
    Stack s1;
    int option,key,value;
    do{
        cout<<"\nwhich operation you want to perform? select the option. enter 0 to exts."<<endl;
        cout<<"1. push()"<<endl;
        cout<<"2. pop()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. search()"<<endl;
        cout<<"6. count()"<<endl;
        cout<<"7. display()"<<endl;
        cout<<"8. clearScreen()"<<endl;

        cin>>option;
        switch(option){
            case 0:
            break;
            case 1:
            cout<<"enter an element to push: ";
            cin>>value;
            s1.push(value);
            break;
            case 2:
            cout<<"popped element is: "<<s1.pop()<<endl;
            break;
            case 3:
            if(s1.isEmpty()){
                cout<<"stack is empty"<<endl;
            }
            else{
                cout<<"stack is not empty"<<endl;
            }
            break;
            case 4:
            if(s1.isFull()){
                cout<<"stack is full"<<endl;
            }
            else{
                cout<<"stack is not full"<<endl;
            }
            break;
            case 5:
            cout<<"enter the element you want to search: ";
            cin>>key;
            cout<<"element is found at index "<<s1.search(key)<<endl;
            break;
            case 6:
            cout<<"total no of element is "<<s1.Count()<<endl;
            break;
            case 7:
            s1.display();
            break;
            case 8:
            system("cls");
            break;
            default:
            cout<<"wrong input"<<endl;
        }

    }while(option!=0);
    cout<<"thank you !"<<endl;
    return 0;
}