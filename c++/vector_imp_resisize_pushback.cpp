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
	myvector.push_back(5); // this will be 11th element, please note that. This is true even when you resize the vector.
	
	for (int i = 0; i < myvector.size(); ++i) // vectora have out of index error check.
	{
		cout << myvector.at(i) << " ";
	}
	return 0;
}