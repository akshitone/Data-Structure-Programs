#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Head:public Node
{
public:
    Node *head;
};
class Graph:public Head
{
public:
    int v;
    Head *a;
    Graph(int v)
    {
        this->v = v;
        a = new Head[v];
        for(int i=0;i<v;i++)
        {
            a[i].head = NULL;
        }
    }
    void addEdge(int,int);
    void display();
};

void Graph::addEdge(int src,int dest)
{
    Node *newnode;
    newnode = new Node;

    newnode->data = dest;
    newnode->next = NULL;

    newnode->next = a[src].head;
    a[src].head = newnode;

    newnode = new Node;

    newnode->data = src;
    newnode->next = NULL;

    newnode->next = a[dest].head;
    a[dest].head = newnode;

}

void Graph::display()
{
    for(int i=0;i<v;i++)
    {
        Node *ptr;
        ptr = a[i].head;
        cout<<endl<<"Adj list of vertex "<<i<<" : "<<endl;
        while(ptr)
        {
            cout<<i<<" --> "<<ptr->data<<endl;
            ptr = ptr->next;
        }
    }
}

int main()
{
    Graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);

    gh.display();
    return 0;
}
