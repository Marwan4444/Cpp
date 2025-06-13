#include <iostream>

using namespace std;

int const MAX =100;
class Stack
{
    int item[MAX];
    int top;


    public:
    Stack()
    {
        top =-1;
    }

    void push(int element)
    {
        if(top >= (MAX-1) )
        {
            cout<<"Stack is full\n";
        }
        else
        {
            top++;
            item[top]=element;

        }

    }

    void pop()
    {
        if(top<0)
        {
            cout<<"Stack is empty\n";
        }
        else
        {
            top--;
        }
    }


    void pop(int &top_element)
    {
        if(top<0)
        {
            cout<<"Stack is empty\n";
        }
        else
        {
            top_element= item[top];
            top--;
        }
    }


    void getTop(int& top_element)
    {
        if (top<0)
        {
            cout << "Stack is empty \n" ;
        }
        else
        {
            top_element = item[top];
            cout <<"Top element :"<< top_element << endl;
        }
    }

    void print()
    {
        if(top<0)
        {
            cout<<"Stack is empty\n";
        }
        else
        {
            cout<<"Element in Stack :\n";

            for(int counter =top; counter>=0 ; counter --)
            {
                cout<<"|\t"<<item[counter]<<"\t|\n";
            }
            cout<<"-----------------\n";



        }
    }


};

int main()
{
    int pop, top;
    Stack obj;
    obj.push(10);
    obj.push(12);
    obj.push(23);
    obj.push(50);
    obj.print();
    obj.pop();
    obj.getTop(top);
    obj.pop(pop);
    obj.getTop(top);
    obj.print();



    return 0;
}

