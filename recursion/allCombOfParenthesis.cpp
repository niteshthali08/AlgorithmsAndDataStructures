#include <iostream>
# define MAX_SIZE 100
using namespace std; 
 
void printParenthesis(int pos, int n, int open, int close, char* str)
{
    
  if(close == n) 
  {
    cout << str <<endl;
    return;
  }
  else
  {
    
  	 if(open < n) {
       str[pos] = '{';
       printParenthesis(pos+1, n, open+1, close, str);
    }
    if(open > close) { 	
        str[pos] = '}';
        printParenthesis(pos+1, n, open, close+1, str);
    }
   
  }
}
 
/* driver program to test above functions */
int main()
{
  int n = 3;
  char *str = new char[n*2];
  printParenthesis(0,n,0,0, str);
  return 0;
}