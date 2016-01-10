#include <iostream>
using namespace std;
/*
Question from: Cracking the coding Interviw. 
author = Nitesh Thali
Code to check if two string are anagrams or not
Time Complexity: O(n), Space: O(n)
*/
bool anagrams(string str1, string str2)
{
	int len = str1.length();
	int a[256];
	for (int i = 0; i < 256; ++i)
	{
		a[i] = 0;
	}
	for (int i = 0; i < len; ++i)
	{
		a[str1[i]] ++;
	}
	len = str2.length();
	for (int i = 0; i < len; ++i)
	{
		a[str2[i]] --;		
	}
	for (int i = 0; i < 256; ++i)
	{
		if(a[i] != 0) return false;
	}
	
	return true;
}

int main(int argc, char const *argv[])
{
	string str1, str2;
	cout << "Enter string1: ";
	cin >> str1;
	cout << "Enter string2: ";
	cin >> str2;
	if(anagrams(str1, str2))
		cout << "Strigs are anagrams!" << endl;
	else
		cout << "Strigs are NOT anagrams!" << endl;
	return 0;
}