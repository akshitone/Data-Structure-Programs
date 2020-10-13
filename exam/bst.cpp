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
    void search(int);
    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);
};

void Bst::insertt(int ele)
{
    Node *temp;
    temp = new Node;
    temp->data = ele;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        Node *curr;
        Node *prnt;
        prnt = root;
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
void Bst::preorder(Node* r)
{
    cout<<r->data<<"\t";
    if(r->left)
        preorder(r->left);
    if(r->right)
        preorder(r->right);
}
void Bst::postorder(Node* r)
{
    if(r->left)
        postorder(r->left);
    if(r->right)
        postorder(r->right);
    cout<<r->data<<"\t";
}

int main()
{
    Bst b;
    int a;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter element "<<i<<" : ";
        cin>>a;
        b.insertt(a);
    }
    b.search(5);
    cout<<"Inorder Traversal : \n";
    b.inorder(b.root);
    cout<<"\nPreorder Traversal : \n";
    b.preorder(b.root);
    cout<<"\nPostorder Traversal : \n";
    b.postorder(b.root);
}
