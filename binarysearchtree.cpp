#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};
class BinaryTree:public Node
{
public:
    Node *root;

    BinaryTree()
    {
        root = NULL;
    }

    Node* insertt(int info,Node* temp)
    {
        if(temp == NULL)
        {
            temp = new Node;
            temp->data = info;
            temp->left = temp->right = NULL;
        }
        else if(info < temp->data)
        {
            temp->left = insertt(info,temp->left);
        }
        else
        {
            temp->right = insertt(info,temp->right);
        }
        return temp;
    }

    void inoder(Node* temp)
    {
        if(temp == NULL)
        {
            return;
        }
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }


    void insertt(int info)
    {
        root = insertt(info,root);
    }

    void display()
    {
        inorder(root);
        cout<<endl;
    }
};

int main()
{
    BinaryTree t;
    t.insertt(20);
    t.insertt(10);
    display();
}
