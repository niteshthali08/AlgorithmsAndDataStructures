#include <iostream>
#include <string>
using namespace std;
 
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     cout <<"----- return------: " << a << endl;
   else
   {
       for (i = l; i <= r; i++)
       {
          cout << "swap before: " << l << " " << i << endl;
          swap((a+l), (a+i));
          cout << "permute(" << a <<", " << l+1 <<", " << r << ")" <<endl;
          permute(a, l+1, r);
          cout << "swap after: " << l <<" " << i << endl;
          swap((a+l), (a+i)); //backtrack
       }
   }
}
 
int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}