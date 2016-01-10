#include <iostream>
using namespace std;
/*
author : Nitesh Thali
Outout from first call to partition after completion of each pass in a loop. 
The element at i+1 is at the correct place after first call.
input [5,7,1,3,9,8,2,4]
i= -1 j= 0 5 7 1 3 9 8 2 4 
i= -1 j= 1 5 7 1 3 9 8 2 4 
i= 0  j= 2 1 7 5 3 9 8 2 4 
i= 1  j= 3 1 3 5 7 9 8 2 4 
i= 1  j= 4 1 3 5 7 9 8 2 4 
i= 1  j= 5 1 3 5 7 9 8 2 4 
i= 2  j= 6 1 3 2 7 9 8 5 4 
Swapping pivot with i+1
Before swapping pivot: 1 3 2 7 9 8 5 4  
After swapping pivot: 1 3 2 4 9 8 5 7 
*/
void swap (int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}
void print (int a[], int start, int end)
{
	for (int i = start; i <=end ; ++i)
	{
		cout<< a[i] << " ";
	}
	cout <<endl;
}
int partition(int a[], int start, int end)
{
	int pivot = a[end];
	int i = start -1;
	for (int j = start; j <= end-1; ++j)
	{
		 if (a[j] <= pivot)
		 {
		 	i = i+1;
		 	swap (a[i], a[j]);
		 }
		 //cout << "i= " <<i <<"j= " <<j << " ";
		 //print (a, start, end);
	}
	//cout << "Before swapping pivot: ";
	//print (a, start, end);
	swap (a[i+1], a[end]);
	//cout << "After swapping pivot: ";
	//print (a, start, end);
	return i+1; // note returning i+1;
}

void qucikSort(int a[], int start, int end)
{
	if (start < end)
	{
		int q = partition(a, start, end);
		qucikSort(a, start, q-1);
		qucikSort(a, q+1, end);
	}
}

int main(int argc, char const *argv[])
{
	//int a[] = {5,7,1,3,9,8,2,4};
	//int a[] = {2,2,2};
	//int a[] = {1,2,3,4,5,6,7,8,9};
	//int a[] = {9,8,7,6,5,4,3,2,1};
 	int a[] = {10, 10, 20,50,50, 60,30, 100, 80, 50};
 	int len = sizeof(a)/sizeof(int);
	
	cout << "Array: ";
	print(a, 0, len-1);
	cout <<endl;
	qucikSort(a, 0, len-1);
	cout << "Sorted: ";
	print (a, 0,len-1);
	cout <<endl;
	return 0;
}


/*
output for sorted array.
Array: 1 2 3 4 5 6 7 8 9 

i= 0j= 0 1 2 3 4 5 6 7 8 9 
i= 1j= 1 1 2 3 4 5 6 7 8 9 
i= 2j= 2 1 2 3 4 5 6 7 8 9 
i= 3j= 3 1 2 3 4 5 6 7 8 9 
i= 4j= 4 1 2 3 4 5 6 7 8 9 
i= 5j= 5 1 2 3 4 5 6 7 8 9 
i= 6j= 6 1 2 3 4 5 6 7 8 9 
i= 7j= 7 1 2 3 4 5 6 7 8 9 
Before swapping pivot: 1 2 3 4 5 6 7 8 9 
After swapping pivot: 1 2 3 4 5 6 7 8 9 
i= 0j= 0 1 2 3 4 5 6 7 8 
i= 1j= 1 1 2 3 4 5 6 7 8 
i= 2j= 2 1 2 3 4 5 6 7 8 
i= 3j= 3 1 2 3 4 5 6 7 8 
i= 4j= 4 1 2 3 4 5 6 7 8 
i= 5j= 5 1 2 3 4 5 6 7 8 
i= 6j= 6 1 2 3 4 5 6 7 8 
Before swapping pivot: 1 2 3 4 5 6 7 8 
After swapping pivot: 1 2 3 4 5 6 7 8 
i= 0j= 0 1 2 3 4 5 6 7 
i= 1j= 1 1 2 3 4 5 6 7 
i= 2j= 2 1 2 3 4 5 6 7 
i= 3j= 3 1 2 3 4 5 6 7 
i= 4j= 4 1 2 3 4 5 6 7 
i= 5j= 5 1 2 3 4 5 6 7 
Before swapping pivot: 1 2 3 4 5 6 7 
After swapping pivot: 1 2 3 4 5 6 7 
i= 0j= 0 1 2 3 4 5 6 
i= 1j= 1 1 2 3 4 5 6 
i= 2j= 2 1 2 3 4 5 6 
i= 3j= 3 1 2 3 4 5 6 
i= 4j= 4 1 2 3 4 5 6 
Before swapping pivot: 1 2 3 4 5 6 
After swapping pivot: 1 2 3 4 5 6 
i= 0j= 0 1 2 3 4 5 
i= 1j= 1 1 2 3 4 5 
i= 2j= 2 1 2 3 4 5 
i= 3j= 3 1 2 3 4 5 
Before swapping pivot: 1 2 3 4 5 
After swapping pivot: 1 2 3 4 5 
i= 0j= 0 1 2 3 4 
i= 1j= 1 1 2 3 4 
i= 2j= 2 1 2 3 4 
Before swapping pivot: 1 2 3 4 
After swapping pivot: 1 2 3 4 
i= 0j= 0 1 2 3 
i= 1j= 1 1 2 3 
Before swapping pivot: 1 2 3 
After swapping pivot: 1 2 3 
i= 0j= 0 1 2 
Before swapping pivot: 1 2 
After swapping pivot: 1 2 
Sorted: 1 2 3 4 5 6 7 8 9 

*/