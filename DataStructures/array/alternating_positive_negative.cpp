#include <iostream>
using namespace std;
/*
REFERENCE: http://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance.
Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

Example:

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0} 
Constrints : O(1) space
*/
void rotate(int arr[], int i, int j)
{

	int temp = arr[i], next;
	arr[i] = arr[j];
	for (int k = i+1; k <= j; ++k)
	{
		next = arr[k];
		arr[k] = temp;
		temp = next;
	}

}
void alternate(int arr[], int n)
{
	int flag;
	int j;
	flag = (arr[0] > 0)? 1 :0;
	for (int i = 0; i < n; ++i)
	{ 
		if(flag) // that means i am expecting a positive number
		{
			if( arr[i] < 0 )
			{
				j = i +1;
				while (arr[j] < 0 && j<n) // find first positive number in order
					j++;
				if (j == n)
					return;
				else
					rotate(arr, i, j);
			}
		}
		else
		{
			if( arr[i] > 0 )
			{
				cout << "found positive numebr" <<endl;
				j = i +1;
				while (arr[j] >= 0 && j<n) // find first positive number in order, 0 is considered as positive.
					j++;
				if (j == n)
					return;
				else
						rotate(arr, i, j);
			}
		}
		flag = !flag;
	}
}
int main(int argc, char const *argv[])
{
	//int arr[] = {1, 2, 3, -4, -1, 4};
	int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};	
	//int arr[] = {-5, -2, -5, -2, -4, -7, -1, -8, -8};	
	int n = sizeof(arr)/sizeof(int);
	cout << "Original Array: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] <<" ";
	}
	alternate(arr, n);
	cout <<endl;
	cout << "Alternate_positive_negative: " ;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] <<" ";
	}
	cout << endl;
	return 0;
}