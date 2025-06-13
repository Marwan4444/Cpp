#include <iostream>
#include <cassert>

using namespace std;

struct nodeType
{
   int     info;
   nodeType  *left;
   nodeType  *right;
};


class binarySearchTreeType
{

private:
	nodeType *root;

void  clear(nodeType* &p)
        {
        if(p != NULL)
        {
            clear(p->left);
            clear(p->right);
            delete p;
            p = NULL;
        }

        }

void inorder(nodeType *p)
        {
            nodeType *temp =root;
       while(temp != NULL)
       {
            temp= temp->left;
            cout<<temp->info<<" ";

            temp= temp->right;
            temp = root;


       }
        }
void preorder(nodeType *p)
        {
        if(p != NULL)
        {
            cout<<p->info<<" ";
            preorder(p->left);
            preorder(p->right);
        }
        }

void postorder(nodeType *p)
    {
	if(p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->info<<" ";
	}
    }

    /******/
int height(nodeType *p)
    {
	if(p == NULL)
		return 0;
	else
		return 1 + max(height(p->left), height(p->right));
    }

    /*****/
int max(int x, int y)
    {
	if(x >= y)
		return x;
	else
		return y;
    }
    /*****/

int nodeCount(nodeType *p)
    {
	if(p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->left) + nodeCount(p->right);
    }
    /*****/

int leavesCount(nodeType *p)
    {
	if(p == NULL)
		return 0;
	else if ((p->left == NULL) && (p->right == NULL))
		return 1;
	else
		return leavesCount(p->left) + leavesCount(p->right);
    }
    /*****/



	public:

binarySearchTreeType()
{
	root = NULL;
}


bool isEmpty()
{
	return (root == NULL);
}


void inorderTraversal()
{
	inorder(root);
}


void preorderTraversal()
{
	preorder(root);
}


void postorderTraversal()
{
	postorder(root);
}


int treeHeight()
{
	return height(root);
}


int treeNodeCount()
{
	return nodeCount(root);
}


int treeLeavesCount()
{
	return leavesCount(root);
}


void  clearTree()
{
	clear(root);
}

~binarySearchTreeType()
{
	clear(root);
}


bool search(int item)
{
	nodeType *current = root;

	while(current != NULL)
	{
		if(current->info == item)
			return true;
		else if(current->info > item)
			current = current->left;
        else
            current = current->right;
	}

    return false;
}



void deleteFromTree(nodeType* &p)
{
     nodeType *current;    //pointer to traverse
                                     //the tree
     nodeType *trailCurrent;   //pointer behind current
     nodeType *temp;        //pointer to delete the node

	 if(p->left == NULL && p->right == NULL)
     {
		delete p;
		p = NULL;
     }
     else if(p->left == NULL)
     {
		temp = p;
        p = p->right;
        delete temp;
     }
     else if(p->right == NULL)
     {
		temp = p;
        p = p->left;
        delete temp;
     }
     else
     {
        current = p->left;
        trailCurrent = NULL;

        while(current->right != NULL)
        {
            trailCurrent = current;
            current = current->right;
        }//end while

        p->info = current->info;

        if(trailCurrent == NULL) //current did not move;
                                 //current == p->left; adjust p
           p->left = current->left;
        else
           trailCurrent->right = current->left;

        delete current;
     }//end else
}//end deleteFromTree


void insert(int item)
{
    nodeType *current;  //pointer to traverse the tree
    nodeType *trailCurrent; //pointer behind current
    nodeType *newNode;  //pointer to create the node

    newNode = new nodeType;
    assert(newNode != NULL);
    newNode->info = item;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL)
       root = newNode;
    else
    {
       current = root;

       while(current != NULL)
       {
           trailCurrent = current;

           if(current->info == item)
           {
              cout<<"The insert item is already in the list -- ";
              cout<<"duplicates are not allowed."<<endl;
              return;
           }
           else
              if(current->info > item)
                 current = current->left;
              else
                 current = current->right;
       }//end while

       if(trailCurrent->info > item)
          trailCurrent->left = newNode;
       else
          trailCurrent->right = newNode;
   }
}

//this function only determines the node to be deleted
void remove(int item)
{
	nodeType *current;  //pointer to traverse the tree
	nodeType *trailCurrent; //pointer behind current

	if(root == NULL)
	{
		cout<<"Cannot delete from the empty tree."<<endl;
		return;
	}
	if(root->info == item)
	{
		deleteFromTree(root);
		return;
	}

	//if you get here, then the item to be deleted is not the root
	trailCurrent = root;

	if(root->info > item)
		current = root->left;
	else
		current = root->right;

	//search for the item to be deleted.
	while(current != NULL)
	{
		if(current->info == item)
			break;
		else
		{
			trailCurrent = current;
			if(current->info > item)
				current = current->left;
			else
				current = current->right;
		}
	}// once the while is done, current points to either NULL or to the node to be deleted

	if(current == NULL)
		cout<<"The delete item is not in the tree."<<endl;
	else if(trailCurrent->info > item)
		deleteFromTree(trailCurrent->left);
	else
		deleteFromTree(trailCurrent->right);
}




};
int main()
{
    binarySearchTreeType b;
    b.insert(10);
    b.insert(20);
    b.insert(5);
    b.insert(15);
    b.insert(1);
    b.insert(50);
    //b.insert(5);
	cout<<b.treeHeight()<<endl;
	// b.preorderTraversal();
	b.inorderTraversal();

	return 0;
}
