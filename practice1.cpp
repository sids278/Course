#include <iostream>
using namespace std;

/*void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void bubble_algo(int a[],int n){
    int i= n-1;
    while(i>0){
        if (a[i]<a[i-1]){
            swap(a,i,i-1);
        }
        i=i-1;
    }
}

void bubble_sort(int a[],int n){
    int i=0;
    while(i<n){
        bubble_algo(a,n);
    }
}






void displayer(int a[],int n){
    for(int k=0;k<=n-1;k++){
        cout<<a[k]<<" ";

    }
    cout<<""<<endl;

}*/
class node{
public:
    int data;
    node* next=NULL;
    node(int data){
        this->data=data;
    }
};
node* take_input(){
    int data;
    cin>>data;
    node* head=NULL;
    node* tail=NULL;
    node* new_node = new node(data);
    while(data!=-1){
        node* new_node = new node(data);

        if(head==NULL){
            head=new_node;
            tail=head;
        }

        else{
            tail->next=new_node;
            tail=tail->next;

        }
        cin>>data;
    }
    return head;

}

void print(node* head){
    while(head !=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
/*
int len(node* head){
    int cnt=0;
    while(head!=NULL){
        cnt+=1;
        head=head->next;
    }
    return cnt;
}
node* insert_recursive(node* head,int i,int data){
     node* new_node= new node(data);
    if(i==0){
       new_node->next=head;
       return new_node;
    } 
    
    else{
        node*temp = insert_recursive(head->next,i-1,data);

    }
    return head;
    
    
    
}
node* insertNodeRec(node *head, int i, int data) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     
    if(head==NULL)
        return NULL;
    if(i==0){
        node* temp=new node(data);
        temp->next=head;
        return temp;
    }
    
    if(i==1){
        node* temp=new node(data);
        temp->next=head->next;
        head->next=temp;
        return head;
    }
    else{
        node* curr=insertNodeRec(head->next,i-1,data);
    }
    return head;
}*/
/*node* reverse_linked(node*head){
    node*current = head;
    node*previous= NULL;
    while(current!=NULL){
        
        node*n=current->next;
        current->next=previous;
        previous=current;
        current=n;
    }
    return previous;
    

        

    

}*/
void print_nodes(node* head){
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
    }
    cout<<" "<<endl;
}
void insert_node(node* head,int i,int data){
    while(i!=1){
        head=head->next;
        i=i-1;
    }
    node *prev=head->next;
    node* new_node= new node(data);
    head->next=new_node;
    new_node->next=prev;
    
}
node* insert_recursive(node* head,int i ,int data){
    if(i==0){
        node* new_node=new node(data);
        new_node->next=head;
        head=new_node;
        return head;

    }
    if (i==1){
        node* temp =head->next;
        node*new_node=new node(data);
        head->next=new_node;
        new_node->next=temp;
        return head;
    }
    else{
        node* small_ans= insert_recursive(head->next,i-1,data);
        return head;
    }
}
void delete_node_iterative(node* head,int i){
    while(i!=1){
        head=head->next;
        i=i-1;
    }
    head->next=head->next->next;
   
}
node* delete_node_recursive(node* head,int i){
    if(i==0){
        head=head->next;
        return head;
    }
    if(i==1){
        head->next=head->next->next;
        return head;
    }
    else{
        node* small_ans=delete_node_recursive(head->next,i-1);
        return head;
    }
}
node* reverter(node* head){
    node* current =head;
    node*previous=NULL;
    while(current!=NULL){
        node*n=current->next;
        current->next=previous;
        previous=current;
        current=n;
    }
    return previous;
}
int main(){
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
   
   print(delete_node_recursive(head,3));
   cout<<" "<<endl;
   print(insert_recursive(head,3,4));
   cout<<" "<<endl;
   insert_node(head,7,7);
   print(head);
   
   print(reverter(head));
   

   
   
   
   

    

    
    


}