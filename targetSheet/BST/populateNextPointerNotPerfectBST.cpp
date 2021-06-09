#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node *nextRight; // This has garbage value in input trees
};

class Solution
{
public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        // Your Code Here
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {

            Node *prev = NULL;
            int sz = q.size();
            while (sz--)
            {

                Node *temp = q.front();
                q.pop();
                if (prev != NULL)
                    prev->nextRight = temp;
                prev = temp;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }
};