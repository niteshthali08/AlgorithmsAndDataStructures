#include <vector>
#include <iostream>
#include <string>
using namespace std;

/*
functions: at(), size(), push_back(), pop_back(), empty(), begin(), resize(int new_size)
reference: http://www.cplusplus.com/reference/vector/vector/
Vectors are sequence containers representing arrays that can change in size.
- contiguous storage
- dynamic increases size
- compared to other sequential ds like deques, lists and forward_lists), vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end.
- they perform worst on removing element from middle.
- they take more storage then array
*/
int main(int argc, char const *argv[])
{
	vector<int> myvector (10);   // 10 zero-initialized ints
	// at functio
	for (int i = 0; i < myvector.size(); ++i) // vectora have out of index error check.
	{
		myvector.at(i) = i*10;
	}
	for (int i = 0; i < myvector.size(); ++i) // vectora have out of index error check.
	{
		cout << myvector.at(i) <<" ";
	}
	cout << endl;
	myvector.push_back(100);
	myvector.push_back(200);
	for (int i = 0; i < myvector.size(); ++i) // vectora have out of index error check.
		cout << myvector.at(i) <<" ";
	cout << endl;
	
	myvector.pop_back();
	for (int i = 0; i < myvector.size(); ++i) // vectora have out of index error check.
		cout << myvector.at(i) <<" ";
	cout << endl;
	cout << "now size of vector: " << myvector.size() << endl;
	
	cout << "erasing 6th element " <<endl;
	myvector.erase(myvector.begin());
	cout << "now size of vector: " << myvector.size() << endl;
	for (int i = 0; i < myvector.size(); ++i) // vectora have out of index error check.
	 	cout << myvector.at(i) <<" ";
	cout << endl;
	
	int sum;
	while (!myvector.empty())
  	{
     	sum += myvector.back();
     	myvector.pop_back();
  	}
	cout << "total: " << sum << '\n';
	return 0;
}