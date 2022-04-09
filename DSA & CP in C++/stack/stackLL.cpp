#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(int n){
        data=n;
        next=NULL;
    }

};
class StackUsingLinkedList{
    public:
    Node* head;
    int top=-1;
    StackUsingLinkedList(){
        head=NULL;
        top=-1;
    }
    StackUsingLinkedList(Node* n){
        head=n;
        top=-1;
    }
    bool isEmpty(){
        if(head==NULL)
            return true;
        else
            return false;
    }
    void PushInStack(Node* n){
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        top++;
    }
    void PopInStack(){
        if(isEmpty() == NULL){
            cout<<"STACK IS EMPTY. NOTHING TO POPOUT!"<<endl;
        
        }
        else{
            Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        int popval=temp->next->data;
        temp->next=NULL;
        top--;
        cout<<"popped value is "<<popval<<endl;
        }
    }
    void DisplayStack(){
        if(isEmpty()==NULL){
            cout<<"STACK IS EMPTY. NOTHING TO DISPLAY!"<<endl;
        }
        else{
            Node* temp=head;
            cout<<"Stack elements are: ";
            while(temp != NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<endl;
        }
    }
    int countStack(){
        return top+1;
    }
};
int main()
{
    int data1,option;
    StackUsingLinkedList s1;
    do{
        cout<<"Enter the operaton number you want to perform. Enter 0 to exit."<<endl;
        cout<<"1. push()"<<endl;
        cout<<"2. pop()"<<endl;
        cout<<"3. display()"<<endl;
        cout<<"4. isEmpty()"<<endl;
        cout<<"5. clearScreen()"<<endl;
        cout<<"6. countStack()"<<endl;
        cout<<"Enter choice: ";
        cin>>option;
        Node* n1=new Node();
        switch(option){
            case 0:
                break;
            case 1:
                    cout<<"Enter the value you want to push: ";
                    cin>>data1;
                    n1->data=data1;
                    s1.PushInStack(n1);
                    break;
            case 2:
                s1.PopInStack();
                break;
            case 3:
                s1.DisplayStack();
                break;
            case 4:
                if(s1.isEmpty()){
                cout<<"STACK IS EMPTY."<<endl;
                 }
                else{
                cout<<"STACK IS NOT EMPTY."<<endl;
                }
                break;
            case 5:
                system("cls");
                break;
            case 6:
                cout<<"number of node is "<<s1.countStack()<<endl;
                break;
            default:
                cout<<"wrong input"<<endl;
        }


    }while(option!=0);
    cout<<"thank you!";
    
    return 0;
}