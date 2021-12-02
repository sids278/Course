#include <iostream>
#include <queue>
using namespace std;
template <typename t>


class binary_treenode
{
public:
    t data;
    binary_treenode *left = NULL;
    binary_treenode *right = NULL;
    binary_treenode(t data)
    {
        this->data = data;
    }
};

binary_treenode<int> *take_input()
{
    int data;
    cout << "enter the root data" << endl;
    cin >> data;
    queue<binary_treenode<int> *> pending;

    if (data == -1)
    {
        return 0;
    }
    binary_treenode<int> *root = new binary_treenode<int>(data);

    pending.push(root);

    while (pending.size() != 0)
    {
        binary_treenode<int> *front = pending.front();
        pending.pop();
        int left_data;
        cout << "enter the left child of " << front->data << endl;
        cin >> left_data;
        if (left_data != -1)
        {
            binary_treenode<int> *left_node = new binary_treenode<int>(left_data);
            front->left = left_node;
            pending.push(left_node);
        }
        int right;
        cout << " enter the right child of " << front->data << endl;
        cin >> right;
        if (right != -1)
        {
            binary_treenode<int> *right_node = new binary_treenode<int>(right);
            pending.push(right_node);
            front->right = right_node;
        }
    }
    return root;
}


binary_treenode<int>* search_on_tree(binary_treenode<int>* root, int f){
    if(root==NULL){
        return NULL;
    }
    if(root->data==f){
        return root;
    }
    if(root->data>f){
        cout<<root->left->data;
        return search_on_tree(root->left,f);
    }
    else{
        cout<<root->right->data;
        return search_on_tree(root->right,f);
    }

}
void print_in_range(binary_treenode<int>* root,int s,int l){
    if(root==NULL){
        return;
    }
    if(root->data>=s && root->data<=l){
       cout<<root->data<<endl;
       print_in_range(root->left,s,l);
       print_in_range(root->right,s,l);
    }
    if(root->data>=l){
        print_in_range(root->left,s,l);
    }
    if(root->data<=s){
        print_in_range(root->right,s,l);
    }
}
//check if binary tree is a bst or not
int check_bst(binary_treenode<int>* root){
    if(root==NULL){
        return 1;
    }
    
    if(root->right!=NULL && root->data>root->right->data ){
        return 0;
    }
    if(root->left!=NULL && root->left->data>root->data){
        return 0;
    }
    if(!check_bst(root->right) || !check_bst(root->left)){
        return 0;
    }
    return 1;
}
// forming bst from a sorted array
binary_treenode<int>* bst_from_array(int a[],int n){
    
    if(n==0){
        return NULL;
    }
    binary_treenode<int>* root =NULL;
    if(n%2==1){
        int mid =(n-1)/2;
        binary_treenode<int>* root = new binary_treenode<int>(a[mid]);
        root->left=bst_from_array(a,mid);
        root->right=bst_from_array(a+mid+1,mid);
    }
    else{
        int mid =n/2-1;
        binary_treenode<int>* root = new binary_treenode<int>(a[mid]);
        root->left=bst_from_array(a,mid);
        root->right=bst_from_array(a+mid+1,mid+1);
    }
    

    return root;

}

// preorder printter
void preorder (binary_treenode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
    
}
// flatten bst to ll --> very very good look again
void bst2ll(binary_treenode<int>* root,binary_treenode<int>* prev){
    if(root==NULL){
        return;
    }
    bst2ll(root->right,prev);
    bst2ll(root->left,prev);

    root->right=prev;
    root->left=NULL;

    prev=root;


}
///// AVL TREES DEKHNA HAI BSDK UTH JA



int main(){
    binary_treenode<int>* root =take_input();
    
    
    cout<<"vs code is fuck";
}
