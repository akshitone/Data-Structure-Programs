#include <iostream>
using namespace std;
class cQueue{
    public:
    int cqueue[5];
    int front,rear,n=5;
    cQueue()
    {
        front=rear=-1;
    }

    void insertCQ(int val) {
   if ((front == 0 && rear == n-1) || (front == rear+1)) {
      cout<<"Queue Overflow \n";
      return;
   }
   if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      if (rear == n - 1)
      rear = 0;
      else
      rear = rear + 1;
   }
   cqueue[rear] = val ;
}
void deleteCQ() {
   if (front == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<cqueue[front]<<endl;

   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == n - 1)
      front = 0;
      else
      front = front + 1;
   }
}
void displayCQ() {
   int f = front, r = rear;
   if (front == -1) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are :\n";
   if (f <= r) {
      // while (f <= r){
      //    cout<<cqueue[f]<<" ";
      //    f++;
      // }
      for(int i=f;i<=r;i++)
      {
         cout<<cqueue[i]<<" ";
      }
   } else {
      // while (f <= n - 1) {
      //    cout<<cqueue[f]<<" ";
      //    f++;
      // }
      for(int i=f;i<=n-1;i++)
      {
         cout<<cqueue[i]<<" ";
      }
      f = 0;
      // while (f <= r) {
      //    cout<<cqueue[f]<<" ";
      //    f++;
      // }
      for(int i=f;i<=r;i++)
      {
         cout<<cqueue[i]<<" ";
      }
   }
   cout<<endl;
}
};
int main() {
    cQueue c;
   int ch, val;
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";
do {
   cout<<"Enter choice : "<<endl;
   cin>>ch;
   switch(ch) {
      case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>val;
         c.insertCQ(val);
         break;

      case 2:
         c.deleteCQ();
         break;

      case 3:
         c.displayCQ();
         break;

      case 4:
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect!\n";
   }
} while(ch != 4);
   return 0;
}
