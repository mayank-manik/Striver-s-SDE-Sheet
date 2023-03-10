#include <bits/stdc++.h>
using namespace std;

// Given the head of a linked list, rotate the list to the right by k places.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head or !head->next or k == 0)
        return head;
    ListNode *cur = head;
    int len = 1;
    while (cur->next and ++len)
        cur = cur->next;
    cur->next = head;
    k = k % len;
    k = len - k;
    while (k--)
        cur = cur->next;

    head = cur->next;
    cur->next = NULL;

    return head;
}
int main()
{

    return 0;
}