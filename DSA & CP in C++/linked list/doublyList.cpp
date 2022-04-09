#include<iostream>
using namespace std;

class Node{
    public:
        int key,data;
        Node* next;
        Node* prev;
    Node(){
        key=0;
        data=0;
        next=NULL;
        prev=NULL;
    }
    Node(int k,int d){
        key=k;
        data=d;
        next=NULL;
        prev=NULL;
    }
};
class doublyLinkedList{
    public:
    Node* head;
    doublyLinkedList(){
        head=NULL;
    }
    doublyLinkedList(Node* n){
        head=n;
    }

    //node exits
    Node* nodeExists(int k){
        Node* temp =NULL;
        Node* prev=head;
        while(prev!=NULL){
            if(prev->key==k){
                temp=prev;
            }
            prev=prev->next;
        }
        return temp;
    }
    //append a node
    void appendNode(Node* n){
        if(nodeExists(n->key)!=NULL){
                cout<<"node already exits with this key value."<<endl;
            }
         else{
                 Node* temp=head;
                if(head==NULL){
                 head=n;
                 cout<<"node appended"<<endl;
                 }
                 else{
                     while(temp->next!=NULL){
                    temp=temp->next;
                }
                 temp->next=n;
                 n->prev=temp;
                 } 
            }
    }
    //prepend node at the start
    void prependNode(Node* n){
        if(nodeExists(n->key) != NULL){
            cout<<"node already exits with this key value."<<endl;
        }
        else{
             Node* temp=head;
                if(head==NULL){
                 head=n;
                 cout<<"node appended"<<endl;
                 }
                 else{
                     head->prev=n;
                     n->next=head;
                     head=n;
                 }
        }
    }
    //insert after a key
    void insertNodeAfterKey(int k,Node* n){
        Node* temp= nodeExists(k);
        if(temp == NULL){
            cout<<"no key exit of this value."<<endl;
        }
        else{
            if(nodeExists(n->key)!= NULL){
                cout<<"a new node cant be inserted of this key value as this key already exits."<<endl;
            }
            else if(temp->next==NULL){
                n->prev=temp;
                temp->next=n;
            }
            else{
                Node* temp1= temp->next;
                n->next=temp->next;
                n->prev=temp;
                temp1->prev=n;
                temp->next=n;
            }
        }
    }
    //delete a node
    void deleteNode(int k){
        Node* temp= nodeExists(k);
        if(head==NULL){
            cout<<"list is empty. nothing to delete."<<endl;
        }
        else{
            if(temp==NULL){
                cout<<"no key exit of this value to delete."<<endl;
            }
            else if(head==temp){
                head=temp->next;
            }
            else if(temp->next==NULL){
                Node* temp1= temp->prev;
                temp1->next=NULL;
            }
            else{
                Node* temp1= temp->prev;
                Node* temp2= temp->next;
                temp1->next=temp2;
                temp2->prev=temp1;
            }
        }
    }
    //update data of a node
    void updateNode(int k,int val){
        Node* temp= nodeExists(k);
        if(temp==NULL){
            cout<<"no key exit of this value to update."<<endl;
        }
        else{
            temp->data=val;
        }
    }
    //display a doubly linked list
    void displayDoublyList(){
        Node* temp= head;
        if(temp==NULL){
            cout<<"nothing to display. doubly linked list is empty."<<endl;
        }
        else{
            while(temp!=NULL){
                cout<<temp->key<<". "<<temp->data<<endl;
                temp=temp->next;
        }
        }
    }
    //print in reverse order
    void printReverseList(){
        Node* temp= head;
        if(temp==NULL){
            cout<<"nothing to display. doubly linked list is empty."<<endl;
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
             while(temp!=NULL){
            cout<<temp->key<<". "<<temp->data<<endl;
            temp=temp->prev;
            }
        }
    }

};
int main()
{
    Node n1(1,10);
    Node n2(2,20);
    doublyLinkedList s;
    int option,key1,k1,data1;
    do{
        cout<<"\nWhat operation do you want to perform? select option number. enter 0 to exit."<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNodeAfter()"<<endl;
        cout<<"4. deleteNodeByKey()"<<endl;
        cout<<"5. updateNodeByKey()"<<endl;
        cout<<"6. displayList()"<<endl;
        cout<<"7. printReverseList()"<<endl;
        cout<<"8. clear screen()"<<endl;

        cin>>option;
        Node* n1=new Node();

        switch (option)
        {
        case 1:
            cout<<"to append node operation. enter a key and data respectively: ";
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.appendNode(n1);
            break;
        case 2:
            cout<<"to prepend a node operation. enter a key and data respectively: ";
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.prependNode(n1);
            break;
        case 3:
            cout<<"to insert a node after a particular key. enter a key after which you want to insert :";
            cin>>k1;
            cout<<"enter key and data of new node: ";
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.insertNodeAfterKey(k1,n1);
            break;
        case 4:
            cout<<"to delete a node pass its key value: ";
            cin>>key1;
            s.deleteNode(key1);
            break;
        case 5:
            cout<<"to update a node by key, enter key and new value: ";
            cin>>key1;
            cin>>data1;
            s.updateNode(key1,data1);
            break;
        case 6:
            s.displayDoublyList();
            break;
        case 7:
                s.printReverseList();
                break;
        case 8:
                system("cls");
                break;
        default:
            cout<<"wrong input"<<endl;
            break;
        }
        
    }while(option!=0);

    return 0;
    return 0;
}