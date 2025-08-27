#include<iostream>
using namespace std;
class node{
   public:
    int data;
node*previous;
node*next;
//constructor 
node(int d){
this->data=d;
this->next=NULL;
this->previous=NULL;
}
// destructor
~node(){
    int value=this->data;
    if(next!=NULL){
        delete next;
        next=NULL;
    }
    cout<<"memory free for node with data"<<value<<endl;
}
};
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int  getlength(node*head){
    int len=0;
     node*temp=head;
    while(temp!=NULL){
       len++;
       temp=temp->next;
    }
    return len;
}
void insertathead(node*&head,int data){
    node*temp=new node(data);
    temp->next=head;
    head->previous=temp;
    head=temp;
}
void insertattail(node*&tail,int data){
    node*temp=new node(data);
    temp->previous=tail;
    tail->next=temp;
    temp=tail;
}
void insertatposition(node*&tail,node*&head,int position,int data){
    if(position==1){
        insertathead(head,data);
        return;
    }
    
        node*temp=head;
        int count=1;
        while(count<position-1){
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL){
          insertattail(tail,data);
          return;
        }
        
        node*nodetoinsert=new node(data);
        nodetoinsert->next=temp->next;
        temp->next->previous=nodetoinsert;
        temp->next=nodetoinsert;
        nodetoinsert->previous=temp;
    
}
void deletenode(int position,node*&head){
    if(position==1){
        node*temp=head;
        temp->next->previous=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node*current=head;
        node*previous=NULL;
        int count=1;
        while(count<position){
            previous=current;
            current=current->next;
            count++;
        }
        current->previous=NULL;
        previous->next=current->next;
        current->next=NULL;
        delete current;
    }
}
int main(){

node*node1=new node(3);
node*head=node1;
node*tail=node1;
print(head);
insertathead(head,5);
print(head);
insertattail(tail,6);
print(head);
insertatposition(tail,head,3,55);
print(head);
deletenode(4,head);
print(head);
cout<<getlength(head)<<endl;

    return 0;
}