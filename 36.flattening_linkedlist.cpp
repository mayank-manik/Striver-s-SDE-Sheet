#include <bits/stdc++.h>
using namespace std;

// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *a, Node *b)
{
    Node *res = new Node(0);
    Node *temp = res;
    while (a and b)
    {
        if (a->data > b->data)
        {
            temp->bottom = b;
            b = b->bottom;
            temp = temp->bottom;
        }
        else
        {
            temp->bottom = a;
            a = a->bottom;
            temp = temp->bottom;
        }
    }
    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;
    return res->bottom;
}
Node *flatten(Node *root)
{
    if (!root or !root->next)
        return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}
int main()
{

    return 0;
}