#include<iostream>
using namespace std;

int main()
{
    int a[10];
    int i,n,pos;
    for(i=0;i<3;i++)
    {
        cout<<"Enter Position :";
        cin>>pos;
        cout<<"Enter Value :";
        cin>>n;
        a[pos-1]=n;
    }
    for(i=0;i<3;i++)
    {
        cout<<a[i]<<endl;
    }
}
