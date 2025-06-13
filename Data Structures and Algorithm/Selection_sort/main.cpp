#include <iostream>
#include<algorithm>

using namespace std;


void selectionSort(int arr[], int n)
{
	int minIdx;

	for (int i = 0; i < n - 1; i++)
	{
		minIdx = i;

		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIdx])
				minIdx = j;
	            swap(arr[minIdx], arr[i]);

	}
}

void print(int arr[], int size)
{

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

}


int main(){
   int  arr[5]= {1 ,4,6,2 ,5 };
    print(arr , 5);
    cout<< "array after sorting  \n";
    selectionSort(arr ,5);
    print(arr , 5);



    return 0;
}
