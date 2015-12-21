#include <iostream>
using namespace std;
/*
Question from: Cracking the coding Interviw. 
author = Nitesh Thali
Code to remove duplicate characters from a string without using additiona array.
Straight forward algorithm would be to iterate through all characters and eliminated duplicate characters by checking if it is a duplicate of already found character.
Time Complexity: O(n^2)
*/
void removeDuplicates(char *str)
{
	int len = 0;
	while(str[len]!='\0')
		len++;
	int new_length = 1;
	int j;
	for (int i = 1; i < len; ++i)
	{
	 	for (j = 0; j < new_length; ++j)
	 		if ( str[i] == str[j])
	 			break;
	 	if (j == new_length) 		
			str[new_length++] = str[i];
	}
	str[new_length++] = '\0';
}
int main(int argc, char const *argv[])
{
	char str[100];
	cout << "Enter a string: ";
	cin >> str;
	removeDuplicates(str);
	cout << "String after removing duplicate characters: " << str <<endl;
	return 0;
}