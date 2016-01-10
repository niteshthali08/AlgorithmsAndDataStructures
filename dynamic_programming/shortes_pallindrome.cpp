#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
Problem is to find a shortest pallindrome given a string by prepending characters to the string.
This algo uses KMP pattern match longest prefix suffix array to find the shortest pallindrome.
*/
void calculate_lps(string pal, int lps[])
{
	// KMP lps calcultion - will return array with containing values indicating longest proper prefix which is also a proper suffix
	int len = pal.size();
	int j = 0;
	int i = 1;
	lps[0] = 0;
	//cout << "len inside: " << len <<endl;
	while (i < len)
	{
		if (pal[j] == pal[i])
		{
			lps[i] = 1+lps[i-1];
			i++;
			j++;
		}
		else
		{
			if(j != 0)
			{
				j = lps[j-1];
			}
			else // j==0
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
void print(int a[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << " ";
	}
	cout <<endl;
} 
string find_pallindrome(string str)
{
	
	string rev = str;
	std :: reverse(rev.begin(), rev.end());
	string pal = str + rev;
	int len = pal.size();
	//cout << "size: " <<len <<endl;
	int lps[len];
	calculate_lps(pal, lps);
	//cout << len/2 << len-lps[len-1] << "\n";
	//cout << pal << "\n";
	string sub = pal.substr(len/2, len/2 - lps[len-1]);
	return sub+str;
}

int main(int argc, char const *argv[])
{
	string str = "abab";
	//string str = "banana";
	//string str = "ananab";
	string str = "a";
	string str = "abc";
	cout << "Pallindrome: " << find_pallindrome(str) << endl;
	return 0;

}