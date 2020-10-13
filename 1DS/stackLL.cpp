#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Stackll:public Node
{
public:
    int ele;
    Node* top = NULL;
    void insertt();
    void deletee();
    void display();
};

void Stackll::insertt()
{
    Node *temp;
    temp = new Node;
    cout<<"Enter element :";
    cin>>ele;
    temp->data = ele;
    temp->next = top;
    top = temp;
}

void Stackll::deletee()
{
    Node *temp;
    if(top == NULL)
    {
        cout<<"Stack is empty";
    }
    else
    {
        temp = top;
        top = temp->next;
        temp->next = NULL;
        free(temp);
    }
}

void Stackll::display()
{
    Node *ptr;
    if(top == NULL)
    {
        cout<<"Stack is empty";
    }
    else
    {
        ptr = top;
        while(ptr != NULL)
        {
            cout<<ptr->data<<"-->";
            ptr = ptr->next;
        }
    }
}

int main()
{
    Stackll l;
    int ch;
    do
    {
        cout<<"\n1.Insert\n2.Delete\n3.Display\n";
        cout<<"Enter Choice :";
        cin>>ch;
        switch(ch)
        {
            case 0:
                break;
            case 1:
                l.insertt();
                break;
            case 2:
                l.deletee();
                break;
            case 3:
                l.display();
            default:
                break;
        }

    }while(ch != 0);
}
