#include <iostream>
using namespace std;
template <typename t>
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
            cout<<"queue is full!"
            return;
        }
        
        data[next_indx]=element;
        next_indx=(next_indx+1)%s;
        size=size+1;
    }
    t dequeue(){
        t x=data[first_indx];
        first_indx=(first_indx+1)%s;
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

    
};
int main(){
    queue<int>q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    cout<<q1.top()<<endl;
}