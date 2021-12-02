#include <iostream>
#include<vector>
#include "binary_tree.cpp"
#include<queue>
using namespace std;

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
vector<int> treeToList(binary_treenode<int>* node, vector<int>& list)
    {
        // Base Case
        if (node == NULL){
            return list;
        }
        treeToList(node->left, list);
        list.push_back(node->data);
        treeToList(node->right, list);
 
        return list;
}
 
    // method that checks if there is a pair present
bool isPairPresent(binary_treenode<int>* node, int target)
    {
        // This list a1 is passed as an argument
        // in treeToList method
        // which is later on filled by the values of BST
        vector<int> a1;
 
        // a2 list contains all the values of BST
        // returned by treeToList method
        vector<int> a2 = treeToList(node, a1);
 
        int start = 0; // Starting index of a2
 
        int end = (int)a2.size() - 1; // Ending index of a2
 
        while (start < end) {
 
            if (a2[start] + a2[end] == target) // Target Found!
            {
                cout << "Pair Found: " << a2[start] << " + " << a2[end] << " = " << target << '\n';
                return true;
            }
 
            if (a2[start] + a2[end]  > target) // decrements end
            {
                end--;
            }
 
            if (a2[start] + a2[end]  < target) // increments start
            {
                start++;
            }
        }
 
        cout << "No such values are found!\n";
        return false;
}
// lca binary  tree assignement
binary_treenode<int>* lca(binary_treenode<int>* root,binary_treenode<int>* p,binary_treenode<int>* q){
    if(root==NULL||root==p||root==q){
        return root;
    }
    binary_treenode<int>* left=lca(root->left,p,q);
    binary_treenode<int>* right=lca(root->right,p,q);

    if(right==NULL){
        return left;
    }
    else if(left==NULL){
        return right;
    }
    else{
        return root;
    }
}
int max_bst(binary_treenode<int>* root,int max_height){
    if(root==NULL){
        return 0;
    }
    

}
void bst_to_vector(binary_treenode<int>* root , vector<int> a){
    if(root==NULL){
        return NULL;
    }
    a.push_back

}


int main(){
    bst b1;
    binary_treenode<int>* root= take_input();
    
    b1.root=root;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    
