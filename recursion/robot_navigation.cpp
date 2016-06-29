#include <iostream>
using namespace std;
/*
Problem: is to move robot from top left corner to bottom right corner. Count the number ways robot can reach its destination

*/
int moveRobot(int X, int Y)
{
	if ( X == 1 || Y == 1)
		{	
			cout << "returning 1" <<endl;
			return 1;
		}
	
	cout << "moveRobot(" << X-1 << ", " << Y << ")" <<endl;
	int m = moveRobot(X-1, Y);
	cout << "moveRobot(" << X << ", " << Y-1 << ")" <<endl;
	int n  = moveRobot(X, Y-1);
	cout << "m+n " << m+n << endl;
	return m+n;
	
}

int main(int argc, char const *argv[])
{	
	int count = moveRobot(3,3);
	cout << "There are " <<count << " ways by which Robot can travel";

	return 0;
}