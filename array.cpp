#include<iostream>
using namespace std;
class a
{
    public:
        int arr[10],n,i,j;
    public:
        void accept();
        void display();
        void del();
};
void a::accept()
{
    cout<<"enter how many elements";
    cin>>n;
    cout<<"enter array elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void a::display()
{
    for(i=0;i<n;i++)
    {
        cout<<"  _ ";
    }
    cout<<endl;
    for(i=0;i<n-1;i++)
    {
        cout<<"| "<<arr[i]<<" ";
    }
    for(i=0;i<n;i++)
    {
        if(i=n-1)
        {
            cout<<"| "<<arr[i]<<" |";
        }
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"  _ ";
    }
}

void a::del()
{
    int temp,e,flag=0;
    cout<<"enter the element to be deleted";
    cin>>e;
    for(i=0;i<n;i++)
    {
        if(arr[i]==e)
        {
            temp=arr[i];
            arr[j]=arr[j+1];
            arr[j]=temp;
        }
        flag=1;
    }
    if(flag==0)
    {
        cout<<"elment not found";
    }
    n=n-1;
}
int main()
{
    a ar;
    int ch;
    do
    {
        cout<<"enter choice:";
        cin>>ch;
        switch(ch)
        {
                case 1:ar.accept();
                        break;
                case 2:ar.display();
                        break;
                case 3:ar.del();
                        break;
                default:
                        break;
        }
    }while(ch!=0);
    return 0;
}
