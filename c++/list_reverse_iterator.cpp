// C++ reverse iterator
#include <iostream>
#include <list>
using namespace std; 
int main ()
{
  std::list<int> mylist;
  for (int i=1; i<=5; ++i) 
  	mylist.push_back(i);

  std::cout << "mylist backwards:";
  for (list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit) //note ::reverse_iterator, rbegin(), rend(), ++
    std::cout << ' ' << *rit;

  std::cout << '\n';

  return 0;
}