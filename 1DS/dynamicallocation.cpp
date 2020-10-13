#include<iostream>

using namespace std;

int main()
{
    int sizee;
    int *ptr;

    cout<<"Enter Size";
    cin>>sizee;

    ptr = new int[sizee];

    cout<<"Enter Values";

    int i=0;
    while(i<sizee)
    {
        cin>>ptr[i];
        i++;
    }
    i=0;
    while(i<sizee)
    {
        cout<<ptr[i];
        i++;
    }
}
