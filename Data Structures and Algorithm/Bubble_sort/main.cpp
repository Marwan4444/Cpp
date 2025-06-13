#include <iostream>

using namespace std;


void bubbleSort( int arr[] ,int Size)
{
    bool flag = true;


    for(int counter1 =0; counter1 <Size ;counter1++)
    {
        for(int counter2 =0 ; counter2 < Size-counter1 -1 ; counter2++)
        {
            if( arr[counter2]>arr[counter2+1])
            {

                swap(arr[counter2],arr[counter2+1]);
                flag =false;
            }
        }
        if(flag)
        {
            break;
        }
    }


}

void print(int arr[], int size)
{

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

}


int main()
{
      int  arr[5]= {1 ,4,6,2 ,5 };
    print(arr , 5);
    cout<< "array after sorting  \n";
    bubbleSort(arr ,5);
    print(arr , 5);
    return 0;
}
