#include <iostream>
using namespace std;
#include <vector>

class node
{
public:
    node *next = NULL;
    int data;
    node(int data)
    {
        this->data = data;
    }
};
int find_indx(node *head, int check, int i)
{

    if (head->data == check)
    {
        return i;
    }
    find_indx(head->next, check, i + 1);
}
int lenght(node *head, node *temp, int i)
{

    while (find_indx(head, temp->data, 0) < find_indx(head, temp->next->data, 0) && temp != NULL)
    {
        temp = temp->next;
        i += 1;
    }
    return i;
}
bool cycle(node *head)
{
    for (int j = 0; j < lenght(head, head, 0); j++)
    {
        if (head == NULL)
        {
            return false;
        }
        else
        {
            head = head->next;
        }
    }
    return true;
}

// iterative way to reverse linked lis
node *reverse_linked_list(node *head)
{

    node *prev = NULL;
    while (head != NULL)
    {
        node *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return head;
}
// recursive approach to revers linked list
node *reverse_recursive(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    /* reverse the rest list and put
          the first element at the end */
    Node *rest = reverse(head->next);
    head->next->next = head;

    /* tricky step */
    head->next = NULL;

    /* fix the head pointer */
    return rest;
}
// find node

int main()
{
    node *head = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *fourth = new node(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;
}