#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class Bst
{
public:
    Node *root = NULL;

    void insertt(int);
    void inorder(Node*);
};

void Bst::insertt(int ele)
{
    Node *temp,*prnt;
    temp = new Node;
    temp->data = ele;
    temp->left = NULL;
    temp->right = NULL;

    prnt = root;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        Node *curr;
        curr = root;
        while(curr)
        {
            prnt = curr;
            if(temp->data > curr->data)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        if(temp->data > prnt->data)
        {
            prnt->right = temp;
        }
        else
        {
            prnt->left = temp;
        }
    }
}

void Bst::inorder(Node* r)
{
    if(r->left)
        inorder(r->left);
    cout<<r->data<<"\t";
    if(r->right)
        inorder(r->right);
}

int main()
{
    Bst b;
    b.insertt(10);
    b.insertt(5);
    b.insertt(7);
    b.insertt(15);
    b.inorder(b.root);
}
