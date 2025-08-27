#include<iostream>
using namespace std;
class  node{
    public:
        int data;
        node* next;
        node(int data){
           this->data=data;
           this->next=NULL;
        }
 };
  void insertlinkedlist(node* &head,int data){
          node*temp=new node(data);
          temp->next=head;
          head= temp;  


}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
node* node1=new node(20);

// cout<<node1->data<<endl;
// cout<<node1->next<<endl;
// cout<<node2->data<<endl;
// cout<<node2->next<<endl;
node*head = node1;
print(head);
insertlinkedlist(head,33);
print(head); 








}