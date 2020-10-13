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
    int temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}


