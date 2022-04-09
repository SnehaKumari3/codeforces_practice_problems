#include<iostream>
using namespace std;

class Queue{
    public:
    int front,rare;
    int arr[5];
    Queue(){
        front=-1;
        rare=-1;
        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    }
    //isEmpty
     bool isEmpty(){
            if(front==-1 && rare==-1)
                return true;
            else
                return false;
            
    }
    //isFull
    bool isFull(){
        if(rare==4)
        return true;
        else
        return false;
    }
     //insert
    void insertQueue(int data){
        if(isFull()){
            cout<<"queue is full."<<endl;
        }
        else if(isEmpty()){
            rare++;
            front++;
            arr[front]=data;
            cout<<"data entered."<<endl;
        }
        else{
            rare++;
            arr[rare]=data;
            cout<<"data entered."<<endl;
        }
    }
    //delete
    int deleteQueue(){
        if(isEmpty()){
            cout<<"queue is empty. nothing to delete."<<endl;
            return 0;
        }
        //if is the last element to delete
        else if(rare == front){
            int x=arr[front];
            front=-1;
            rare=-1;
            return x;
        }
        else{
            int x;
            x=arr[front];
            arr[front]=0;
            front++;
            return x;
        }
    }
    //count
    int countItem(){
        if(isEmpty()){
            return 0;
        }
        else{
            return (rare-front+1);
        }
    }
    //display
    void display(){
        cout<<"diplaying the queue:"<<endl;
        for(int i=0;i<5;i++){
            cout<<arr[i]<<"  "<<endl;
        }
    }
    
};
int main()
{
    int option,data;
    Queue q1;
    do{
        cout<<"select a option you want to perform. enter 0 to exit. "<<endl;
        cout<<"1. insertQueue()"<<endl;
        cout<<"2. deleteQueue()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. countItem()"<<endl;
        cout<<"6. display()"<<endl;
        cout<<"7. clearScreen()"<<endl;

        cin>>option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout<<"enter an element to insert: ";
            cin>>data;
            q1.insertQueue(data);
            break;
        case 2:
            cout<<"deleted element is "<<q1.deleteQueue()<<endl;
            break;
        case 3:
            if(q1.isEmpty())
            cout<<"Queue is empty"<<endl;
            else
            cout<<"Queue is not empty"<<endl;
            break;
        case 4:
            if(q1.isFull())
            cout<<"Queue is full"<<endl;
            else
            cout<<"Queue is not full"<<endl;
            break;
        case 5:
            cout<<"total number of count is "<<q1.countItem()<<endl;
            break;
        case 6:
            q1.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout<<"wrong input."<<endl;
            break;
        }

    }while(option!=0);
    return 0;
}