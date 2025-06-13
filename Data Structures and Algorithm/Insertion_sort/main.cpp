#include <iostream>

using namespace std;

void insertionSort( int arr[] , int Size)
{
    int key , temp;
                                                        /// 0 1 2 3 4 5
    for( int counter =1  ; counter < Size ; counter++)  /// 4 3 5 0 1 8
    {
        key = arr[counter];
        temp =counter -1;
/** to put max number in last **/
        while( temp>=0 && arr[temp]>key)
        {
            arr[temp+1] = arr[temp];
            temp--;
        }


        arr[temp+1] =key ;  /// to put min nubmer in first
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
    insertionSort(arr ,5);
    print(arr , 5);

    return 0;
}
