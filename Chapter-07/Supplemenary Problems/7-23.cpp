/*
Page 269
7.5  Suppose a binary tree T is in memory and an ITEM of information is given.

(a) Write a procedure which finds the location LOC of ITEM in T (assuming the elements of T are distinct).

(b) Write a procedure which finds the location LOC of ITEM and the location PAR of the parent of ITEM in T.

(c) Write a procedure which finds the number NUM of times ITEM appears in T (assuming the elements of T are not necessarily distinct).

Remark: T is not necessarily a binary search tree.


*/
#include <iomanip>
#include <iostream>
#include <stack>
using namespace std;
typedef struct _tree
{
    char data;
    _tree *left;
    _tree *right;
} TREE;

TREE *insert(TREE *root, char data)
{
    if (root == NULL)
    {
        TREE *ptr = new TREE;
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
    }
    else if (root->data > data)
    {
       root->right =  insert(root->right, data);
    }
    else
       root->left =  insert(root->left, data);
    return root;
}

void COUNT(TREE *root, int &NUM)
{

    if(root == NULL)
    {
        return;
    }
    else 
    {
        NUM = NUM + 1;
        COUNT(root->left,NUM);
        COUNT(root->right,NUM);
    }

}
int MAX(int i, int j)
{
    return (i>j)? i:j;
}
int Find_Depth(TREE *root)
{
    if(root == NULL)
    {
        return -1;
    }
        int l = Find_Depth(root->left);
        int r = Find_Depth(root->right);
        return MAX(l, r) + 1;
}
void PreOrder(TREE *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void inorder(TREE *root)
{

    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

}
void postorder(TREE *root)
{

    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

}
void find(TREE  *root, int data)
{
    if(root != NULL)
    {
        find(root->left, data);
        find(root->right,data);
        if(root->data == data)
        {
            cout << "found\n";
            return;
        }
    }
}
void find_R(TREE  *root, int data, int &ck)
{
    if(root != NULL)
    {
        find_R(root->left, data,ck);
        find_R(root->right,data,ck);
        if(root->data == data,ck)
        {
            ck++;
        }
    }
}
int main()
{
    int AVAIL = 9;
    char  temp;
    TREE *root = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    inorder(root);
    cout << "\n";
    PreOrder(root);
    cout << "\n";
    postorder(root);


}
/*
F
H
D
B
G
A
E
C
K
K H G F E D C B A 
F H K G D E B C A
K G H E C A B D F
*/