#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *llink;
    Node *rlink;
};
class Tree:public Node
{
public:
    Node *root=NULL;

    void insertt()
    {
        int info;
        cout<<"enter element";
        cin>>info;
        Node *temp, *ptr;

        temp=new Node;
        temp->llink=NULL;
        temp->rlink=NULL;
        temp->data=info;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            ptr=root;
            while(1)
            {
                if(info<ptr->data)
                {
                    if(ptr->llink!=NULL)
                    {
                        ptr=ptr->llink;
                    }
                    else
                    {
                        ptr->llink=temp;
                    }
                }
                else if(info>ptr->data)
                {
                    if(ptr->rlink!=NULL)
                    {
                        ptr=ptr->rlink;
                    }
                    else
                    {
                        ptr->rlink=temp;
                    }
                }
                else
                {
                    cout<<"element is already present in the tree"<<endl;
                    break;
                }
            }
        }
    }
};

int main()
{
    Tree t;
    int ch;
    do
    {
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 0:
                break;
            case 1:
                t.insertt();
                break;
            default:
                cout<<"Invalid choice";
                break;
        }

    }while(ch!=0);
}
