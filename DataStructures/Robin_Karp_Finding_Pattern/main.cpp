//
//  main.cpp
//  Robin_Karp_Finding_Pattern
//
//  Created by Nitesh Thali on 7/9/16.
//  Copyright © 2016 Nitesh Thali. All rights reserved.
/* 
    Ref: https://www.coursera.org/learn/data-structures/programming/Hpuiz/programming-assignment-3-hash-tables
*/


#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}
bool isEqual(string text, string patt, int index, int m){
    for (int i=index; index<m; index++) {
        if(text[i] != patt[i])
            return false;
    }
    return true;
}

std::vector<int> get_occurrences(const Data& input) {
    /* Need to compute rolling hash function
     str ='abcd', then hash('abc') = (a + bx + cx^2)
     hash('bcd') = b + cx + dx^2
     We can calculate hash('bacd') from hash of ('abc') as follow
     
     hash('bcd')= hash('abc') - a
                = bx + cx^2 (divid by x) -> b + cx (add next term with power raised to len-1)
                                        -> b+cx+dx^2
     */
    vector <int> result;
    const string& patt = input.pattern, text = input.text;
    long long pattHash = 0;
    long long textHash = 0;
    long long prime = 101;
    int n = (int)text.length();
    int m = (int)patt.length();
    
    //calculate initial hash values for text and pattern
    for(int i=0; i<m; i++){
        long long pow_mult = pow(prime, i);
        pattHash += patt[i] *  pow_mult;
        textHash += text[i] * pow_mult;
    }
    for(int i=1; i<= n-m + 1; i++){
        if (textHash == pattHash){
            if (isEqual(text, patt, i-1, m))
                result.push_back(i-1);
        }
        long long newHash = textHash - text[i-1];
        newHash /= prime;
        newHash += text[i+m-1] * pow(prime, m-1);
        textHash = newHash;
            
    }
    return result;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
/*Input Output
 
 aba
 abacaba
 0 4
 
 Test
 testTesttesT
 4
 
 
 aaaaa
 baaaaaaa
 1 2 3
 
 */