#include <iostream>
#include <vector>
using namespace std;
/*
	C++ program to find longest pallindromic sub sequence
*/
int len;
using namespace std;
int max (int a, int b)
{
	int max;
	(a>b)? max = a: max=b;
	return max;
}
void print (vector< vector<int> > & lps, int len)
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
void find_longest_ps(string str, vector< vector<int> > & lps)
{
	int len = str.size();
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if (i ==j)
				lps[i][j] = 1;
			else
				lps[i][j] = 0;
		}
	}
	for (int i = 1; i < len; ++i)
	{
		for (int j = 0; j < len - i; ++j)
		{
			if (str[j] == str[j+i])
			{
				//cout << j <<" " << j+i <<endl;
				//cout << "match" <<endl;

				lps[j][j+i] = 2 + lps[j+1][j+i-1];
			}
			else
			{
				// if (j==2 && j+i == 6)
				// 	{ cout << lps[j][j+i-1] << " " << lps[j+1][j+i] << endl; }
				lps[j][j+i] = max(lps[j][j+i-1], lps[j+1][j+i]);
			}
		}
	}
	//print (lps, len);
}

int main()
{
	string s = "LPASPAL";
	//string s = "aaaa";
	len = s.size();
	vector < vector <int> > lps (len, vector<int>(len));
	cout << "String: " << s << endl;

	find_longest_ps(s, lps);
	cout <<"Longest Pallindrome length: "<< lps[0][len-1] << endl;
}