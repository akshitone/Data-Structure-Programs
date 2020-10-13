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

class Single:public Node
{
public:
    Node* head;

    Single()
    {
        head = NULL;
    }
    void append();
    void addafter();
    void display();
    void delet();
    void revers();
};

void Single::append()
{
        Node *temp;
        temp=new Node;
        int info;
        cout<<"Enter data :";
        cin>>info;

        temp->data = info;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *ptr;
            ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
}

void Single::addafter()
{
        Node *temp,*ptr;
        temp = new Node;
        int loc,counter=0,i=1;
        int info;
        cout<<"Enter location :";
        cin>>loc;
        cout<<"Enter data :";
        cin>>info;
        temp->data = info;
        temp->next = NULL;
        ptr = head;
        while(ptr != NULL)
        {
            counter++;
            ptr = ptr->next;
        }
        if(loc > counter)
        {
            cout<<"Invalid Location"<<endl;
        }
        else if(loc == 1)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            ptr = head;
            while(i < loc-1)
            {
                ptr = ptr->next;
                i++;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
}

void Single::display()
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
                cout<<temp->data<<"-->";
                temp = temp->next;

            }
        }
}

void Single::delet()
{
    Node *temp,*ptr,*del;
    int loc,counter,i=1;
    cout<<"Enter location :";
    cin>>loc;
    ptr = head;
    while(ptr != NULL)
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
        temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        ptr = head;
        while(i < loc-1)
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

void Single::revers()
{
    Node *p,*q;
    int temp,counter,i,j,k;
    while(p != NULL)
    {
        counter++;
        p = p->next;
    }
    i=0;
    j=counter - 1;
    p=q=head;
    while(i < j)
    {
        k=0;
        while(k < j)
        {
            q = q->next;
            k++;
        }
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        i++;
        j--;
        p = p->next;
        q = head;
    }
}

int main()
{
    Single s;
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
