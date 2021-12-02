#include <iostream>
#include <queue>
using namespace std;
template<typename t>

/*
class queue{
    public:
    int size;
    int capacity;
    t*data;
    int first_indx;
    int next_indx;
    queue(int s){
        capacity=s;
        first_indx=-1;
        next_indx=0;
        data=new t[s];
    }
    void enqueue(t element){
        if(size==capacity){
            cout<<"queue is full!";
            return;
        }
        if(size==0){
            first_indx=0;
        }
        
        data[next_indx]=element;
        next_indx=(next_indx+1)%capacity;
        size=size+1;
        
    }
    t dequeue(){
        t x=data[first_indx];
        first_indx=(first_indx+1)%capacity;
        size=size-1;
        return x;
        
    }
    bool is_empty(){
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }
    int get_size(){
        return size;
    }
    t top(){
        return data[first_indx];
    }
    void printer(){
        for(int i=0;i<capacity;i++){
            cout<<data[i]<<endl;
        }
    }

    
};
*/
class node{
    t data;
    node* next=NULL;
};

class queue_linked_list{
    public:
    node*head;
    node*temp;
    int size;
    int capacity;
    queue_linked_list(int s){
        head=NULL;
        temp=head;
        capacity=s;
    }
    void push(t element){
        
        if(head==NULL){
        node*new_node=new node(element);
        head=new_node;
        temp=new_node;
        }
        else{
            node*new_node=new node(element);
            
            temp->next=new_node;
            temp=new_node;

        }
    }

}
int main(){
    queue<int>q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(10);
    
    queue<int>q2;
    while ((!q1.empty())){
        q2.push(q1.front());
        q1.pop();
    }
    
    while(!q2.empty()){
        cout<<q2.back()<<endl;
    
    }




}


    