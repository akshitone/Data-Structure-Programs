#include<iostream>
using namespace std;
#define n 10
class Stack
{
    int a[n],ele;
    int top = -1;
public:
    void push(int);
    int pop();
    void display();
};
void Stack::push(int ele)
{
    if(top == n-1)
    {
        cout<<"Stack is overflow."<<endl;
    }
    else
    {
        top++;
        a[top] = ele;
    }
}
int Stack::pop()
{
    if(top == -1)
    {
        cout<<"Stack is underflow"<<endl;
        return 0;
    }
    else
    {
        ele = a[top];
        top--;
    }
    return ele;
}
void Stack::display()
{
    if(top == -1)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            cout<<"| "<<a[i]<<" |"<<endl;
        }
    }
}
int main()
{
    Stack s;
    int ch,ele;
    do
    {
        cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter element :";
                cin>>ele;
                s.push(ele);
                break;
            case 2:
                ele=s.pop();
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
