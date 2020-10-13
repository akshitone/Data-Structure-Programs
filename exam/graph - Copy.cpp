#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    void read(Node *ad[],int n)
    {
        Node *newnode;
        int i,j,k,val;
        for(i=0;i<n;i++)
        {
            Node *last = NULL;
            cout<<"Enter no of neighbours of "<<i+1<<" : ";
            cin>>k;
            for(j=0;j<k;j++)
            {
                cout<<"Enter value of "<<j+1<<" neighbours "<<i+1<<" : ";
                cin>>val;
                newnode = new Node;
                newnode->data = val;
                newnode->next = NULL;
                if(ad[i]==NULL)
                {
                    ad[i]=newnode;
                }
                else
                {
                    last->next = newnode;
                }
                last=newnode;
            }
        }
    }

    void print(Node *ad[],int n)
    {
        Node *ptr = NULL;
        int i,j;
        for(i=0;i<n;i++)
        {
            ptr=ad[i];
            cout<<"The neighbours of "<<i+1<<" are :";
            while(ptr != NULL)
            {
                cout<<ptr->data<<"\t";
                ptr = ptr->next;
            }
            cout<<endl;
        }
    }

};

int main()
{
    Node n;
    int i,j,k,nodes;
    cout<<"Enter Nodes :";
    cin>>nodes;

    Node *adj[nodes];
    for(i=0;i<nodes;i++)
    {
        adj[i] = NULL;
    }
    n.read(adj,nodes);
    n.print(adj,nodes);
    return 0;
}
