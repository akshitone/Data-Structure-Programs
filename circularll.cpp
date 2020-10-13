#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Circular:public Node
{
public:
    Node *first;

    Circular()
    {
        first = NULL;
    }
    void append();
    void addafter();
    void display();
    void delet();
    void revers();
};

void Circular::append()
{
    Node *temp,*ptr;
    temp = new Node;
    int info;
    cout<<"Enter data :";
    cin>>info;

    temp->data = info;

    if(first == NULL)
    {
        first = temp;
        temp->next = first;
    }
    else
    {
        ptr = first;
        while(ptr->next != first)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = first;
    }
}

void Circular::display()
{
        Node *temp;
        temp = first;

        if(temp == NULL)
        {
            cout<<"No nodes in single linked list";
        }
        else
        {
            while(temp->next != first)
            {
                cout<<temp->data<<"-->";
                temp = temp->next;
            }
            cout<<temp->data<<"-->";
        }
}

int main()
{
    Circular c;
    int ch;
    do
    {
        cout<<"Enter Choice:";
        cin>>ch;
        switch(ch)
        {
            case 0:
                break;
            case 1:
                c.append();
                break;
            case 3:
                c.display();
                break;
            default:
                cout<<"Invalid Choice";
                break;
        }

    }while(ch != 0);

    return 0;
}
