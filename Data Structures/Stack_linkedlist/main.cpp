#include <iostream>

using namespace std;

template<class t>

class Stack
{

    struct node
    {
        t item ;
        node *next_node;

    };
    node *top;

public:

    Stack()
    {
       top =NULL;
    }


     void push(t new_item)
     {
         node *new_node =new node;   // create node to put new item in new node
         new_node->item = new_item ; // put new item in new node
         new_node->next_node=top;    // next node of new node must be old top
         top=new_node;               //  new top is new node

     }

     void pop()
     {
         if(top== NULL)
         {
            cout<<"stack is empty\n";
         }
         else
         {
             cout<< " the element : "<<top->item<<" is removed \n";
             node *temp= top;
             top=top->next_node;
             temp = temp->item =NULL;
             delete temp;
         }

     }

     void pop(t &item_removed)
     {
        if(top== NULL)
         {
            cout<<"stack is empty\n";
         }
         else
         {
             item_removed =top->item;
             node *temp= top;
             top=top->next_node;
             temp = temp->item =NULL;
             delete temp;
         }

     }

     void getTop(t &top_item)
     {

            if(top== NULL)
             {
                cout<<"stack is empty\n";
             }
             else
             {
                 top_item =top->item;

             }
     }

    void display()
    {
        node *temp=top;
        cout<<"Element in Stack :\n";
        while(temp!=NULL)
        {
           cout<<"|\t"<<temp->item<<"\t|\n";
           temp=temp->next_node ;
        }
        cout<<"-----------------\n";

    }

};

int main()
{
    Stack<int> s;
    s.push(100);
    s.push(98);
    s.push(93);
    s.push(10);
    s.push(1);
    s.display();

    return 0;
}
