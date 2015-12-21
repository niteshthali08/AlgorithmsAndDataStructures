#include <iostream>
using namespace std;
/* 
author: Nitesh Thali
merge sort uses divide and conquer strtegy to sort the elements.
Running time: O(n), Space complexity: O(n)
*/
void merge(int a[], int low, int mid, int high)
{
	//cout << "low:mid:high " << low << ":"<< mid <<":"<< high<<endl;
	int l1 = mid - low +1;
	int l2 = high - mid;
	int b1[l1], b2[l2];
	for (int i = 0; i <l1; ++i)
	{
		b1[i] = a[low + i];
	}
	for (int j = 1; j <=l2; ++j)
	{
		b2[j-1] = a[mid + j];
	}
	int i = 0, j = 0;
	int k = low;
	while (i < l1 && j<l2)
	{
		if(b1[i] > b2[j])
		{
			a[k++] = b2[j++];

		}
		else
		{
			a[k++] = b1[i++];
		}
	}
	if (i == l1)
		{
			
			for (int l = j; l<l2; l++)
				a[k++] = b2[l];
		}
	else
	{
		for (int l = i; l<l1; l++)
				a[k++] = b1[l];
	}	
	// cout<< "array: ";
	// for (int i = low; i <= high; ++i)
	// {
	// 	cout << a[i]<< " ";
	// }
	// cout << endl;
}	


void merge_sort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high)/2;
		merge_sort(a,low, mid);
		merge_sort(a, mid+1, high);
		merge(a,low, mid, high);
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {30, 10, 70, 60, 50, 90, 0, 20};
	//int a[] = {10,20,30,40,50,55,60, 5};
	//int a[] = {70,60,50,40,30,20,10};
	//cout << "length: " << sizeof(a)/sizeof(int)-1 <<endl;
	merge_sort(a, 0,sizeof(a)/sizeof(int)-1);// //note -1 here... important to make index calculation easy
	
	cout << "sorted: ";
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i) 
	 	cout << a[i] <<" ";
	 cout <<endl;
	return 0;
}