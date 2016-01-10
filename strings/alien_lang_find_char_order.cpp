#include <iostream>
#include <list>
#include <iterator>
using namespace std;

/*
author :  Nitesh Thali
Question from: http://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/

Given a sorted dictionary of an alien language, find order of characters
Given a sorted dictionary (array of words) of an alien language, find order of characters in the language.

Examples:

Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
Output: Order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa" 
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input:  words[] = {"caa", "aaa", "aab"}
Output: Order of characters is 'c', 'a', 'b'
Note: Below implementation assumes that characters will always start from a. It won't work if you 3 different characters and
they don't start from 'a' like b,c,d.
Also following does not handle the case when there is only one word present or all words are same. #trivial cases
*/
void constructGraph(list<char> **g, char* words[], int no_of_words)
{
	int j;
	for (int i = 0; i < no_of_words-1; ++i)
	{	j = 0;
		while(words[i][j] != '\0' && words[i+1][j] != '\0')
		{
			if (words[i][j] != words[i+1][j])
			{
				(*g)[words[i][j] - 'a'].push_back(words[i+1][j]);
			}
		}
		

	}
} 
void findOrder(char* words[], int no_of_words, int no_of_alphabates)
{
	list <int> *g = new list<int>[no_of_alphabates];
	list<int>::<iterator> it;
	constructGraph(&g, words[], no_of_words);
	for (int i = 0; i < no_of_alphabates; ++i)
	{
		cout << i << "->";
		for (it = g[i].begin; it !=g[i].end() ++it)
		{
			cout << *it;
		}
		cout << endl;
	}

}

int main()
{
		char* words[] = {"caa", "aaa", "aab"};
		findOrder(words, 3, 3);
}