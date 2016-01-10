#include <iostream>
#include <vector>
using namespace std;
/*
	C++ program to find longest pallindromic substrig.
*/
int len;

void print (vector< vector<bool> > & lps, int len)
{
	for (int i = 0; i < len; ++i)
	{
		
		for (int j = 0; j < len; ++j)
		{
			cout << lps[i][j] << " ";
		}
		cout <<endl;
	}
}
void find_longest_ps(string str, vector< vector<bool> > & lps)
{
	int len = str.size();
	int maxLength = 1	;
	int startIndex = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if (i == j || i == j+1)
				lps[i][j] = true;
			else
				lps[i][j] = false;
		}
	}
	//cout << "len: " << len << endl;
	for (int i = 1; i < len; ++i)
	{
		
		for (int j = 0; j < len - i; ++j)
		{
			
			if (str[j] == str[j+i])
			{
			
				if (lps[j+1][j+i-1] == true)
				{	
					
					//cout << "Inside match ::" << i << maxLength <<endl;
					lps[j][j+i] = true;
					if (i > maxLength )
					{
						// cout << i <<endl;
						// cout << " max " << maxLength << "\n";
						maxLength = i;
						startIndex = j;
					}
				}
			}
			else
			{
				// if (j==2 && j+i == 6)
				// 	{ cout << lps[j][j+i-1] << " " << lps[j+1][j+i] << endl; }
				lps[j][j+i] = false;
			}
		}
	}
	//print (lps, len);
	if (maxLength != 1) maxLength +=1;
	cout <<"Longest Pallindrome length: "<< maxLength << " ";
	cout << "and substring is: " << str.substr(startIndex, maxLength) << "\n";
}

int main()
{
	string s = "a";
	//string s = "banana";
	//string s = "LPASPAL";
	//string s = "aaaa";
	len = s.size();
	vector < vector <bool> > lps (len, vector<bool>(len));
	cout << "String: " << s << endl;

	find_longest_ps(s, lps);
	
}