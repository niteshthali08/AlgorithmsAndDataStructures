//
//  main.cpp
//  Phone_Book_Manager
//
//  Created by Nitesh Thali on 7/9/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    ref: https://www.coursera.org/learn/data-structures/programming/Hpuiz/programming-assignment-3-hash-tables
 Task. In this task your goal is to implement a simple phone book manager. It should be able to process
 the following types of user's queries:
  
 add number name. It means that the user adds a person with name name and phone number
 number to the phone book. If there exists a user with such number already, then your manager
 has to overwrite the corresponding name.
  
 del number. It means that the manager should erase a person with number number from the
 phone book. If there is no such person, then it should just ignore the query.
  find number. It means that the user looks for a person with phone number number. The manager
 should reply with the appropriate name, or with string \not found" (without quotes) if there is
 no such person in the book.
 
 Use open addressing to build the data structure which will perform abover operations in O(1) time.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};
struct Contact{
    string name;
    int numer;
};
vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    // Asked to use open addressing, every phone number at max contains 7-digits.
    
    vector <string> phoneBook(10000000, "not found");
    for (int i=0; i<queries.size(); i++) {
        if(queries[i].type == "add"){
            phoneBook[queries[i].number] = queries[i].name;
        }else if (queries[i].type == "del"){
            phoneBook[queries[i].number] = "not found";
            
        }else{
            if (phoneBook[queries[i].number] == "not found")
                result.push_back("not found");
            else
                result.push_back(phoneBook[queries[i].number]);
            }
    }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
/*
 Sample Input Output
 Input
 12
 add 911 police
 add 76213 Mom
 add 17239 Bob
 find 76213
 find 910
 find 911
 del 910
 del 911
 find 911
 find 76213
 add 76213 daddy
 find 76213
 
 OUTPUT:
 Mom
 not found
 police
 not found
 Mom
 daddy
 
 Input
 8
 find 3839442
 add 123456 me
 add 0 granny
 find 0
 find 123456
 del 0
 del 0
 find 0
 
 Output:
 not found
 granny
 me
 not found
 
 */
