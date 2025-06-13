#include<iostream>
//#include<algorithm>
using namespace std;
void bubbleSort(int arr[], int n)
{
	bool flag = true; 

	for (int i = 0; i < n - 1; i++)
	{                                              //  0  1  2  3  4  5
		for (int j = 0; j < n - i - 1; j++)       //  30,20,40, 5,60, 2 
		{
			if (arr[j] > arr[j + 1])              
			{
				swap(arr[j], arr[j + 1]);
				flag = false;
			}
			
		}
		if (flag == true)
			break;

	}

}



int binarySearch(int arr[], int l, int h, int element)
{
	while (l <= h) {
		
		int m = (l + h) / 2;

		                                  //0 1 2  3  4  5
		if (arr[m] == element)           // 2 5 20 30 40 60
			return m;
        
		if (arr[m] > element)
			
		h = m - 1;

		else

		l = m + 1;

	}

	return -1;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{

	int arr[] = { 30,20,40,5,60,2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<" arr before sorting :";
	printArray(arr, n);
	/* bubbleSort*/
	bubbleSort(arr, n);
	cout<<" arr after sorting  :";
	printArray(arr, n);
	
	/* binary search*/
	int num;
	
	cout << "Enter an Integer :";
	cin >> num;

	int result = binarySearch(arr, 0, n - 1, num);
	if(result == -1)
		cout << "The Number : (" << num << ") Was Not Found." << endl;
	else
		cout << "The Number : (" << arr[result] << ") Was Found At Index : (" << result << ")" << endl;
		
	return 0;

}

