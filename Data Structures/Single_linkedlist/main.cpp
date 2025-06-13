#include <iostream>

using namespace std;


class linkedlist
{
    struct node
    {
        int item;
        node *next;
    };

    node *head;
    node *tail;
    int Size;


    bool isEmpty()
    {
        return Size ==0;
    }



public:

    linkedlist()
    {
        head =NULL;
        tail =NULL;
        Size =0;
    }

    void insertFirst(int element)
    {
        node *new_node =new node;

        if(isEmpty())
        {
            head = tail =new_node;
            new_node->item =element;
            new_node->next =NULL;
        }
        else
        {
            new_node->item =element;
            new_node->next =head;
            head =new_node;

        }
         Size++;
    }


    void insertLast(int element)
    {
        node *new_node =new node;
        new_node->item =element;

        if(isEmpty())
        {
            head = tail =new_node;
            new_node->next =NULL;
        }
        else
        {
            new_node->next =NULL;
            tail->next =new_node;
            tail =new_node;

        }
        Size++;

    }

    void Insert (int pos , int element)
    {

        if(pos<0 || pos> Size)
        {
            cout<<"out od the range ..!\n";
        }
        else
        {
            if( pos == 0)
            {
                insertFirst(element);
            }
            else if( pos ==Size)
            {
                insertLast(element);
            }
            else
            {
                node *new_node =new node;
                node *temp =head;
                new_node->item =element;

                for(int counter =0; counter <pos-1 ;counter++)
                {
                    temp = temp->next;
                }
                new_node ->next =temp->next;
                temp->next =new_node;

                Size++;

            }
        }
    }


    void removeFirst()
    {

        if(isEmpty())
        {

            cout<<"there are not elements\n";
        }
        else if( Size == 1 )
        {
            head = tail =NULL;
            Size--;
        }
        else
        {
            node * temp =head;
            head =head->next;
            temp =NULL;
            Size--;
        }
    }


    void removeLast()
{
	if (Size== 0)
		cout << "ERROR: EMPTY LIST" << endl;
	else if (Size == 1)
	{
		delete head;
		tail = head = NULL;
		Size--;
	}
	else
	{
		node *temp = head;

		/**** to reach the before last node ****/
		while (temp->next != tail)
			temp = temp->next;
        /***************************************/
		delete tail;
		temp->next = NULL;
		tail = temp;
		Size--;
	}
}


    void Remove( int element)
    {
        if(isEmpty())
        {

            cout<<" liked list is empty \n";
        }
        else
        {
            node * prev , *temp;
            temp = head->next;
            prev = head;

            if( head->item ==element)
            {
                removeFirst();
            }
            else
            {

                /****  to reach the node that consist the element ****/
                while(temp!= NULL)
                {
                    if(temp->item == element)
                    {
                        break;
                    }
                    prev=temp;
                    temp =temp->next;
                }
                /*******************************************************/
                if(temp ==NULL)
                {
                    cout<<"this element not be found\n";
                }
                else
                {


                    if(temp == tail)
                    {
                        removeLast();
                    }
                    else
                    {
                        prev->next =NULL;
                        prev->next =temp->next;
                        Size--;
                    }



                }

            }


        }



    }


    void Reverse()
    {
        node *first ,*secound ,*last;
        last =NULL;
        secound = head;
        first = secound->next;
        tail = head ;
/***
     first ->  next node  ___ secound -> current node ___ last -> previous node

***/
        while( first != NULL)
        {
            first = secound->next;
            secound->next = last ;   // to cut  linked list
            last = secound;
            secound = first;

        }

        head = last ;

    }



    void Search(int element)
{
	node *temp = head;
	int loc = 0;
	while (temp != NULL)
	{
		if (temp->item == element)
			cout<<"Element is at index : " <<loc<<endl ;
		temp = temp->next;
		loc++;
	}
	cout<< " this element  no be found \n" ;
}

    void display()
    {
        if(isEmpty())
        {
            cout<<"there are no elements in linked list\n";
        }
        else
        {
            node *temp =head;
            cout<<"Element in Linked list\n";

            while (temp!=NULL)
            {
                cout<<temp->item;
                temp =temp->next;
                if(temp != tail->next)
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
    l.insertFirst(50);
    l.display();
    l.Reverse();
    l.display();

    return 0;
}
