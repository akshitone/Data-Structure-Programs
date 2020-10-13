#include <iostream>
using namespace std;

int main()
{
    int a[10],i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    int mini,temp;
    for(i=0;i<n-1;i++)
    {
        mini=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[mini])
            {
                mini=j;
                temp=a[i];
                a[i]=a[mini];
                a[mini]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}

