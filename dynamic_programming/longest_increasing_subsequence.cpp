#include <iostream>
using namespace std;
/* program to find Longest Increasinng Subsequence; for example, say a = {10, 22, 9, 33, 21, 50, 41, 60, 80} 
LIS length is 6 and it is {10, 22, 33, 50, 60, 80}
Time complexity O(n^2), Space complexity O(n)
*/
void printLIS(int a[], int result[], int index)
{
	if(index == 0)
	{
		cout << a[index] << " ";
		return;
	}
		
	printLIS(a, result, result[index]);
	cout << a[index] << " ";
}
void BottomUpLIS(int a[], int n)
{
	//cout << "length: " << n << endl;
	int lis[n]; // for storing lenght of LIS
	int result[n];	// for storing elements present in LIS
	
	int max = 1;
	for (int i = 0; i < n; ++i)
	{
		result [i] = 0;
		lis[i] = 1;
	}	
	for (int i = 1; i < n; ++i)
	 {
	 	for (int j = 0; j < i; ++j)
	 	{
	 		if(a[j] <= a[i] && max < (1 + lis[j]))
	 		{
	 			max = 1 + lis[j];
	 			lis[i] = max;
	 			result[i] = j;
	 		}
	 		
	 	}
	 } 
	 cout << "Length of LIS: " << lis[n-1] << endl;
	 // find index where LIS is max.
	 max = -999;
	 int index;

	 for (int i = 0; i < n; ++i)
	 {
	 	if (max < result[i])
	 		{
	 			max = result [i];
	 			index = i;
	 		}
	 }
	 //cout << max <<endl;
	 printLIS(a, result, index);
	 cout <<endl;

}

int main(int argc, char const *argv[])
{
	int a[] = {10, 22, 9, 33, 21, 50, 41, 60, 80}; //	 LIS length is 6 and LIS is {10, 22, 33, 50, 60, 80}
	//int a[] = {1,2,3,4,5,6,7,8,9};
	//int a[] = {9,8,7,6,5,4,3,2,1};
	
	BottomUpLIS(a, sizeof(a)/sizeof(int));
	return 0;
}
