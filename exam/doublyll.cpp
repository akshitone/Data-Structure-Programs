#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next,*prev;
};

class Double:public Node
{
public:
    Node *head;
    Double()
    {
        head = NULL;
    }
    void append();
    void addafter();
    void display();
    void delet();
    void revers();
};

void Double::append()
{
    Node *temp,*ptr;
    temp = new Node;
    int info;
    cout<<"Enter data :";
    cin>>info;

    temp->data = info;
    temp->next = NULL;
    temp->prev = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}

void Double::addafter()
{
    Node *temp,*ptr;
    temp = new Node;
    int counter,info,loc,i=1;

    cout<<"Enter location :";
    cin>>loc;
    cout<<"Enter data :";
    cin>>info;

    temp->data = info;
    temp->next = NULL;
    temp->prev = NULL;

    ptr = head;
    while(ptr->next != NULL)
    {
        counter++;
        ptr = ptr->next;
    }
    if(loc > counter)
    {
        cout<<"Invalid location";
    }
    else if(loc == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        ptr=head;
        while(i < loc - 1)
        {
            ptr = ptr->next;
            i++;
        }
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
    }
}

void Double::display()
{
        Node *temp;
        temp = head;

        if(temp == NULL)
        {
            cout<<"No nodes in single linked list";
        }
        else
        {
            while(temp !=NULL)
            {
                cout<<"("<<temp->prev<<","<<temp->data<<","<<temp->next<<")"<<"-->";
                temp = temp->next;

            }
        }
}

void Double::delet()
{
    Node *temp,*ptr,*del;
    int loc,counter=0,i=1;
    cout<<"Enter location :";
    cin>>loc;
    ptr=head;
    while(ptr != NULL)
    {
        counter++;
        ptr = ptr->next;
    }
    cout<<counter;
    if(loc > counter)
    {
        cout<<"Invalid location";
    }
    else if(loc == 1)
    {
        temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        ptr = head;
        while(i < loc)
        {
            ptr = ptr->next;
            i++;
        }
        del = ptr->next;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        ptr->next = NULL;
        ptr->prev = NULL;
        free(ptr);
    }
}

void Double::revers()
{

}

int main()
{
    Double s;
    int ch;
    do
    {
        cout<<"\n\n---Menu---"<<endl;
        cout<<"1.insert"<<endl;
        cout<<"2.insert at position"<<endl;
        cout<<"3.display"<<endl;
        cout<<"4.delete"<<endl;
        cout<<"5.reverse"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;

        switch(ch)
        {
            case 0:
                break;
            case 1:
                s.append();
                break;
            case 2:
                s.addafter();
                break;
            case 3:
                s.display();
                break;
            case 4:
                s.delet();
                break;
            case 5:
                s.revers();
                break;
            default:
                cout<<"Invalid choice";
                break;
        }

    }while(ch != 0);
    return 0;
}
