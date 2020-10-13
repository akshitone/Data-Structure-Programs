#include<iostream>
#include<stdlib.h>
using namespace std;


class Array
{
public:
    int b[10],a[50],n;
    void acceptLength()
    {
        cout<<"Enter length of an Array :";
        cin>>n;
    }
};

class Operation : public Array
{
    int add,pos,i,j,k,temp,mid,first=0,last=n-1,num;
public:
    void acceptArray()
    {
        cout<<"Enter Value :";
        cin>>add;
        cout<<"Enter Position :";
        cin>>pos;
        b[k]=pos;
        k++;
        for(j=0;j<n;j++)
        {
            if(b[j]==pos)
            {
                a[pos]=add;
                for(k=pos;k<n;k++)
                {
                    a[k+1]=a[k];
                }
            }
            else
            {
                a[pos-1]=add;
            }
        }

        /*for(i=0;i<n;i++)
        {
            cin>>a[i];
        }*/

    }
    void displayArray()
    {
        cout<<"Your Array"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"| "<<a[i]<<" |"<<endl;
        }
    }
    void sortArray()
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[i]<a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            cout<<"| "<<a[i]<<" |"<<endl;
        }
    }
    int searchArray()
    {
        cout<<endl<<"Enter number that you want to search:";
        cin>>num;
        while(first<=last)
        {
            mid=(first+last)/2;
            if(a[mid]==num)
            {
                return mid+1;
                break;
            }
            else if(a[mid]<num)
            {
                first=mid+1;
            }
            else
            {
                last=mid-1;
            }
        }
        if(first>last)
        {
            return 0;
        }
    }
};

int main()
{
    Operation op;
    int ch,pos;
    while(1)
    {
        cout<<"----MENU----"<<endl;
        cout<<"1.Length of your Array"<<endl;
        cout<<"2.Insertion"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.sort"<<endl;
        cout<<"5.search"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your Choice :";
        cin>>ch;
        switch(ch)
        {
            case 1:
                op.acceptLength();
                break;
            case 2:
                op.acceptArray();
                break;
            case 3:
                op.displayArray();
                break;
            case 4:
                op.sortArray();
                break;
            case 5:
                pos=op.searchArray();
                if(pos==0)
                {
                    cout<<"Number is not found";
                }
                else
                {
                    cout<<" number is found at this position :"<<pos;
                }

                break;
            case 6:
                exit(1);
            default:
                cout<<"Invalid Choice";
                return 0;
        }
    }
    return 0;
}
