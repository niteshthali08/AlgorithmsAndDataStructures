#include <iostream>
using namespace std;
enum Suit { 
		CLUBS = 1, 
		SPADES = 2, 
		HEARTS = 3, 
		DIAMONDS = 4
		};

class Card
{

private:
		int c;
		Suit s;

public:
	Card(int c, Suit s)
	{
		
		this->c = c;
		this->s = s;
	}
	void printCard()
	{
		cout << c <<" " <<s <<endl;
	}	

};

int main(int argc, char const *argv[])
{
	
	Card one(1, CLUBS);
	Card two(2, SPADES);
	Card three(3, HEARTS);
	Card four(4, DIAMONDS);
	one.printCard();
	two.printCard();
	three.printCard();
	four.printCard();
	return 0;
}