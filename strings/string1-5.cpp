#include <iostream>
#include <string>
using namespace std;

/*
Question from: Cracking the coding Interviw. 
author = Nitesh Thali
Method to replace all spaces in a string with '%20';
Time Complexity: O(n), Space: O(n)
*/
void replace_spaces(char str[])
{
	//count spaces;
	int len = 0, spaces = 0;
	while(str[len]!= '\0')
	{
		if (str[len] == ' ')
			spaces++;
		len++;
	}
	//each space will be replaced with 3 characteres therefore length of the new string will be changed.
	int new_length = len + spaces*2;
	// start forming new string from back side to avoid overwritting.
	str[new_length] = '\0';
	for (int i = len-1; i >=0 ; --i)
	{
		
		if(str[i] == ' ')
		{
			str[--new_length] = '0';
			str[--new_length] = '2';
			str[--new_length] = '%';
		}
		else
			str[--new_length ] = str[i];
	}
}

int main(int argc, char const *argv[])
{
	char str[100] = "I love ASU";
	cout << str <<endl;
	replace_spaces(str);
	cout << "String after replacement: " << str << endl; 
	return 0;
}