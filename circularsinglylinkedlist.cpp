#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    // constructor
    node(int d){
        this->data=d;
        this->next=NULL;
    }
    // destructor
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for the data "<<value<<endl;
        
    }

};
void insertnode(node*&tail,int element,int d){
    node*temp=new node(d);
    if(tail==NULL){
        tail=temp;
        temp->next=temp;
    }
    else{
        node*current=tail;
        while(current->data!=element){
            current=current->next;
        }
        temp->next=current->next;
        current->next=temp;
    }
}
void print(node*tail){
     node*temp=tail;
     if(tail==NULL){
        cout<<"the list is empty"<<" ";
     }
     do{
         cout<<tail->data<<" ";
         tail=tail->next;
     }while(tail!=temp);
     cout<<endl;
    }
    void deletenode(node*&tail,int value){
        if(tail==NULL){
            return;
        }
        else{
             node*previous=tail;
             node*current=previous->next;
             while(current->data!=value){
                previous=current;
                current=current->next;
             }
             previous->next=current->next;
             if(current==previous){
                tail=NULL;
             }
             
             
             if(tail==current){
                tail=previous;
             }
             current->next=NULL;
             delete current;
        }
    }

int main(){
    node*tail=NULL;
    insertnode(tail,5,3);
    print(tail);
    insertnode(tail,3,5);
    print(tail);
    insertnode(tail,3,6);
    print(tail);
    deletenode(tail,3);
    print(tail);
    return 0;
}