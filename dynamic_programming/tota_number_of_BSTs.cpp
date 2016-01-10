#include <iostream>
#include <vector>
using namespace std;
/*
C++ program to compute unique BSTs possible given an iteger n
*/
int computeBST(int n, std::vector<int> &v)
{
	if (n<0) return 0;
	if (n==0 || n==1) 
		{	cout << " returning 0 \n";
			return 1; //n=0 null tree
		}		
	int total = 0;	
	cout << " total = 0, ";
	for (int i = 0; i < n; ++i)
	{
		cout << "i= "<<i <<endl;
		if (v[i] == -1)
			{
			cout << " first call: " << i;
			v[i] = computeBST(i,v);
		}
		if (v[n-i-1] == -1)
			{	cout << " second call " << n-i-1;
				v[n-i-1] = computeBST(n-i-1, v);
			}
		
		total += v[i] * v[n-i-1];
		cout << " total now: " << total <<endl;
	}
	cout << " returning total " <<endl;
	return total;	
}

int main(int argc, char const *argv[])
{
	int n = 6;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		v[i] = -1;
	}
	cout << "hellp\n";
	cout <<computeBST(n, v);
	return 0;
}