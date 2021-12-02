#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
    }
};

int main()
{
    int data;
    cin>>data;
    Node* new_node= new Node(data);
    Node* head=new_node;
    Node* temp=head;
    while(temp!=NULL){
        int data;
        cin>>data;
        Node*new_node=new Node(data);
        temp->next=new_node;
        temp=temp->next;

    }

    while(head!=NULL){
        int ans = head->data;
        cout<<ans<<endl;
        head=head->next;
    }
}