#include <iostream>

using namespace std;

const int Max =100;
class Queue
{
    int Front ;
    int rear ;
    int Size;
    int arr[Max];

public:
    Queue()
    {
        Front =0;
        rear =Max-1;
        Size =0;
    }

    /*** empty -> true      not empty -> false ***/
    bool isEmpty()
    {
       return Size == 0;
    }

     /*** Full -> true      not Full -> false ***/
    bool isFull()
    {
          return Size == Max;
    }
   void enqueue(int element)
    {
        if(isFull())
        {
            cout<<"Queue is full \n";
        }
        else
        {
            rear =(rear+1)%Max;
            arr[rear] = element;
            Size++;
        }

    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty\n";
        }
        else
        {
            Front=(Front+1)%Max;
            Size--;
        }

    }

    int getFront()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty\n";
        }
        else
        {
            return arr[Front];

        }

    }

    int getRear()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty\n";
        }
        else
        {
            return arr[rear];

        }

    }

    void display()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty\n";
        }
        else
        {
            for(int counter =Front; counter!= rear ;counter=(counter+1)%Max)
            {
                cout<<"-------";
            }
            cout<<"\n<- ";

            /**** print all elements ****/
            for(int counter =Front; counter!= rear ;counter=(counter+1)%Max)
            {
                cout<<arr[counter]<<"   ";
            }
            cout<<arr[rear]<<" <-\n";
            /****************************/

            for(int counter =Front; counter!= rear ;counter=(counter+1)%Max)
            {
                cout<<"-------";
            }
            cout<<"\n";


        }
    }



};


int main()
{
    Queue q;
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.display();


    return 0;
}
