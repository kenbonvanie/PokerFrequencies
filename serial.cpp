#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::find
#include <random>
#include <ctime>
#include <mpi.h>

using namespace std;


// shuffle helper method
vector<string> ShuffleTheDeck(vector<string> &x)
{
	srand( (unsigned) time( NULL ) );
	random_shuffle ( x.begin(), x.end() );
	return x;
}

vector<string> sortCards(string one, string two, string three, string four, string five, vector<string> &x)
{


	if(one == "Ace")
	{
		x.push_back(one);
	}
	else if(two == "Ace")
	{
		x.push_back(two);
	}
	else if(three == "Ace")
	{
		x.push_back(three);
	}
	else if(four == "Ace")
	{
		x.push_back(four);
	}
	else if(five == "Ace")
	{
		x.push_back(five);
	}


	if(one == "2")
	{
		x.push_back(one);
	}
	else if(two == "2")
	{
		x.push_back(two);
	}
	else if(three == "2")
	{
		x.push_back(three);
	}
	else if(four == "2")
	{
		x.push_back(four);
	}
	else if(five == "2")
	{
		x.push_back(five);
	}


	if(one == "3")
	{
		x.push_back(one);
	}
	else if(two == "3")
	{
		x.push_back(two);
	}
	else if(three == "3")
	{
		x.push_back(three);
	}
	else if(four == "3")
	{
		x.push_back(four);
	}
	else if(five == "3")
	{
		x.push_back(five);
	}


	if(one == "4")
	{
		x.push_back(one);
	}
	else if(two == "4")
	{
		x.push_back(two);
	}
	else if(three == "4")
	{
		x.push_back(three);
	}
	else if(four == "4")
	{
		x.push_back(four);
	}
	else if(five == "4")
	{
		x.push_back(five);
	}


	if(one == "5")
	{
		x.push_back(one);
	}
	else if(two == "5")
	{
		x.push_back(two);
	}
	else if(three == "5")
	{
		x.push_back(three);
	}
	else if(four == "5")
	{
		x.push_back(four);
	}
	else if(five == "5")
	{
		x.push_back(five);
	}


	if(one == "6")
	{
		x.push_back(one);
	}
	else if(two == "6")
	{
		x.push_back(two);
	}
	else if(three == "6")
	{
		x.push_back(three);
	}
	else if(four == "6")
	{
		x.push_back(four);
	}
	else if(five == "6")
	{
		x.push_back(five);
	}



	if(one == "7")
	{
		x.push_back(one);
	}
	else if(two == "7")
	{
		x.push_back(two);
	}
	else if(three == "7")
	{
		x.push_back(three);
	}
	else if(four == "7")
	{
		x.push_back(four);
	}
	else if(five == "7")
	{
		x.push_back(five);
	}

	if(one == "8")
	{
		x.push_back(one);
	}
	else if(two == "8")
	{
		x.push_back(two);
	}
	else if(three == "8")
	{
		x.push_back(three);
	}
	else if(four == "8")
	{
		x.push_back(four);
	}
	else if(five == "8")
	{
		x.push_back(five);
	}

	if(one == "9")
	{
		x.push_back(one);
	}
	else if(two == "9")
	{
		x.push_back(two);
	}
	else if(three == "9")
	{
		x.push_back(three);
	}
	else if(four == "9")
	{
		x.push_back(four);
	}
	else if(five == "9")
	{
		x.push_back(five);
	}

	if(one == "10")
	{
		x.push_back(one);
	}
	else if(two == "10")
	{
		x.push_back(two);
	}
	else if(three == "10")
	{
		x.push_back(three);
	}
	else if(four == "10")
	{
		x.push_back(four);
	}
	else if(five == "10")
	{
		x.push_back(five);
	}

	if(one == "Jack")
	{
		x.push_back(one);
	}
	else if(two == "Jack")
	{
		x.push_back(two);
	}
	else if(three == "Jack")
	{
		x.push_back(three);
	}
	else if(four == "Jack")
	{
		x.push_back(four);
	}
	else if(five == "Jack")
	{
		x.push_back(five);
	}


	if(one == "Queen")
	{
		x.push_back(one);
	}
	else if(two == "Queen")
	{
		x.push_back(two);
	}
	else if(three == "Queen")
	{
		x.push_back(three);
	}
	else if(four == "Queen")
	{
		x.push_back(four);
	}
	else if(five == "Queen")
	{
		x.push_back(five);
	}

	if(one == "King")
	{
		x.push_back(one);
	}
	else if(two == "King")
	{
		x.push_back(two);
	}
	else if(three == "King")
	{
		x.push_back(three);
	}
	else if(four == "King")
	{
		x.push_back(four);
	}
	else if(five == "King")
	{
		x.push_back(five);
	}

	return x;

}


