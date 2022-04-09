#include<iostream>
using namespace std;

class Node{
    public:
    int data,key;
    Node* next;
    Node(){
        data=0;
        key=0;
        next=NULL;
    }
    Node(int k,int d){
        key=k;
        data=d;
    }
};
class circularLinkedList{
    public:
    Node* head;
    circularLinkedList(){
        head=NULL;
    }
    circularLinkedList(Node* n){
        head=n;
    }

    //keyExists

    Node* keyExsits(int k){
        Node* temp=NULL;
        Node* ptr=head;
        while(ptr!=NULL){
            if(ptr->key==k)
            {
                temp=ptr;
                return temp;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    //append node
    void appendNode(Node* n){
        if(keyExsits(n->key)!=NULL){
            cout<<"this key already exits. try with a unique key."<<endl;
        }
        else{
            if(head==NULL){
            head=n;
            n->next=head;
             }
            else{
            Node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=n;
            n->next=head;
            }
        } 
    }
    //prepend
    void prependNode(Node* n){
        if(keyExsits(n->key)!=NULL){
            cout<<"this key already exits. try with a unique key."<<endl;
        }
        else{
            if(head==NULL){
            head=n;
            n->next=head;
        }
        else{
            n->next=head;
            Node* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=n;
            head=n;
        }
        } 
    }
    //insert after a key
    void inserNodeAfterKey(int k,Node* n){
        if(keyExsits(k)==NULL){
            cout<<"this key doesn't exits. insert after another key."<<endl;
        }
        else{
            if(keyExsits(n->key)!=NULL){
            cout<<"this key already exits. try with a unique key."<<endl;
            }
            else{
                Node* temp=head;
                while(temp->key!=k){
                temp=temp->next;
            }
                n->next=temp->next;
                temp->next=n;
            }
        }
    }
    //delete a node
    void deleteNode(int k){
        Node* temp1=keyExsits(k);
        if(temp1 == NULL){
            cout<<"this key doesn't exits. so key cant be deleted."<<endl;
        }
        else{
            if(temp1 == head){
                Node* temp=head;
                 while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=temp1;
            head=temp;
            }
            else if(temp1->next == head){
                Node* temp=head;
                 while(temp->next!=temp1){
                temp=temp->next;
            }
            temp->next=head;
            }
            else{
                Node* temp=head;
                 while(temp->next!=temp1){
                temp=temp->next;
            }
            temp->next=temp1->next;
            }
            cout<<"node deleted with this key value."<<endl;
        }
    }
    //update a node
    void updateNode(int k,int val){
        Node* temp1=keyExsits(k);
        if(temp1 == NULL){
            cout<<"this key doesn't exits. so key cant be updated."<<endl;
        }
        else{
            temp1->data=val;
            cout<<"node updated."<<endl;
        }
    }
    //display list
    void printCircularList(){
        Node* temp=head;
            cout<<"printing the node key and data:"<<endl;
                 while(temp->next!=head){
                cout<<temp->key<<". "<<temp->data<<" , ";
                temp=temp->next;
            }
            cout<<temp->key<<". "<<temp->data<<endl;
    }
};

int main()
{
    
    return 0;
}