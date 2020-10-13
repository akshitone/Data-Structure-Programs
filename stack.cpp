#include<iostream>
using namespace std;

class Stack
{
private:
    int top;
    int arr[10];
public:
    Stack()
    {
        top=-1;
        for(int i=0;i<10;i++)
        {
            arr[i]=0;
        }
    }
    void push(int);
    int pop();
    void display();
};

void Stack::push(int data)
{
    if(top==9)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        top++;
        arr[top]=data;
    }
}

int Stack::pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        int popValue=arr[top];
        arr[top]=0;
        top--;
        return popValue;
    }
}

void Stack::display()
{
    for(int i=9;i>=0;i--)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    Stack s;
    int data,option;
    do
    {
        cout<<"---Menu---"<<endl;
        cout<<"0.end()"<<endl;
        cout<<"1.push()"<<endl;
        cout<<"2.pop()"<<endl;
        cout<<"3.display()"<<endl;
        cin>>option;

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter Value :";
                cin>>data;
                s.push(data);
                break;
            case 2:
                cout<<"Poped value is "<<s.pop()<<endl;
                break;
            case 3:
                cout<<"Stack"<<endl;
                s.display();
                break;
            default:
                cout<<"Enter valid option";
        }

    }while(option!=0);
    return 0;
}
