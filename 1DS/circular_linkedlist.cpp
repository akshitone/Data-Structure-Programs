#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
class Node {
    public:
   int data;
   Node* next;
   Node(){
       next = NULL;
   }

};
class Circular{
    public:
    Node* head;
    Circular(){
        head = NULL;
    }

void add() {
   Node *temp;
   temp = new Node;
   Node *ptr = head;
   cout<<"Enter Your Data ==> ";
   cin>>temp->data;
   temp->next = head;
   if (head!= NULL) {
      while (ptr->next != head)
         ptr = ptr->next;
      ptr->next = temp;
   } else
      temp->next = temp;
      head = temp;
}
void display() {
   Node* ptr;
   ptr = head;
   do {
      cout<<ptr->data <<" ";
      ptr = ptr->next;
   } while(ptr != head);
}
};
int main() {
   Circular c;
   int ch;
   while(1)
    {
        SetConsoleTitle("By Viral Shastri"); //Set Title
        cout<<"1.Push Elements"<<endl;
        cout<<"2.Pop Element"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter Your Choice ==> ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                c.add();
                break;

            case 2:

                break;

            case 3:
                c.display();
                break;

            case 4:
                exit(1);
                break;

            default:
                cout<<"Invalid Choice";

        }
        system("pause"); //Pause Execution
        system("cls"); //Clear Screen
    }

   return 0;
}
