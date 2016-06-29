#include <iostream>
using namespace std;

class Cards
{
private:
	int c;
	Suit s;
public:

	Cards(int c, Suit s);
	~Cards();
	enum Suit { 
		CLUBS (1), 
		SPADES(2), 
		HEARTS(3), 
		DIAMONDS (4);
		};
	/* data */
};