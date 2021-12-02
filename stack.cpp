#include <iostream>
#include <stack>
using namespace std;
template<typename t>



class TreeNode{
    int data;
    vector<TreeNode<int>*> children;
    TreeNode(int a){
        data=a;
    }
    
};

TreeNode<int>* TakeInput(){
    int a;
    cin>>a;
    TreeNode<int>* root=new TreeNode<int>(a);
    queue<int> pending_node;
    pending_nodes.push(root);
    while(pending_nodes.size()){
        TreeNode<int>*front=pending_root.front();
        int n;cin>>n;
        pending_node.pop();
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            TreeNode<int>*daughter=new TreeNode<int>(a);
            front->children.push_back(daughter);
            pending_nodes.push(daughter);
        }

    }
    return root;
}

    
   
    class node{
        public:
        int data;
        node* next;
        node(int data){
            this->data=data;
            next=NULL;
        }

    };
    class stack_using_linkedlist{
        public:
        int size;
        node* head;
        stack_using_linkedlist(){
            size=0;
            head=NULL;
        }
        void push(int data){
             node*new_node= new node(data);
             new_node->next=head;
             head=new_node;
             size+=1;
        }
        void top(){
            cout<<head->data;
        }
        void pop(){
            cout<<head->data;
            head=head->next;
            size=size-1;
            
        }
        int get_size(){
            return size;
        }
        


    };


    class stack_using_array{

        int* data;
        int next_indx;
        int capacity;
        public:
        stack_using_array(int total_size){
            data=new int[total_size];
            next_indx=0;
            capacity=total_size;
        }
        void push(int element){

            if(next_indx==capacity){
                int*new_array=new int[2*capacity];
                for(int i=0;i<next_indx;i++){
                    new_array[i]=data[i];
                }
                data=new_array;
                data[next_indx]=element;
                capacity=capacity*2;
                next_indx++;
            }
            else{
                data[next_indx]=element;
                next_indx++;
            }

        }
        int size(){
            return next_indx;

        }
        int top(){
            if(next_indx==0){
                cout<<"stack is empty bruh";
                return 0;
            }

            return data[next_indx-1];
        }
        void pop(){
            cout<<data[next_indx-1]<<endl;

            next_indx=next_indx-1;
        }
        bool is_empty(){
            if(next_indx==0){
                return true;

            }
            return false;

        }
        void print(){
            for(int i=0;i<next_indx;i++){
                cout<<data[i];
            }
        }
    };
void stack_reverter(stack<int> s1,stack<int> s2){
     while(!s1.empty()){
        int x=s1.top();
        s2.push(x);
        s1.pop();
    }
}

    

    stack_using_array s1(3);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.print();

    s1.pop();
    s1.print();
    stack_using_linkedlist s2;
    s2.push(90);
    s2.push(45);
    s2.push(22);
    s2.pop();
    s2.top();

    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    
    stack<int> s2;
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();

    }
    cout<<s2.top()<<endl;
    s2.pop();
    cout<<s2.top()<<endl;
    

class stack_using_array{
    public:
    int capacity;
    t* data;
    int next_indx;
    int size;
    stack_using_array(int s){
        data = new t[s];
        capacity =s;
        next_indx=0;
    }
    void push(t element){
        if(size==capacity){
            cout<<"stack is full!";
            return;
        }
        data[next_indx]=element;
        size++;
        next_indx++;
    }
    t pop(){
        t x=data[next_indx-1];
        next_indx-=1;
        size-=1;
        return x;
    }
    int get_size(){
        return size;
    }
    t top(){
        return data[next_indx-1];
    }
};
int main(){
    stack_using_array<int> s1(4);
    s1.push(1);
    cout<<s1.top();
}
