#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next = NULL;
    node(int data)
    {
        this->data = data;
    }
};
node *take_input()
{
    int data;
    cin >> data;

    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *new_node = new node(data);

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = tail->next;
        }
        int data;
        cin >> data;
    }
    cout << "everything is ok in input";
    return head;
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
    }
}
// find node
node* node_finder(node* head,int check){
    if(head==NULL){
        return -1;
    }
    if(head->data==check){
        return head;
    }
    else{
        
        return node_finder(head->next,check);
    }
   
}
// last n to append in front(iterative )
node* last_to_first(node* head,int indx){
    node* temp=head;
    while(int i=0<indx-1){
        head=head->next;
    }
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next
    }
    tail->next=temp;
    head->next=NULL;

}
// last n to first (recursive)
// almost same hai lo bsdk aage chal ig


// Q3 delete duplicates
node* delete_duplicates(node* head){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==temp->next==data){
            delete temp->next;
        }
        temp=temp->next;
    }
}

int main()
{
    node* head= take_input();
    print(head);
    
}
