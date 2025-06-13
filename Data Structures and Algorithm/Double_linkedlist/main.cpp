#include <iostream>

using namespace std;



class linkedlist
{

    struct node
    {
        int item;
        node * next ;
        node * prev;
    };

    node* first;
    node* last ;
    int lenght;


public:
    linkedlist()
    {
        first =NULL;
        last  =NULL;
        lenght =0;
    }

    bool isEmpty()
    {
        return lenght == 0;
    }

   void  insertFirst( int element)
   {
       node * new_node = new node;
       new_node->item =element;

       if(isEmpty())
       {
           first = last = new_node;
           new_node->next =NULL;
           new_node->prev =NULL;
           lenght++;
       }
       else
       {
           new_node->next =first;
           new_node->prev =NULL;
           first->prev = new_node;
           first =new_node;
           lenght++;

       }

   }


   void insertLast(int element)
   {
        node * new_node = new node;
       new_node->item =element;

       if(isEmpty())
       {
           first = last = new_node;
           new_node->next =NULL;
           new_node->prev =NULL;
           lenght++;
       }
       else
       {
           new_node->next =NULL;
           new_node->prev =last;
           last->next =new_node;
           last = new_node;
           lenght++;

       }
   }


   void Insert(int pos , int element)
   {
       if( pos<0 || pos> lenght)
       {
           cout<<"out of range\n";
       }
       else
       {
           if(pos == 0)
           {
               insertFirst(element);
           }
           else if( pos == lenght)
           {
               insertLast(element);
           }
           else
           {
               node *temp =first;
               node *new_node =new node;
               new_node->item =element;

               for( int counter =0; counter< pos-1; counter++)
               {
                   temp =temp ->next;
               }

               new_node->next =temp->next;
               new_node->prev=temp;
               temp->next->prev =new_node;
               temp->next =new_node;
               lenght++;
           }

       }
   }


   void removeFirst()
   {
       if(isEmpty())
       {
           cout<<" List Empty\n";

       }
       else
       {
           if(lenght ==1)
           {
               last =first =NULL;
               lenght--;
           }
           else
           {
               node * temp =first;
               first =first->next;
               first->prev =NULL;
               temp =NULL;
               lenght--;

           }
       }

   }

   void removeLast()
   {
        if(isEmpty())
       {
           cout<<" List Empty\n";

       }
       else
       {
           if(lenght ==1)
           {
               last =first =NULL;
               lenght--;
           }
           else
           {
               node * temp =last;
               last =last->prev;
               last->next =NULL;
               temp =NULL;
               lenght--;

           }
       }

   }


   void Remove(int element)
   {
       if(isEmpty())
       {
           cout<<"List Empty\n";
       }
       else
       {
          if(first->item == element)
          {
              removeFirst();
          }
          else
          {
              node *temp =first;

              while(temp != NULL  )
              {
                  if(temp->item == element)
                  {
                     break;
                  }

                  temp=temp->next;
              }

              if(temp == NULL)
              {
                  cout<<" not found";
              }
              else if(temp->next == NULL)
              {
                  removeLast();
              }
              else
              {
                  temp->next->prev =temp->prev;
                  temp->prev->next =temp->next;
                  temp =NULL;
                  lenght--;
              }

          }
       }

   }

    void display()
    {
        if(isEmpty())
        {
            cout<<"there are no elements in linked list\n";
        }
        else
        {
            node *temp =first;
            cout<<"Element in Linked list\n";

            while (temp!=NULL)
            {
                cout<<temp->item;
                temp =temp->next;
                if(temp != last->next)
                {
                    cout<<" <- ";
                }
                else
                {
                    continue;
                }

            }
            cout<<"\n";


        }
    }



};
int main()
{
    linkedlist l;
    l.insertFirst(10);
    l.insertFirst(20);
    l.insertFirst(30);
    l.insertFirst(40);
    l.insertFirst(50);
    l.insertLast(5);
    l.Insert(1,32);
    l.display();
    l.removeFirst();
    l.removeLast();
    l.Remove(30);
    l.display();


    return 0;
}
