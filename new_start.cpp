#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename t>
class binary_treenode{
    public:
    t data;
    binary_treenode* left=NULL;
    binary_treenode* right=NULL;
    binary_treenode(t data){
        this->data=data;
    }
};
class bst{
    public:
    binary_treenode<int>* root;
    private:
    bool has_data(binary_treenode<int>* node, int f ){
        if(node==NULL){
            return false;
        }
        if(node->data==f){
            return true;

        }
        if(node->data>f){
            has_data(node->left,f);
        }
        else{
            has_data(node->right,f);
        }
    }
    private:
    binary_treenode<int>* insert_node(binary_treenode<int>* node,int data_push){
        if(node==NULL){
            binary_treenode<int>* new_node = new binary_treenode<int>(data_push);
            return new_node;
        }
        if(node->data>data_push){
            node->left=insert_node(node->left,data_push);
        }
        else{
            node->right=insert_node(node->right,data_push);
        }
        return root;

    }
    binary_treenode<int>* delete_node(int data,binary_treenode<int>* node){
        if(node==NULL){
            return NULL;
        }
        if(node->data>data){
            node->left=delete_node(data,node->left);
        }
        else if(node->data<data){
            node->right=delete_node(data,node->right);
        }
        else{
            if(node->right==NULL && node->left==NULL){
                delete node;
            }
            else if(node->left==NULL){
                binary_treenode<int>* temp=node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                binary_treenode<int>* temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else{
                binary_treenode<int>* min_node=node->right;
                while(min_node->left!=NULL){
                    min_node=min_node->left;
                }
                int right_min=min_node->data;
                node->data=right_min;
                node->right=delete_node(right_min,node->right);
            }
        }
    }
    public:
    void  insert_node(int data){
        this->root=insert_node(this->root,data);
    }
    bool has_data(int n){
        return has_data(root,n);
    }
    void delete_node(int data){
        root=delete_node(data,root);
    }

    ~bst(){
        delete root;
    }
    
};

void bst_to_vector(binary_treenode<int>* root,vector<int> &for_bst){
    if(root==NULL){
        return;
    }
    bst_to_vector(root->left,for_bst); 
    for_bst.push_back(root->data);
    bst_to_vector(root->right,for_bst);
}
binary_treenode<int> *take_input(){
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
/*binary_treeNode<int> *constructBST(int arr[], int n){
    int mid = 0;
    /*
    if (n != 0){
        if (n % 2 == 0)
            mid = n/2 - 1;
        else
            mid = (n - 1)/ 2;
    }
    else
        return NULL;
        
    if (n == 0)
        return NULL;
    if (n % 2 != 0){
        mid = (n - 1)/ 2;

        binary_treeNode<int> *root = new binary_treeNode<int>(arr[mid]);
        root->left = constructBST(arr, mid);
        root->right = constructBST(arr + mid + 1, mid);
    }
    else{
        mid = n/2 - 1;

        binary_treeNode<int> *root = new binary_treeNode<int>(arr[mid]);
        root->left = constructBST(arr, mid);
        root->right = constructBST(arr + mid + 1, mid + 1);
    }
    return root;
}*/
binary_treenode<int>* bst_from_vector(vector<int> for_bst,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid =(s+e)/2;
    binary_treenode<int>* root=new binary_treenode<int>(for_bst[mid]);
    root->left=bst_from_vector(for_bst,s,mid-1);
    root->right=bst_from_vector(for_bst,mid+1,e);

    return root;
}
/*
void path_sum_to_node(binary_treenode<int>* root,int count, int check){
    if(root==NULL){
        return NULL;
    }
    if(count+root->data==check){
        return ;
    }
    if(count>check){
        return -1;
    }
    else{
        count+=root->data;
        cout<<root->data<<" ";
    }
    path_sum_to_node(root->left,count,check);
    path_sum_to_node(root->right,cout,check);
}
*/
    

int root_to_node_transversal(binary_treenode<int>* root,binary_treenode<int>* node,int cost){
    if(root==node){
       return cost;
    }
    cost+=1;
    
    if(root->data>node->data){
        root_to_node_transversal(root->left,node,cost);
    }
    else{
        root_to_node_transversal(root->right,node,cost);
    }
}
void nodes_at_distance(binary_treenode<int>* root,binary_treenode<int>* temp,int distance){
    if(root==NULL){
        return ;
    }
    if(root_to_node_transversal(root,temp,0)==distance){
       cout<<temp->data;
       return;
    }
    if(root_to_node_transversal(root,temp,0)>distance){
        return ;
    }
    nodes_at_distance(root,root->left,distance);
    nodes_at_distance(root,root->right,distance);
}
// nodes at distance k
#include <iostream>
using namespace std;
 
// A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};
 
/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
void printkdistanceNodeDown(node *root, int k)
{
    // Base Case
    if (root == NULL || k < 0)  return;
 
    // If we reach a k distant node, print it
    if (k==0)
    {
        cout << root->data << endl;
        return;
    }
 
    // Recur for left and right subtrees
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}
 
// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward.  This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
int printkdistanceNode(node* root, node* target , int k)
{
    // Base Case 1: If tree is empty, return -1
    if (root == NULL) return -1;
 
    // If target is same as root.  Use the downward function
    // to print all nodes at distance k in subtree rooted with
    // target or root
    if (root == target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }
 
    // Recur for left subtree
    int dl = printkdistanceNode(root->left, target, k);
 
    // Check if target node was found in left subtree
    if (dl != -1)
    {
         // If root is at distance k from target, print root
         // Note that dl is Distance of root's left child from target
         if (dl + 1 == k)
            cout << root->data << endl;
 
         // Else go to right subtree and print all k-dl-2 distant nodes
         // Note that the right child is 2 edges away from left child
         else
            printkdistanceNodeDown(root->right, k-dl-2);
 
         // Add 1 to the distance and return value for parent calls
         return 1 + dl;
    }
 
    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was not found in left subtree
    int dr = printkdistanceNode(root->right, target, k);
    if (dr != -1)
    {
         if (dr + 1 == k)
            cout << root->data << endl;
         else
            printkdistanceNodeDown(root->left, k-dr-2);
         return 1 + dr;
    }
 
    // If target was neither present in left nor in right subtree
    return -1;
}




int main(){
    vector<int> for_bst;
    //binary_treenode<int>* root= take_input();
    
    /*bst_to_vector(root,for_bst);
    
    for(int i=1;i<for_bst.size();i++){
        for_bst[i]=for_bst[i-1]+ for_bst[i-2];
        
    }
    binary_treenode<int>* root2=bst_from_vector(for_bst,0,for_bst.size());
    cout<<root2->data;
    cout<<root2->left->data;
    cout<<root2->right->data;
    */
    binary_treenode<int>* root= new binary_treenode<int>(4);
    binary_treenode<int>* left= new binary_treenode<int>(2);
    binary_treenode<int>* right= new binary_treenode<int>(6);
    root->left=left;
    root->right=right;
    left->left=new binary_treenode<int>(1);
    right->right= new binary_treenode<int>(8);
    right->left=new binary_treenode<int>(5);
    
    
    

}