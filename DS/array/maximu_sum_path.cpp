
#include <iostream>
using namespace std;
/*
Question from: http://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/
Maximum Sum Path in Two Arrays
Given two sorted arrays such the arrays may have some common elements. Find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays. We can switch from one array to another array only at common elements.

Expected time complexity is O(m+n) where m is the number of elements in ar1[] and n is the number of elements in ar2[].
Input:  ar1[] = {2, 3, 7, 10, 12}, ar2[] = {1, 5, 7, 8}
Output: 35
35 is sum of 1 + 5 + 7 + 10 + 12.
We start from first element of arr2 which is 1, then we
move to 5, then 7.  From 7, we switch to ar1 (7 is common)
and traverse 10 and 12.

Input:  ar1[] = {10, 12}, ar2 = {5, 7, 9}
Output: 22
22 is sum of 10 and 12.
Since there is no common element, we need to take all 
elements from the array with more sum.

Input:  ar1[] = {2, 3, 7, 10, 12, 15, 30, 34}
        ar2[] = {1, 5, 7, 8, 10, 15, 16, 19}
Output: 122
122 is sum of 1, 5, 7, 8, 10, 12, 15, 30, 34
*/

int calculate_sum(int ar1[], int ar2[], int n1, int n2)
{
	// Use modified merge logic to decide the switch between arrays on common element.
	int i = 0, j=0;
	int sum1 = 0, sum2 = 0, max_sum = 0;
	while ( i<n1 && j<n2)
	{
		
		if (ar1[i] > ar2[j])
		{
			sum2 += ar2[j];
			j++;

		}
		else if (ar1[i] < ar2[j])
		{
			sum1 += ar1[i];
			i++;
		}
		else
		{
			(sum1 >= sum2)? max_sum += sum1 + ar1[i] : max_sum += sum2 + ar1[i];
			sum1 = 0;
			sum2 = 0;
			i++;
			j++;
		}
	}
	if ( i == n1)
	{
		while ( j<n2 ) 
		{	
			sum2 += ar2[j];
			j++;
		}
	}
	else
	{
		while ( i<n1 ) 
		{	
			sum1 += ar1[i];
			i++;
		}
	}	
	(sum1 >= sum2)? max_sum += sum1 : max_sum += sum2;
	return max_sum;
}

int main(int argc, char const *argv[])
{
	int ar1[] = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] = {1, 5, 7, 8, 10, 15, 16, 19};
    //int ar1[] = {10, 12};
    //int ar2[] = {5, 7, 9};
    int n1 = sizeof(ar1)/sizeof(int);
    int n2 = sizeof(ar2)/sizeof(int);
    int sum = calculate_sum(ar1, ar2, n1, n2);
    cout << "Maximum Path Sum: "<<sum << endl;
	return 0;
}