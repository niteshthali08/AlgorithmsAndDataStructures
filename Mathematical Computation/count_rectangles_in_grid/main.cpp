//
//  main.cpp
//  count_rectangles_in_grid
//
//  Created by Nitesh Thali on 7/15/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/*
    Program to count number unique rectangles in given m*n grid.
 
    Solution: We can derive a formula to count the number of rectangles present.
    For example consider a grid of 1*5
    Now there are   1*1
                    1*2
                    1*3
                    1*4
    Total of 10 rectangles. This is like 1* (1+2+3+4). Similary if m >1 then total number of rectangles would be equal to m(m+1)* n(n+1)/4
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int m, n;
    cout << "Enter m and n:";
    cin >>m >> n;
    cout << "Rectangles = " << m * (m+1) * n * (n+1) /4 <<endl;
    return 0;
    
}