int main()
{
	cout << "     Poker Hand Frequency Simulation  [Serial Version]   " << endl;


	vector<string> Rank;
	Rank.push_back("Ace");
	Rank.push_back("2");
	Rank.push_back("3");
	Rank.push_back("4");
	Rank.push_back("5");
	Rank.push_back("6");
	Rank.push_back("7");
	Rank.push_back("8");
	Rank.push_back("9");
	Rank.push_back("10");
	Rank.push_back("Jack");
	Rank.push_back("Queen");
	Rank.push_back("King");

	vector<string> Suits;
	Suits.push_back("Hearts");
	Suits.push_back("Diamonds");
	Suits.push_back("Clubs");
	Suits.push_back("Spades");

	// NOTES: 
	// Hearts
	// Diamonds
	// Clubs
	// Spades

	// Ace
	// 1 - 10
	// Jack
	// Queen
	// King

	vector<string> Cards;
	for(int i = 0; i < Suits.size(); ++i)
	{
		for(int k = 0; k < Rank.size(); ++k)
		{
			Cards.push_back(Rank[k] + " " + Suits[i]);
		}
	}


	for(int i = 0; i < Cards.size(); ++i)
	{
		cout << "Card: " << Cards[i] << endl;
	}

	cout << "There are " << Cards.size() << " In total." <<  endl;


	bool foundRoyalFlush = false, foundStraightFlush = false, foundFlush = false, foundFourOfAKind = false, foundFullHouse = false, foundStraight = false, foundThreeOfAKind = false, foundTwoPair = false, foundOnePair = false, foundNoPair = false;
	string hand = "";
	double noPair = 0, onePair = 0, twoPair = 0, threeOfAKind =0, straight =0, flush = 0, fullHouse = 0, fourOfAKind = 0, straightFlush = 0, royalFlush =0;
	int handsGenerated = 0;

	// take first 5 cards from the vector and concatenate them to hand string
	// compare the cards to check for matches and increment corresponding hand type ex if you find 2 of heart and 2 of diamonds increment number of pairs
	// check for special cases like full house, straight, straight flushm royal flush and no pairs.
	// figure out which hand type it was and then make that handtype bool = true. ex find a straight and set foundStraight = true.
	// increment hand counter
	// continue to take 5 cards off the stack and compare them until all of the booleans are true, This might require you to make a new deck
	// if you have less than 5 cards left in the deck when you go to take 5 remake the deck and shuffle it.

	int loops=1;
	clock_t begin = clock();
	while(foundRoyalFlush == false || foundFlush == false || foundStraightFlush == false || foundFourOfAKind == false || foundFullHouse == false || foundStraight == false || foundThreeOfAKind == false || foundTwoPair == false || foundOnePair == false || foundNoPair == false )
	{

		// shuffle here
		ShuffleTheDeck(Cards);
		int index = 0;

		while(index <= 46)
		{
			string cardOne = Cards[0+index];
			string cardTwo = Cards[1+index];
			string cardThree = Cards[2+index];
			string cardFour = Cards[3+index];
			string cardFive = Cards[4+index];
			index += 5;

			// string find sub string
			int cardOneSpace = cardOne.find(" ");
			int cardTwoSpace = cardTwo.find(" ");
			int cardThreeSpace = cardThree.find(" ");
			int cardFourSpace = cardFour.find(" ");
			int cardFiveSpace = cardFive.find(" ");

			// 1 pair
			//clock_t begin = clock();
			if(cardOne.substr(0,cardOneSpace) == cardTwo.substr(0,cardTwoSpace) || cardOne.substr(0,cardOneSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0,cardFourSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0,cardFiveSpace) || cardTwo.substr(0,cardTwoSpace) == cardThree.substr(0,cardThreeSpace) || cardTwo.substr(0,cardTwoSpace) == cardFour.substr(0,cardFourSpace) || cardTwo.substr(0,cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardThree.substr(0,cardThreeSpace) == cardFour.substr(0,cardFourSpace) || cardThree.substr(0,cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardFour.substr(0,cardFourSpace) == cardFive.substr(0,cardFiveSpace))
			{
				// 3 of a kind
				if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) || cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) || cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) || cardThree.substr(0, cardThreeSpace) == cardFour.substr(0, cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0, cardFiveSpace))
				{
					// 4 of a kind
					if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace))
					{
						foundFourOfAKind = true;
						fourOfAKind++;
					}
					else if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardFour.substr(0, cardFourSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardFour.substr(0, cardFourSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0,cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0,cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) ||  cardOne.substr(0, cardOneSpace) == cardFour.substr(0,cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) ||  cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0,cardFiveSpace) ||  cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0,cardFourSpace) || cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0,cardThreeSpace) || cardThree.substr(0, cardThreeSpace) == cardFour.substr(0,cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0, cardFiveSpace) && cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace)) // full house
					{
						foundFullHouse = true;
						fullHouse++;
					}
					else
					{
						foundThreeOfAKind = true;
						threeOfAKind++;
					}
				}
				// 2 pair
				else if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardThree.substr(0, cardThreeSpace) == cardFour.substr(0,cardFourSpace) || cardOne.substr(0,cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardFour.substr(0, cardFourSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) ||  cardOne.substr(0,cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardFour.substr(0, cardFourSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardThree.substr(0, cardThreeSpace) == cardFour.substr(0,cardFourSpace))
				{
					foundTwoPair = true;
					twoPair++;
				}
				else
				{
					foundOnePair = true;
					onePair++;
				}
			}
			else
			{
				vector<string> hand;
				sortCards(cardOne.substr(0,cardOneSpace), cardTwo.substr(0, cardTwoSpace), cardThree.substr(0, cardThreeSpace), cardFour.substr(0, cardFourSpace), cardFive.substr(0, cardFiveSpace), hand );

				// check to see if all card are the same suit
				if(cardOne.substr(cardOneSpace) == cardTwo.substr(cardTwoSpace) && cardOne.substr(cardOneSpace) == cardThree.substr(cardThreeSpace) && cardOne.substr(cardOneSpace) == cardFour.substr(cardFourSpace) && cardOne.substr(cardOneSpace) == cardFive.substr(cardFiveSpace))
				{
					//either royal flush, straight flush or flush
					//check to see if it is a sequence
					if(hand[0] == "Ace" && hand[1] == "2" && hand[2] == "3" && hand[3] == "4" && hand[4] == "5" || hand[0] == "2" && hand[1] == "3" && hand[2] == "4" && hand[3] == "5" && hand[4] == "6" || hand[0] == "3" && hand[1] == "4" && hand[2] == "5" && hand[3] == "6" && hand[4] == "7" || hand[0] == "4" && hand[1] == "5" && hand[2] == "6" && hand[3] == "7" && hand[4] == "8" || hand[0] == "5" && hand[1] == "6" && hand[2] == "7" && hand[3] == "8" && hand[4] == "9" || hand[0] == "6" && hand[1] == "7" && hand[2] == "8" && hand[3] == "9" && hand[4] == "10" || hand[0] == "7" && hand[1] == "8" && hand[2] == "9" && hand[3] == "10" && hand[4] == "Jack" || hand[0] == "8" && hand[1] == "9" && hand[2] == "10" && hand[3] == "Jack" && hand[4] == "Queen" || hand[0] == "9" && hand[1] == "10" && hand[2] == "Jack" && hand[3] == "Queen" && hand[4] == "King")
					{
						foundStraightFlush = true;
						straightFlush++;
						if(foundRoyalFlush == true && foundFlush == true && foundStraightFlush == true && foundFourOfAKind == true && foundFullHouse == true && foundStraight == true && foundThreeOfAKind == true && foundTwoPair == true && foundOnePair == true && foundNoPair == true)
						{
							break;
						}
					}
					// Royal Flush
					else if(hand[0] == "Ace" && hand[1] == "10" && hand[2] == "Jack" && hand[3] == "Queen" && hand[4] == "King")
					{
						foundRoyalFlush = true;
						royalFlush++;
						if(foundRoyalFlush == true && foundFlush == true && foundStraightFlush == true && foundFourOfAKind == true && foundFullHouse == true && foundStraight == true && foundThreeOfAKind == true && foundTwoPair == true && foundOnePair == true && foundNoPair == true)
						{
							break;
						}
					}
					else
					{
						foundFlush = true;
						flush++;
					}
				}
				else if(hand[0] == "Ace" && hand[1] == "2" && hand[2] == "3" && hand[3] == "4" && hand[4] == "5" || hand[0] == "2" && hand[1] == "3" && hand[2] == "4" && hand[3] == "5" && hand[4] == "6" || hand[0] == "3" && hand[1] == "4" && hand[2] == "5" && hand[3] == "6" && hand[4] == "7" || hand[0] == "4" && hand[1] == "5" && hand[2] == "6" && hand[3] == "7" && hand[4] == "8" || hand[0] == "5" && hand[1] == "6" && hand[2] == "7" && hand[3] == "8" && hand[4] == "9" || hand[0] == "6" && hand[1] == "7" && hand[2] == "8" && hand[3] == "9" && hand[4] == "10" || hand[0] == "7" && hand[1] == "8" && hand[2] == "9" && hand[3] == "10" && hand[4] == "Jack" || hand[0] == "8" && hand[1] == "9" && hand[2] == "10" && hand[3] == "Jack" && hand[4] == "Queen" || hand[0] == "9" && hand[1] == "10" && hand[2] == "Jack" && hand[3] == "Queen" && hand[4] == "King")
				{
					foundStraight = true;
					straight++;
					if(foundRoyalFlush == true && foundFlush == true && foundStraightFlush == true && foundFourOfAKind == true && foundFullHouse == true && foundStraight == true && foundThreeOfAKind == true && foundTwoPair == true && foundOnePair == true && foundNoPair == true)
					{
						break;
					}
				}
				else
				{
					foundNoPair = true;
					noPair++;
				}
			}

			loops++;
		}
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "===========================================================" << endl;
	cout << "      Hand Type       Fequency      Relative Frequency  (%)  " << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "No Pair                  "  << noPair << "               "  <<  (noPair/loops) * 100 << endl;
	cout << "One Pair                 "  << onePair << "               "  <<  (onePair/loops) * 100 << endl;
	cout << "Two Pair                 "  << twoPair << "               "  <<  (twoPair/loops) * 100 << endl;
	cout << "Three of a Kind          "  << threeOfAKind << "               "  <<  (threeOfAKind/loops) * 100 << endl;
	cout << "Straight                 "  << straight << "               "  <<  (straight/loops) * 100 << endl;
	cout << "Flush                    "  << flush << "               "  <<  (flush/loops) * 100 << endl;
	cout << "Full House               "  << fullHouse << "               "  <<  (fullHouse/loops) * 100 << endl;
	cout << "Four of a Kind           "  << fourOfAKind << "               "  <<  (fourOfAKind/loops) * 100 << endl;
	cout << "Straight Flush           "  << straightFlush << "               "  <<  (straightFlush/loops) * 100 << endl;
	cout << "Royal Flush              "  << royalFlush << "               "  <<  (royalFlush/loops) * 100 << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "Hands Generated		    " << loops << endl;
	cout << "Elapsed TIME (s) 		    " << elapsed_secs << endl;
	int breakPoint=0;

}


