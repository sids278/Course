#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
    }
};
int first_occurence(node* head,int check,int cnt){
    
    if(head->data=check){
        return cnt;
    }
    else{
        first_occurence(head->next,check,cnt+1)
    }

int main()
{
   node n1(23);
   node n2(21);
   node n3(24);
   node n4(21);
   node n5(-1);

   n1.next=&n2;
   n2.next=&n3;
   n3.next=&n4;
   n4.next=&n5;
   node*head=&n1;
   cout<<first_occurence(head,21,0)<<"you did ok"<<endl;



}