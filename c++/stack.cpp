#include <iostream>
#include <stack>

using namespace std;
/*
	reference: http://www.cplusplus.com/reference/stack/stack/pop/
	exploring functions like push(), pop() => returns void, empty(), top() => return value on top of stack
*/

int main(int argc, char const *argv[])
{
	stack <int> mystack;

	for (int i = 10; i < 100; i = i + 10)
	{
		mystack.push(i);
	}
	
	cout << "Top is :" << mystack.top() << endl;
	cout << "Poping out elements one by one:" << endl;
	while (!mystack.empty())
	{
		cout << mystack.top() << " ";
		mystack.pop();
	}
	cout << endl;
	return 0;
}