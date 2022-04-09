#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    int data;
    Node* next;
    Node(){
        key =0;
        data=0;
        next=NULL;
    }

    Node(int k,int d){
        key=k;
        data=d;
        next=NULL;
    }
};

class SinglyLinkedList{
    public:
        Node* head;

        SinglyLinkedList(){
            head=NULL;
        }
        SinglyLinkedList(Node* n){
            head=n;
        }
        //check a node exist using key value
        Node* nodeExists(int k){
            Node* temp=NULL;
            Node* ptr=head;
            while(ptr!=NULL){
                if(ptr->key==k){
                    temp=ptr;
                }
                ptr=ptr->next;               
            }
            return temp;
        }
        //append a node to the list
        void appendNode(Node* n){
            if(nodeExists(n->key)==NULL){
                if(head==NULL){
                    head=n;
                    cout<<"node appended"<<endl;
                }
                else{
                Node* ptr=head;
                     while(ptr->next!=NULL){
                      ptr=ptr->next;               
                     }
                    ptr->next=n;
                    cout<<"node appended."<<endl;
                    n->next=NULL;
                }
             }
             else{
                cout<<"node already exits append another node with different key value."<<endl;
            }
        }

        //prepend node
        void prependNode(Node* n){
            if(nodeExists(n->key)==NULL){
                if(head==NULL){
                    head=n;
                    cout<<"node prepended"<<endl;
                }
                else{
                    n->next=head;
                    head=n;
                    cout<<"node prepended"<<endl;
                }
            }
            else{
                cout<<"node already exits prepend another node with different key value."<<endl;
            }
        }
        //insert a node after a particular node in the list
        void insertNodeAfter(int k,Node* n){
            Node* ptr=nodeExists(k);
            if(ptr!=NULL){
                    if(nodeExists(n->key)!=NULL){
                        cout<<"node already exits insert another node with different key value."<<endl;
                    }
                    else{
                    n->next=ptr->next;
                    ptr->next=n;
                    cout<<"node inserted."<<endl;
                    }
            }
            else{
                    cout<<"no node exit of this key value."<<endl;
            }
        }
        //deleting a node by unique key
        void deleteNode(int k){
            Node* ptr=nodeExists(k);
            Node* temp=head->next;
            if(head==NULL){
                cout<<"linked list is empty"<<endl;
            }
            else if(ptr==NULL){
                cout<<"node doesnt exit. so cant deleted."<<endl;
            }
            else{
                if(head->key==k){
                head=head->next;
                cout<<"node unlinked with key value"<<endl;
                }
                else{
                while(temp->next!=ptr){
                    temp=temp->next;
                }
                temp->next=ptr->next;
                cout<<"node unlinked with key value"<<endl;
                 }
            }
        }
        //update data of a node
        void updateNodeByKey(int k,int val){
            Node* ptr=nodeExists(k);
            if(ptr==NULL){
                cout<<"no node found of this key value"<<endl;
            }
            else{
                ptr->data=val;
                cout<<"node updated"<<endl;
            }
        }
        //display the linked list
        void displayList(){
            if(head==NULL){
                cout<<"no node in the list to display"<<endl;
            }
            else{
                Node* ptr=head;
            cout<<"diplaying the linked list: "<<endl;
            while(ptr!=NULL){
                cout<<ptr->key<<" "<<ptr->data<<endl;
                ptr=ptr->next;
            }
            }
        }
};

int main()
{
    Node n1(1,10);
    Node n2(2,20);
    SinglyLinkedList s;
    int option,key1,k1,data1;
    do{
        cout<<"\nWhat operation do you want to perform? select option number. enter 0 to exit."<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNodeAfter()"<<endl;
        cout<<"4. deleteNodeByKey()"<<endl;
        cout<<"5. updateNodeByKey()"<<endl;
        cout<<"6. displayList()"<<endl;
        cout<<"7. clear screen()"<<endl;

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
            s.insertNodeAfter(k1,n1);
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
            s.updateNodeByKey(key1,data1);
            break;
        case 6:
            s.displayList();
            break;
        case 7:
                system("cls");
                break;
        
        default:
            cout<<"wrong input"<<endl;
            break;
        }
        
    }while(option!=0);

    return 0;
}