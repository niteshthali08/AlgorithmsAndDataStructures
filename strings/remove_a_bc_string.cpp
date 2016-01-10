#include <iostream>
#include <list>

using namespace std;
/*
Reference: http://www.geeksforgeeks.org/remove-a-and-bc-from-a-given-string/
author : Nitesh
Prgram to remove b and ac from a input string in one pass over the string without extras storage.
acbac   ==>  ""
aaac    ==>  aa
ababac  ==>   aa
bbbbd   ==>   d

Note for this string: aacacc, it outputs ac correctly but we may have requirement to remove it as well.
*/
void remove(char *str, int n)
{
	int j=0;
	bool prevA = false;
	for(int i=0; i<n; i++)
	{
		if( j>1 && str[j-2] == 'a' && str[j-1] == 'c')
			j = j - 2;	
		if (prevA && str[i] == 'c')
		{
			j--;
			prevA = false;
		}
		else if (str[i] == 'b')
		{
			continue;
		}
		else if (str[i] == 'a')
		{
			prevA = true;
			str[j++] = str[i];
		}
		else
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}
int main(int argc, char const *argv[])
{
	//char str[] = "aacacc";
	char str[] = "ababac";
	cout << "original: "<< str << endl;
	remove(str, sizeof(str));
	cout << "modified: " <<str << endl;
	return 0;
}