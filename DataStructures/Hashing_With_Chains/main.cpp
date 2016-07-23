
//  main.cpp
//  Hadhing_With_Chains
//
//  Created by Nitesh Thali on 7/9/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.

/*
  Ref : https://www.coursera.org/learn/data-structures/programming/Hpuiz/programming-assignment-3-hash-tables
 
 add string - insert string into the table. If there is already such string in the hash table, then
 just ignore the query.
 
  del string - remove string from the table. If there is no such string in the hash table, then just
 ignore the query.
 
 find string - output \yes" or \no" (without quotes) depending on whether the table contains
 string or not.
 
  check i output the content of the i-th list in the table. Use spaces to separate the elements of
 the list. If i-th list is empty, output a blank line.
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector< list <string> > elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }
    
public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
         elems.resize(bucket_count);
    }
   
    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }
    
    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }
    
    void processQuery(const Query& query) {
       
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (list<string>::iterator rit=elems[query.ind].begin(); rit!=elems[query.ind].end(); ++rit) //note ::reverse_iterator, rbegin(), rend(), ++
                std::cout << *rit << " ";
            std::cout << "\n";
        } else {
            size_t index = hash_func(query.s);
            list <string>::iterator it = std::find(elems[index].begin(), elems[index].end(), query.s);
            if (query.type == "find"){
                 writeSearchResult(it != elems[index].end());
            }
            else if (query.type == "add") {
                if (it == elems[index].end())
                    elems[index].push_front(query.s);
            } else if (query.type == "del") {
                if (it != elems[index].end())
                    elems[index].erase(it);
            }
        }
    }
    
    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
/*
 
 Sample Input Output
 5
 12
 add world
 add HellO
 check 4
 find World
 find world
 del world
 check 4
 del HellO
 add luck
 add GooD
 check 2
 del good
 
 Output:
 ellO world
 no
 yes
 HellO
 GooD luck
 
 Input:
 4
 8
 add test
 add test
 find test
 del test
 find test
 find Test
 add Test
 find Test
 
 Output:
 yes
 no
 no
 yes
 */