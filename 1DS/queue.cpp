#include<iostream>
using namespace std;
#define n 10
class Queue
{
    int q[n],ele;
    int rear = -1;
    int frontt = -1;
public:
    void insertt(int);
    int deletee();
    void display();
};
void Queue::insertt(int ele)
{
    if(rear == n-1)
    {
        cout<<"Queue is overflow";
    }
    else
    {
        if(frontt == -1)
        {
            frontt++;
        }
        rear++;
        q[rear] = ele;
    }
}
int Queue::deletee()
{
    ele = q[frontt];
    if(frontt == rear)
    {
        cout<<"Queue is underflow";
        frontt = -1;
        rear = -1;
        return 0;
    }
    else
    {
        frontt++;
    }
    return ele;
}
void Queue::display()
{
    cout<<"front :"<<frontt<<endl;
    cout<<"rear :"<<rear<<endl;
    if(frontt == -1 && rear == -1)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"| ";
        for(int i=frontt;i<=rear;i++)
        {
            cout<<q[i]<<" | ";
        }
    }
}
int main()
{
    Queue s;
    int ch,ele;
    do
    {
        cout<<"\n1.Insert"<<endl<<"2.Delete"<<endl<<"3.Display"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter element :";
                cin>>ele;
                s.insertt(ele);
                break;
            case 2:
                ele=s.deletee();
                if(ele != 0)
                {
                    cout<<"Poped element :"<<ele<<endl;
                }
                break;
            case 3:
                s.display();
                break;
            default:
                break;
        }

    }while(ch != 0);
    return 0;
}
