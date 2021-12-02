#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template<typename t>
class tree_node{
    public:
    t data;
    vector<tree_node*>children;
    tree_node(t data){
        this->data=data;
    }

};

/*tree_node<int>* take_input(){
    int rootdata;
    cout<<"give input of root_node"<<endl;
    cin>>rootdata;
    tree_node<int>* root = new tree_node<int>(rootdata); 
    int n;
    cout<<"give input for number of children of "<<rootdata<<endl;

    
    cin>>n;
    for(int i=0;i<n;i++){
        child=take_input();
        root.children.push_back(child);
    }
    
    return root;
}
*/

void print_the_tree(tree_node<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
        
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        print_the_tree(root->children[i]);
    }
}
tree_node<int>* take_input_levelwise(){
    int rootdata;
    cout<<"enter the root data:"<<endl;
    cin>>rootdata;
    tree_node<int>*root= new tree_node<int>(rootdata);
    queue<tree_node<int>*> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size()!=0)
    {
        tree_node<int>* front =pending_nodes.front();
        pending_nodes.pop();
        int n;
        cout<<"enter the number of children of :"<< front->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            int child_data;
            cout<<"enter the value for "<<i<<"th child of : "<<front->data<<endl;
            cin>>child_data;
            tree_node<int>* child =new tree_node<int>(child_data);
            front->children.push_back(child);
            pending_nodes.push(child);


        }
    }
    return root;
    
    
}
void print_the_tree_levelwise(tree_node<int>* root){
    queue<tree_node<int>*>left_for_printing;
    left_for_printing.push(root);
    while(left_for_printing.size()!=0){
        tree_node<int>*front= left_for_printing.front();
        left_for_printing.pop();
        cout<<"the children of "<<front->data<<" are : ";
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            left_for_printing.push(front->children[i]);
        }
        cout<<endl;
    }
}
void print_recursive(tree_node<int>* root){
    cout<<root->data;
    for(int i=0;i<root->children.size();i++){
        print_recursive(root->children[i]);
    }
}
int leaf_count_of_tree(tree_node<int>* root){
    int ans=0;
    queue<tree_node<int>*>left_for_printing;
    left_for_printing.push(root);
    while(left_for_printing.size()!=0){
        tree_node<int>*front= left_for_printing.front();
        left_for_printing.pop();
        if(front->children.size()==0)
            ans++;
        for(int i=0;i<front->children.size();i++){
            
            left_for_printing.push(front->children[i]);
        }
        
    }
    return ans;

}
int check(tree_node<int>* root,int x){
    
    if(root->data>x){
        x=root->data;
        
    }
    for(int i=0;i<root->children.size();i++){
        int y=check(root->children[i],x);
        x=y;
        
        
    }
    return x;
}
int max_child_sum(tree_node<int>* root){
    int ans=0;
    ans+=root->data;
    for (int i=0;i<root->children.size();i++){
        ans+=check(root->children[i],0);

    }
    return ans;
    
    
}

int the_second_largest_node(tree_node<int>* root,int x,int greatest){
    
    
    if(root->data>x && root->data<greatest){
        x=root->data;
        
    }
    for(int i=0;i<root->children.size();i++){
        int y= the_second_largest_node(root->children[i],x,greatest);
        x=y;
    }
    return x;
    

}    
int main(){
    tree_node<int>* root= take_input_levelwise();
    
    
    print_the_tree_levelwise(root);
    
    


    
}
    