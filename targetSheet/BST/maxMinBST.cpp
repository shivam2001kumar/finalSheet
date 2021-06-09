#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node* left;
    struct node* right;
};
int maxValue(struct node* node)
{  
    /* loop down to find the rightmost leaf */
    struct node* current = node;
    while (current->right != NULL)
        current = current->right;
     
    return (current->data);
}
int minValue(struct node* node)
{  
    /* loop down to find the rightmost leaf */
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
     
    return (current->data);
}