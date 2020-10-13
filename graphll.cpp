#include <iostream>
using namespace std;
class VertexNode
{
    public:
    int data;
    VertexNode* next;
};
class AdjList:public VertexNode
{
    public:
    VertexNode *head;
};
class Graph:public AdjList
{
    public:
        int V;
        AdjList* a;
    public:
        Graph(int V)
        {
            this->V = V;
            a = new AdjList [V];
            for (int i = 0; i < V; ++i)
                a[i].head = NULL;
        }
        void addEdge(int src, int dest)
        {
        	VertexNode* newNode = new VertexNode;
            newNode->data = dest;
            newNode->next = NULL;

            newNode->next = a[src].head;
            a[src].head = newNode;

			newNode = new VertexNode;
            newNode->data = src;
            newNode->next = NULL;

            newNode->next = a[dest].head;
            a[dest].head = newNode;
        }
        void printGraph()
        {
            int i;
            for (i = 0; i < V; ++i)
            {
                VertexNode* tmp = a[i].head;
                cout<<"\nAdjacency list of vertex "<<i<<" :"<<endl;
                while (tmp)
                {
                    cout<<i<<" -> "<<tmp->data<<"\n";
                    tmp = tmp->next;
                }
            }
        }
};
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

    gh.printGraph();

    return 0;
}

