#include<iostream>
#define sizee 10
using namespace std;

class Queue
{
public:
    int frontt=-1,rear=-1;
    int que[sizee];

    void insertt()
    {
        int data;
        if(rear == sizee-1)
        {
            cout<<"Queue overflow";
        }
        else
        {
            if(frontt==-1)
            {
                frontt=0;
            }
            cout<<"Enter element:";
            cin>>data;
            rear++;
            que[rear]=data;
        }
    }
    void deletee()
    {
        int ele;
        if(frontt==rear)
        {
            frontt=-1;
            rear=-1;
        }
        else
        {
            ele=que[frontt];
            frontt++;
            cout<<"Deleted element :"<<ele;
        }
    }
    void display()
    {
        for(int i=frontt;i<=rear;i++)
        {
            cout<<que[i]<<endl;
        }
    }
};

int main()
{
    Queue q;
    int ch;
    do
    {
        cin>>ch;
        switch(ch)
        {
            case 0:
                break;
            case 1:
                q.insertt();
                break;
            case 2:
                q.display();
                break;
            case 3:
                q.deletee();
                break;
        }

    }while(ch != 0);
    return 0;
}
