#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
    public:int info;
        Node *next,*rear,*fron;
    public:
        Node()
        {
            rear=NULL;
            fron=NULL;
        }
};
class que:public Node
{
    public: Node *rear=NULL,*fron=NULL;
    public:
        void create(int);
        void del();
        void display();
};
void que::create(int data)
{
    Node *temp;
    temp=new Node;
    temp->info=data;
    temp->next=NULL;
    if(fron==NULL)
    {
        fron=temp;
    }
    else
    {
        rear->next=temp;
    }
    rear=temp;
}
void que::del()
{
    Node *temp;
    if(fron==NULL)
    {
        cout<<"Queue underflow";
        return;
    }
    else
    {
        temp=fron;
        cout<<"deleted element is:"<<temp->info<<endl;
        fron=fron->next;
        free(temp);
    }
}
void que::display()
{
    Node *q;
    q=fron;
    if(fron==NULL)
    {
        cout<<"Queue underflow"<<endl;
    }
    while(q!=NULL)
    {
        cout<<q->info<<endl;
        q=q->next;
    }
}
int main()
{
    que Q;
    int m,ch;
    while(1)
    {
        cout<<"1.create"<<endl;
        cout<<"2.delete"<<endl;
        cout<<"3.display"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"enter element:"<<endl;
                    cin>>m;
                    Q.create(m);
                    break;
            case 2:Q.del();
                    break;
            case 3:Q.display();
                    break;
        }

    }
    return 0;
}
