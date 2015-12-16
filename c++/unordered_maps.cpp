#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
/* 
	reference : http://www.cplusplus.com/reference/unordered_map/unordered_map/insert/
	to run => g++ -std=c++11 file_name
*/
int main(int argc, char const *argv[])
	{
		unordered_map<string, double> myrecipe, mypantry = {{"milk",2.0},{"flour",1.5}};
		pair <string, double> myshopping ("baking powder", 0.3);

		myrecipe.insert(myshopping);
		myrecipe.insert (make_pair<std::string,double> ("eggs",6.0)); // move insertion
		myrecipe.insert (mypantry.begin(), mypantry.end());  // range insertion
		myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );    // initializer list insertion

		// check if key exists.
		unordered_map <string, double>::const_iterator result = myrecipe.find("milk"); // this return an iterator.
		if ( result == myrecipe.end())
			cout << "milk key not found"<< endl;
		else 
			cout << "key foound: " <<result->first << " : " << result->second <<endl; 	  
		
		result = myrecipe.find("nitesh");
		if ( result == myrecipe.end())
			cout << "nitesh key not found"<< endl;
		else 
			cout << "key foound: " <<result->first << " : " << result->second <<endl; 	  

		// delete a key from map
		myrecipe.erase ( myrecipe.begin() );      // erasing by iterator
  		myrecipe.erase ("lol");             // erasing by key
  		myrecipe.erase ( myrecipe.find("adff"), myrecipe.end() ); // erasing by range


		cout << "myrecipe contains:" << endl;
  		//printing
  		for (auto& x: myrecipe)
    		cout << x.first << ": " << x.second << endl;
		cout << std::endl;


		return 0;
	}	