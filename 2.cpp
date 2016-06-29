#include <iostream>
using namespace std;
void printResult(int s, int t, char st[][10])
{
	int max = 0, curr_max = 0, count = 0;
	for(int i=0; i<s-1; i++)
	{
		for (int j=i+1; j<s; j++)
		{
			curr_max = 0;
			for(int k=0; k<t; k++)
			{
			
				if (st[i][k] ==1 || st[j][k] == 1)
					curr_max++;
			}
			if (curr_max > max)
			{
				max = curr_max;
				count = 1;
			}
			else if (curr_max == max)	
				count++;
		}
	}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int s, t;
    cin >>s >>t;
    char st[s][t+1];
    for (int i=0; i<s; i++)
        cin >>st[i];
    //for (int i=0; i<s; i++)
        //cout <<st[i] <<endl;
   
    int max = 0, curr_max = 0, count = 0;
	for(int i=0; i<s-1; i++)
	{
		for (int j=i+1; j<s; j++)
		{
			curr_max = 0;
			for(int k=0; k<t; k++)
			{
			
				if (st[i][k] == '1' || st[j][k] == '1')
					curr_max++;
			}
			if (curr_max > max)
			{
				max = curr_max;
				count = 1;
			}
			else if (curr_max == max)	
				count++;
		}
	}
   cout <<max <<endl;
   cout <<count;
    return 0;
}