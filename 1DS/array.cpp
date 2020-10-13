#include<iostream>
#include<graphics.h>
using namespace std;

class Array
{
public:
    int arr[50];
    int n;
    void accept();
    void display();
    void deletee();
};

void Array::accept()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void Array::display()
{
    for(int i=0;i<n*2;i++)
    {
        cout<<"- ";
    }
    cout<<"-";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"| "<<arr[i]<<" ";
    }
    cout<<"|"<<endl;
    for(int i=0;i<n*2;i++)
    {
        cout<<"--";
    }
    cout<<"-";
}
int main()
{
    Array a;
    a.accept();
    a.display();

    // gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file
    int gd = DETECT, gm;

    // initgraph initializes the graphics system
    // by loading a graphics driver from disk
    initgraph(&gd, &gm, "");

    // line for x1, y1, x2, y2
    line(150, 150, 450, 150);

    // line for x1, y1, x2, y2
    line(150, 200, 450, 200);

    // line for x1, y1, x2, y2
    line(150, 250, 450, 250);

    getch();

    // closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system .
    closegraph();
}
