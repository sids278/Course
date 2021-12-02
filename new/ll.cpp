#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next=NULL;
    node(int data)
    {
        this->data = data;
    }
};
int first_occurence(node* head,int check,int i){
    
    if(head->data==check){
        return i;
    }
    else{
        first_occurence(head->next,check,i+1);
        
        
    }
}
int mid(node*head){
    node*slow=head;
    node* fast=head;
    while(fast->next!=NULL && fast!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int length(node* head){
    int i=0;
    node*fast=head;
    while(fast!=NULL){
        i++;
        fast=fast->next;
    }
    return i;
}
node* locate_the_node_at_index(node*head,int i){
    while (i!=0)
    {
        head=head->next;

    }
    return head;
    
}
    



int main()
{
   node n1(1);
   node n2(2);
   node n3(3);
   node n4(4);
   node n5(5);
   node n6(6);

   n1.next=&n2;
   n2.next=&n3;
   n3.next=&n4;
   n4.next=&n5;
   n5.next=&n6;
   
   node*head=&n1;
   cout<<"hello"<<endl;
   
   cout<<length(head)<<endl;
   int i =locate_the_node_at_index(head,3)->data;
   cout<<i<<endl;

}



   

   


