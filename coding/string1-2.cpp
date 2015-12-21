#include <iostream>
using namespace std;
/*
Question from: Cracking the coding Interviw. 
author = Nitesh Thali
code to reverse C-style string (null terminated)
Time: O(n), Space: O(1)
*/

void reverse(char* str)
{
	int len = 0;
	while(str[len]!= '\0')
		len++;
	int front =0, end = len-1;
	while(front < end)
	{
		char t = str[front];
		str[front++] = str[end];
		str[end--] = t;

	}
}
int main(int argc, char const *argv[])
{
	char str[100];
	cout << "Enter a string: ";
	cin >> str;
	reverse(str);
	cout << "String reversed: " <<str << endl;	
	return 0;
}