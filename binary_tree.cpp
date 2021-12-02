#include <iostream>
#include<queue>

using namespace std;
template <typename t>
class binary_treenode{
public:
    t data;
    binary_treenode *left = NULL;
    binary_treenode *right = NULL;
    binary_treenode(t data)
    {
        this->data = data;
    }
};
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
void print_levelwise(binary_treenode<int> *root){
    queue<binary_treenode<int> *> pending_for_printing;

    if (root == NULL)
    {
        return;
    }
    pending_for_printing.push(root);
    cout << root->data;

    while (pending_for_printing.size() != 0)
    {
        binary_treenode<int> *front = pending_for_printing.front();
        pending_for_printing.pop();
        

        if (front->left != NULL)
        {
            pending_for_printing.push(front->left);
            cout << front->left->data;
        }
        if (front->right != NULL)
        {

            pending_for_printing.push(front->right);
            cout << front->right->data;
        }
    }
}
int heigth(binary_treenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(heigth(root->left), heigth(root->right));
}
int check_balance(binary_treenode<int> *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int lh = heigth(root->left);
    int rh = heigth(root->right);

    if (abs(lh - rh) <= 1 && check_balance(root->left) && check_balance(root->right))
    {
        return 1;
    }

    return 0;
}

void print_recurive(binary_treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    print_recurive(root->left);
    print_recurive(root->right);
}
int node_cnt(binary_treenode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + node_cnt(root->right) + node_cnt(root->left);
}
void postorder(binary_treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}
void inorder(binary_treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void preorder(binary_treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}
binary_treenode<int> *leaf_remover(binary_treenode<int> *root)
{
    if (root->right == NULL && root->left == NULL)
    {
        root->data = -1;
        return root;
    }
    leaf_remover(root->left);
    leaf_remover(root->right);
}
//assignemnent level order transversal
void level_order(binary_treenode<int> *root, int i)
{
    queue<binary_treenode<int> *> level_printer;
    level_printer.push(NULL);
    if (root == NULL)
    {
        return;
    }
    level_printer.push(root);
    cout << root->data;
    while (i > 0)
    {
        binary_treenode<int> *front = level_printer.front();
        level_printer.pop();
        i--;
        if (front == NULL)
        {
            level_printer.push(NULL);
            i--;

            cout << endl;
        }
        else
        {
            if (front->left != NULL)
            {
                level_printer.push(front->left);
                cout << front->left->data;
            }
            if (front->right != NULL)
            {

                level_printer.push(front->right);
                cout << front->right->data;
            }
        }
    }
}
// zig zag binary tree
/*
void zig_zag(binary_treenode<int> *root, int i)
{
    queue<binary_treenode<int> *> q;
    deque<binary_treenode<int> *> dq;
    if (root == NULL)
    {
        return;
    }
    q.push(root);
    dq.push_front(root);
    q.push(NULL);
    dq.push_back(NULL);
    int n = 0;
    cout << root->data;
    while (n < i)
    {
        binary_treenode<int> *f1 = q.front();
        
        binary_treenode<int> *f2 = dq.front();
        q.pop();
        dq.pop_front();

        if (f1 || f2 == NULL)
        {
            n = n + 1;
            cout << endl;
            q.push(NULL);
            q.pop();
            dq.push_back(NULL);
            dq.pop_front();
        }
        else
        {
            if (n % 2 == 1)
            {

                if (f1->right != NULL)
                {
                    cout << f1->right->data;
                }
                if (f1->left != NULL)
                {
                    dq.push_front(f1->left);
                    q.push(f1->left);
                    cout << f1->left->data;
                }
                if (f1->right != NULL)
                {
                    q.push(f1->right);
                    dq.push_front(f1->right);
                }
            }
            else
            {
                if (f1->left != NULL)
                {
                    dq.push_front(f1->left);
                    cout << f1->left->data;
                    q.push(f1->left);
                }
                if (f1->right != NULL)
                {
                    dq.push_back(f1->right);
                    cout << f1->right->data;
                    q.push(f1->right);
                }
            }
        }
    }
}
*/
// question 6 without sibling assignement
void without_sibling(binary_treenode<int>* root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL && root->right==NULL){
        cout<<root->left->data;
    }
    else if(root->right!=NULL && root->left==NULL){
        cout<<root->right->data;
    }
    without_sibling(root->left);
    without_sibling(root->right);
}

