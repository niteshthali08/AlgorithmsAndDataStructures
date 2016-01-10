#include <iostream>
using namespace std;
/*
Question from: Cracking the coding Interviw. 
author = Nitesh Thali
1. Code to check if string has all unique characters ?
2. code without additional data structure ? // can be done using a bit vector, but can represent only 32 characters.
Time : O(n), Space: O(1)
*/
bool duplicate_characters(string str)
{
	int a[256]; // because ascii characters are 8 bit long.
	for (int i = 0; i < 256; ++i)
	{
		a[i] = 0;
	}
	//cout << "lenght: "<<str.length()<<endl;
	for (int i = 0; i < str.length(); ++i)
	{
		
		if (a[str[i]])
			return true;
		else
			a[str[i]] +=1;
	}
	return false;
}

bool duplicate_characters_bit_vector(string str)
{
	// 4 bytes -> 32 bits -> 32 characters
	//lets test for small letters.

	int check = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		int location = str[i] - 'a';
		if (( check & 1<< location) > 0) // note bit operator &. using right shift operator to check for dup char.
		check = check | 1<<location; // bit operator or to place one at postition identified by char.	
		
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string str;
	//cout << "size: "<<sizeof(int);
	cout <<"Enter string: ";
	cin >>str;
	bool check = duplicate_characters(str);
	if (check)
		cout << "string contains duplicate characters" << endl;
	else
		cout << "string does not contain duplicate characters" << endl;	
	bool check2 = duplicate_characters_bit_vector(str);
	if (check)
		cout << "string contains duplicate characters <using bit vector>" << endl;
	else
		cout << "string does not contain duplicate characters <using bit vector>" << endl;	
	return 0;
}

