#include <bits/stdc++.h>
using namespace std;

/*
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
*/

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    void dfs(Node *node, Node *copy, vector<Node *> &vis)
    {
        vis[copy->val] = copy;
        for (auto org : node->neighbors)
        {
            if (vis[org->val] == NULL)
            {
                Node *newCopy = new Node(org->val);
                (copy->neighbors).push_back(newCopy);
                dfs(org, newCopy, vis);
            }
            else
            {
                (copy->neighbors).push_back(vis[org->val]);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        vector<Node *> vis(101, NULL);
        Node *copy = new Node(node->val);
        dfs(node, copy, vis);
        return copy;
    }
};
int main()
{

    return 0;
}