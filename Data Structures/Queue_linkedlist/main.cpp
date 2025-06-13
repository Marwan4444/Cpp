#include <iostream>

using namespace std;

class Queueu
{
    struct node
    {
        int item;
        node *next;
    };

    int Size;
    node *Front;
    node *rear;
    /*** empty -> true           not empty -> false ***/
    bool isEmpty()
    {
        return Size == 0;
    }

public:

    Queueu()
    {
        Front = NULL;
        rear = NULL;
        Size =0;
    }

    void enqueue(int element)
    {
        if(isEmpty())
        {
            Front = new node;
            Front->item = element;
            Front->next =NULL;
            rear = Front;
            Size++;
        }
        else
        {
            node *new_node =new node;
            new_node->item =element;
            new_node->next = NULL;
            rear->next = new_node;
            rear= new_node;
            Size++;
        }
    }

    void dequeue()
    {
        if(isEmpty())
        {
           cout<<"Queue is empty \n" ;
        }
        else
        {
            if( Size == 1)
            {
                Front =rear =NULL;
                Size--;
            }
            else
            {
                node *temp =Front;
                Front =Front->next;
                temp->next=NULL;
                temp=NULL;
                Size--;
            }


        }
    }

    int getfront()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty \n" ;
            return false;
        }
        else
        {
            return Front->item;
        }
    }

    int getrear()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty \n" ;
            return false;
        }
        else
        {
            return rear->item;
        }
    }


    /*** clear all element ***/
        void clearQueue()
        {
            node *temp = Front;

            while(Front != NULL)
            {
                temp= Front;
                Front = Front->next;
                temp =NULL;
            }

            rear=NULL;
            Size =0;

        }

        void display()
        {


        node *temp = Front;
        if(isEmpty())
        {
            cout<<"Queue is empty \n" ;

        }
        else
        {

            cout<<"Element in Queue \n";
            while(temp != NULL)
            {
                cout<<"-------";
                temp=temp->next;

            }
            temp=Front;
            cout<<"\n<- ";
            /************* print element ********************/
            while(temp != NULL)
            {

                cout<<temp->item<<"   ";
                temp=temp->next;

            }
            cout<<"<-\n";
            temp=Front;
             /***************************************/

            while(temp != NULL)
            {
                cout<<"-------";
                temp=temp->next;

            }
            cout<<"\n";

        }



        }


};

int main()
{
   Queueu q;
   q.enqueue(100);
   q.enqueue(200);
   q.enqueue(300);
   q.enqueue(400);
   q.enqueue(500);
   q.display();
  cout<<"front element :" << q.getfront();



    return 0;
}
