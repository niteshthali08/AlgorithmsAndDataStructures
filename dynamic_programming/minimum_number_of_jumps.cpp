#include <iostream>
using namespace std;
/*
Given an array, find the minimum number of jumps required to reach the end of an array.
Time Complexity O(n^2)
*/
void print (int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " "; 
	}
	cout <<endl;
}
int find_min_jumps(int a[], int n)
{
	if (n==0 || n==1)
		return 0;
	int jumps[n], min = 99999;
	jumps[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if ((i-j) <= a[j])
			{
				if ((1 + jumps[j]) < min)
					min = 1+ jumps[j];
			}
		}
		jumps[i] = min;
		min = 99999;
		//cout << "Jumps: " ;
		//print (jumps, n);
	}
	
	if(jumps[n-1] == 99999)
		return -1;
	return jumps[n-1];

}
int main(int argc, char const *argv[])
{
	int a[] = {1, 4, 3, 7, 1, 2, 6, 7, 6, 10};
	//int a[] = {1};
	//int a[] = {5,5,5,5};
	//int a[] = {1,5,3,2,1,0,1, 0, 12};
	int n = sizeof(a)/sizeof(int);
	cout << "Array: "; print(a, n);
	cout << "Minimum Jumps: " << find_min_jumps(a, n) << endl;
	int r = find_min_jumps(a, n);
	return 0;
}