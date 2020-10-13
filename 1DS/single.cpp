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

class List:public Node
{
public:
    int ele;
    Node* head;
    List()
    {
        head = NULL;
    }
    void insertt();
    void Addafter();
    void deletee();
    void display();
};

void List::insertt()
{
    Node* temp;
    temp = new Node;
    cout<<"Enter element :";
    cin>>ele;
    temp->data = ele;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Node* ptr;
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void List::Addafter()
{
    int c=0,pos,i=1;
    Node *temp,*ptr;
    temp = new Node;
    ptr = head;
    cout<<"Enter element and Position :";
    cin>>ele>>pos;
    temp->data = ele;
    temp->next = NULL;
    while(ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }
    if(pos > c)
    {
        cout<<"Invalid position";
    }
    else if(pos == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        ptr = head;
        while(i < pos - 1)
        {
            ptr=ptr->next;
            i++;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void List::deletee()
{
    Node *ptr,*temp,*del;
    int pos,c=0,i=1;
    ptr = head;
    cout<<"Enter position :";
    cin>>pos;
    while(ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }
    if(pos > c)
    {
        cout<<"Invalid position";
    }
    else if(pos == 1)
    {
        temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        ptr = head;
        while(i < pos-1)
        {
            ptr = ptr->next;
            i++;
        }
        del = ptr->next;
        ptr->next = del->next;
        del->next = NULL;
        free(del);
    }
}

void List::display()
{
    Node *ptr;
    ptr = head;
    while(ptr != NULL)
    {
        cout<<ptr->data<<"-->";
        ptr = ptr->next;
    }
}

int main()
{
    List l;
    int ch;
    do
    {
        cout<<"\n1.Insert\n2.Add at position\n3.Delete\n4.Display\n";
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
                l.Addafter();
                break;
            case 3:
                l.deletee();
                break;
            case 4:
                l.display();
            default:
                break;
        }

    }while(ch != 0);
}
