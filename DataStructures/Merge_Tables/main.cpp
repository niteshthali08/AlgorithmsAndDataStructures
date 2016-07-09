//
//  main.cpp
//  Merge_Tables
//
//  Created by Nitesh Thali on 7/8/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Ref: https://www.coursera.org/learn/data-structures/home/week/3
 
 
 */

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct DisjointSetsElement {
    int size, parent, rank;
    // size -> no of row
    DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
    int size; // number of tables
    int max_table_size;
    vector <DisjointSetsElement> sets;
    
    DisjointSets(int size): size(size), max_table_size(0), sets(size) {
        for (int i = 0; i < size; i++)
            sets[i].parent = i;
    }
    
    int getParent(int table) {
        // find parent and compress path
        if (sets[table].parent != table){
            sets[table].parent = getParent(sets[table].parent); // parent gets updated from top to bottom hence gets propagated.
        }
        return sets[table].parent; // returnig parent for path compression
    }
    
    void merge(int destination, int source) {
        int realDestination = getParent(destination);
        int realSource = getParent(source);
        if (realDestination != realSource) {
            // merge two components
            if(realDestination != realSource){
            // use union by rank heuristic
                if (sets[realDestination].rank < sets[realSource].rank){
                    sets[realDestination].parent = realSource;
                    sets[realSource].size += sets[realDestination].size;
                    sets[realDestination].size = 0;
                    max_table_size = max(max_table_size, sets[realSource].size);
                    
                }else{
                    
                    sets[realSource].parent = realDestination;
                    sets[realDestination].size += sets[realSource].size;
                    max_table_size = max(max_table_size, sets[realDestination].size);
                    if(sets[realDestination].rank == sets[realSource].rank)
                        sets[realDestination].rank +=1;
                     sets[realSource].size = 0;
                }
                
                // update max_table_size
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    DisjointSets tables(n);
    for (auto &table : tables.sets) {
        cin >> table.size;
        tables.max_table_size = max(tables.max_table_size, table.size);
    }
    
    for (int i = 0; i < m; i++) {
        int destination, source;
        cin >> destination >> source;
        --destination;
        --source;
        
        tables.merge(destination, source);
        cout << tables.max_table_size << endl;
    }
    
    return 0;
}
/*Sample Input output
 Input:
 5 5
 1 1 1 1 1
 3 5
 2 4
 1 4
 5 4
 5 3
 Output:
 2
 2
 3
 5
 5
 Explanation:
 1. All the data from the table 5 is copied to table number 3. Table 5 now contains only a symbolic
 link to table 3, while table 3 has 2 rows. 2 becomes the new maximum size.
 2. 2 and 4 are merged in the same way as 3 and 5.
 3. We are trying to merge 1 and 4, but 4 has a symbolic link pointing to 2, so we actually copy
 all the data from the table number 2 to the table number 1, clear the table number 2 and put a
 symbolic link to the table number 1 in it. Table 1 now has 3 rows of data, and 3 becomes the
 new maximum size.
 4. Traversing the path of symbolic links from 4 we have 4 ! 2 ! 1, and the path from 5 is 5 ! 3.
 So we are actually merging tables 3 and 1. We copy all the rows from the table number 1 into
 the table number 3, and now the table number 3 has 5 rows of data, which is the new maximum.
 5. All tables now directly or indirectly point to table 3, so all other merges won't change anything.
 
 Input:
 6 4
 10 0 5 0 3 3
 6 6
 6 5
 5 4
 4 3
 Output:
 10
 10
 10
 11
 
 */
