#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
public:
    void NewNode(int);
};

class Vertexlist:public Node
{
public:
    Node* vertexhead;
};

class Graph:public Vertexlist
{
public:
    int vertex;
    Vertexlist* vlist;
public:
    int CreateGraph(int);
    void InsertNode(Graph*,int,int);
};

int Graph::CreateGraph(int n)
{
    Graph* temp;
    temp = new Graph;

    temp->vertex = n;

    temp->vlist = new Vertexlist[n+1];

    for(int i=0;i<n+1;i++)
    {
        temp->vlist[i].vertexhead = NULL;
    }

    return temp;
}

void Node::NewNode(int ele)
{
    Node* temp;
    temp = new Node;

    temp->data = ele;
    temp->next = NULL;

    return temp;
}

void Graph::InsertNode(Graph *G,int v1,int v2)
{
    Node *node1 = NewNode(v1);
    Node *node2 = NewNode(v2);
    Node *temp = new Node;

    if(G->vlist[v2].vertexhead == NULL)
    {
        G->vlist[v2].vertexhead = node1;
    }
    else
    {
        node1->next = G->vlist[v2].vertexhead;
        G->vlist[v2].vertexhead = node1;
    }

    if(G->vlist[v1].vertexhead == NULL)
    {
        G->vlist[v1].vertexhead = node2;
    }
    else
    {
        node2->next = G->vlist[v1].vertexhead;
        G->vlist[v1].vertexhead = node2;
    }
}

int main()
{
    Graph g;
    int v,e;
    cout<<"Enter no of vertexs :";
    cin>>v;

    g.CreateGraph(v);

    cout<<"Enter no of edges :";
    cin>>e;

    int edge[e][2];

    for(int i=0;i<e;i++)
    {
        cout<<"\nEnter the vertex pair for edge : "<<i+1;
        cout<<"\nV(1) : ";
        cin>>edge[i][0];
        cout<<"\nV(2) : ";
        cin>>edge[i][1];

        InsertNode(G, edge[i][0], edge[i][1]);
    }

    cout<<"\n\nIncidence : ";
    for(int i=0;i<v;i++)
    {
        cout<<"\n\tV("<<i+1<<") -> { ";
        while(G->vlist[i+1].vertexhead != NULL)
		{
			cout<<G->vl[i+1].vertexhead->data<<"  ";
			G->vlist[i+1].vertexhead = G->vlist[i+1].vertexhead->next;
		}
		cout<<"}";
    }

    return 0;
}
