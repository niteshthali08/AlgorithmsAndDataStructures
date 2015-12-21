#include <iostream>
using namespace std;
/* 
author: Nitesh Thali
max heap code to sort array in decreasing order, in place sorting.
Time complexity for buildiing a max heap: O(n)
Time complexity to sort: O(n*lgn)
*/
int left (int i)
{
	return 2*i + 1;	
}
int right (int i)
{
	return 2*i + 2;
}
void swap(int *first, int *last)
{
	int t = *first;
	*first = *last;
	*last = t;
	//cout << "inside swap function" <<*first <<" "<<*last;
}
void max_heapify(int a[], int index, int size)
{
	int l = left(index);
	int r = right(index);
	int largest = index;
	if( l <= size and a[l] > a[largest])
		largest = l;
	if (r <=size  and a[r] > a[largest])
		largest = r;
	if (largest != index)
	{
		swap(&a[index], &a[largest]);
		max_heapify(a, largest, size);
	}
 }
void build_max_heap(int a[], int length)
{ 	// start calling max heapify function from size/2; heapify will take care of leaf nodes.
	
	for (int i = length/2 - 1; i >=0; --i)
	{   //cout << "building max heap" <<i <<endl;
		max_heapify(a, i, length); 
	}
}


int main(int argc, char const *argv[])
{
	int a[] = {50, 60, 10, 100, 20, 90, 70};
	//int a[] = {10};
	//int a[] = {10,20,30,40,50,60,70};
	//int a [] = {70,60,50,40,30,20,10};
	int length = sizeof(a)/sizeof(int);
	//cout << length << endl;
	build_max_heap(a, length-1);
	int size = length -1;
	for (int i = length - 1; i > 0; --i) 
	{		
			
			swap(&a[0], &a[i]);
			max_heapify(a, 0, --size);
		
	}
	cout <<"sorted: ";
	for (int i = 0; i < length; ++i)
	{
		cout << a[i] << " ";void swap(int *first, int *last);
	}
	cout << endl;
	return 0;
}