/**
* INFO5083 Concurrent Processing 2
* Project 1 - Poker Hands Simulation
* By Ken Bonvanie
*
**/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::find
#include <ctime>
#include <mpi.h>

using namespace std;

const int TAG_DATA = 1, TAG_QUIT = 2;
int rankX, numProcs;
const int TAG_HAND = 0;
const int TAG_KILL = 1;

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

void processSlave(int rank)
{
	bool found[10] = {false};
	double noPair = 0.0, onePair = 0.0, twoPair = 0.0, threeOfAKind = 0.0, straight = 0.0, flush = 0.0, fullHouse = 0.0, fourOfAKind = 0.0, straightFlush = 0.0, royalFlush = 0.0;
	bool stop = false;
	int frequency[10] = {0};

	// fill the deck
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

	// generate the hand
	vector<string> Cards;
	for(unsigned i = 0; i < Suits.size(); ++i)
	{
		for(unsigned k = 0; k < Rank.size(); ++k)
		{
			Cards.push_back(Rank[k] + " " + Suits[i]);
		}
	}

	MPI_Request send_Request, recv_Request;	
	static int rcv_buff, recvFlag;
	MPI_Status status;
	recv_Request = 0;
	int x = 0;

	// main loop
	do
	{
		// shuffle 
		ShuffleTheDeck(Cards);
		int index = 0;

		// draw the hand 
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

			// check hand
			if(cardOne.substr(0,cardOneSpace) == cardTwo.substr(0,cardTwoSpace) || cardOne.substr(0,cardOneSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0,cardFourSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0,cardFiveSpace) || cardTwo.substr(0,cardTwoSpace) == cardThree.substr(0,cardThreeSpace) || cardTwo.substr(0,cardTwoSpace) == cardFour.substr(0,cardFourSpace) || cardTwo.substr(0,cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardThree.substr(0,cardThreeSpace) == cardFour.substr(0,cardFourSpace) || cardThree.substr(0,cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardFour.substr(0,cardFourSpace) == cardFive.substr(0,cardFiveSpace))
			{
				// 3 of a kind found, could be 4 of a kind or full house
				if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) || cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) || cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) || cardThree.substr(0, cardThreeSpace) == cardFour.substr(0, cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0, cardFiveSpace))
				{
					// 4 of a kind or full house
					if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace))
					{
						//4 of a kind
						x=7;
					}
					else if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardFour.substr(0, cardFourSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardFour.substr(0, cardFourSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0,cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0,cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) ||  cardOne.substr(0, cardOneSpace) == cardFour.substr(0,cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) ||  cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0,cardFiveSpace) ||  cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0,cardFourSpace) || cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0,cardThreeSpace) || cardThree.substr(0, cardThreeSpace) == cardFour.substr(0,cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0, cardFiveSpace) && cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace)) // full house
					{
						//full house
						x=6;
					}
					else
					{
						//3 of a kind
						x=3;
					}
				}
				else if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardThree.substr(0, cardThreeSpace) == cardFour.substr(0,cardFourSpace) || cardOne.substr(0,cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardFour.substr(0, cardFourSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) ||  cardOne.substr(0,cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardFour.substr(0, cardFourSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardThree.substr(0, cardThreeSpace) == cardFour.substr(0,cardFourSpace))
				{
					//two pair
					x=2;		
				}
				else
				{
					//one pair
					x=1;
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
						//straight flush
						x=8;
					}
					else if(hand[0] == "Ace" && hand[1] == "10" && hand[2] == "Jack" && hand[3] == "Queen" && hand[4] == "King")
					{
						//royal flush
						x=9;
					}
					else
					{
						//flush
						x=5;
					}
				}
				else if(hand[0] == "Ace" && hand[1] == "2" && hand[2] == "3" && hand[3] == "4" && hand[4] == "5" || hand[0] == "2" && hand[1] == "3" && hand[2] == "4" && hand[3] == "5" && hand[4] == "6" || hand[0] == "3" && hand[1] == "4" && hand[2] == "5" && hand[3] == "6" && hand[4] == "7" || hand[0] == "4" && hand[1] == "5" && hand[2] == "6" && hand[3] == "7" && hand[4] == "8" || hand[0] == "5" && hand[1] == "6" && hand[2] == "7" && hand[3] == "8" && hand[4] == "9" || hand[0] == "6" && hand[1] == "7" && hand[2] == "8" && hand[3] == "9" && hand[4] == "10" || hand[0] == "7" && hand[1] == "8" && hand[2] == "9" && hand[3] == "10" && hand[4] == "Jack" || hand[0] == "8" && hand[1] == "9" && hand[2] == "10" && hand[3] == "Jack" && hand[4] == "Queen" || hand[0] == "9" && hand[1] == "10" && hand[2] == "Jack" && hand[3] == "Queen" && hand[4] == "King")
				{
					//straight
					x=4;
				}
				else
				{
					//no pairs
					x=0;
				}
			}

			frequency[x]++;
			if(!found[x])
			{
				found[x] = true;
				//Tell others (dont send to self)
				for(int i = 0; i < numProcs; ++i)
				{
					if(i == rankX)
					{
						continue;
					}
					MPI_Isend(&x, 1, MPI_INT, i, TAG_HAND, MPI_COMM_WORLD, &send_Request);

				}
			}
		}

		// listen asynchronously
		if( recv_Request )
		{
			// Already listening for a message Test to see if message has been received
			MPI_Test( &recv_Request, &recvFlag, &status );
			if( recvFlag )
			{
				// Message received hand found
				if( status.MPI_TAG == TAG_HAND ){
					found[rcv_buff] = true;
				} 
				else if(status.MPI_TAG == TAG_KILL){
					stop = true;
				}
				// Reset the request handle
				recv_Request = 0;
			}
		}

		// Start listening again
		if( !recv_Request && !stop ){
			MPI_Irecv(&rcv_buff, 1, MPI_INT,MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &recv_Request);
		}

	}
	while( found[0] == false || found[1] == false || found[2] == false || found[3] == false || found[4] == false || found[5] == false ||found[6] == false || found[7] == false || found[8] == false ||found[9] == false );		

	// Send the results (MPI_SEND)
	MPI_Send(&frequency, 10, MPI_INT, 0, TAG_KILL, MPI_COMM_WORLD);

}

void processMaster(int numProcs)
{
	bool found[10] = {false};
	int frequency[10] = {0};
	double noPair = 0, onePair = 0, twoPair = 0, threeOfAKind =0, straight =0, flush = 0, fullHouse = 0, fourOfAKind = 0, straightFlush = 0, royalFlush =0;

	// Fill the deck
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

	vector<string> Cards;
	for(unsigned i = 0; i < Suits.size(); ++i)
	{
		for(unsigned k = 0; k < Rank.size(); ++k)
		{
			Cards.push_back(Rank[k] + " " + Suits[i]);
		}
	}

	MPI_Request send_Request, recv_Request;	
	static int rcv_buff, recvFlag;
	MPI_Status status;
	recv_Request = 0;

	// start the timer
	clock_t begin = clock();
	int x = 0;
	// main loop 
	do
	{
		if( recv_Request )		
		{
			// Already listening for a message Test to see if message has been received
			MPI_Test( &recv_Request, &recvFlag, &status );
			if( recvFlag )
			{
				// Message received hand found
				if( status.MPI_TAG == TAG_HAND ){
					found[rcv_buff] = true;
					//cout << "in" << endl;
				}
				// Reset the request handle
				recv_Request = 0;
			}
		}
		// Start listening again
		if( !recv_Request ){
			MPI_Irecv(&rcv_buff, 1, MPI_INT,MPI_ANY_SOURCE, TAG_HAND, MPI_COMM_WORLD, &recv_Request);
		}

		// shuffle 
		ShuffleTheDeck(Cards);
		int index = 0;

		// draw the hand 
		while(index <= 46)
		{
			string cardOne = Cards[0+index];
			string cardTwo = Cards[1+index];
			string cardThree = Cards[2+index];
			string cardFour = Cards[3+index];
			string cardFive = Cards[4+index];
			index += 5;

			// string find substring
			int cardOneSpace = cardOne.find(" ");
			int cardTwoSpace = cardTwo.find(" ");
			int cardThreeSpace = cardThree.find(" ");
			int cardFourSpace = cardFour.find(" ");
			int cardFiveSpace = cardFive.find(" ");

			// check hand
			if(cardOne.substr(0,cardOneSpace) == cardTwo.substr(0,cardTwoSpace) || cardOne.substr(0,cardOneSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0,cardFourSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0,cardFiveSpace) || cardTwo.substr(0,cardTwoSpace) == cardThree.substr(0,cardThreeSpace) || cardTwo.substr(0,cardTwoSpace) == cardFour.substr(0,cardFourSpace) || cardTwo.substr(0,cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardThree.substr(0,cardThreeSpace) == cardFour.substr(0,cardFourSpace) || cardThree.substr(0,cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardFour.substr(0,cardFourSpace) == cardFive.substr(0,cardFiveSpace))
			{
				// 3 of a kind
				if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) || cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) || cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) || cardThree.substr(0, cardThreeSpace) == cardFour.substr(0, cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0, cardFiveSpace))
				{
					if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) || cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace))
					{
						//4 of a kind
						x=7;
					}
					else if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardFour.substr(0, cardFourSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardFour.substr(0, cardFourSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0,cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0, cardOneSpace) == cardThree.substr(0,cardThreeSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) ||  cardOne.substr(0, cardOneSpace) == cardFour.substr(0,cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) ||  cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0, cardFourSpace) && cardOne.substr(0, cardOneSpace) == cardFive.substr(0,cardFiveSpace) ||  cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) && cardOne.substr(0, cardOneSpace) == cardFour.substr(0,cardFourSpace) || cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0, cardFiveSpace) && cardOne.substr(0, cardOneSpace) == cardThree.substr(0,cardThreeSpace) || cardThree.substr(0, cardThreeSpace) == cardFour.substr(0,cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0, cardFiveSpace) && cardOne.substr(0, cardOneSpace) == cardTwo.substr(0,cardTwoSpace)) // full house
					{
						//full house
						x=6;
					}
					else
					{
						//3 of a kind
						x=3;
					}
				}
				else if(cardOne.substr(0, cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardThree.substr(0, cardThreeSpace) == cardFour.substr(0,cardFourSpace) || cardOne.substr(0,cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardTwo.substr(0, cardTwoSpace) && cardFour.substr(0, cardFourSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) ||  cardOne.substr(0,cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardThree.substr(0, cardThreeSpace) && cardFour.substr(0, cardFourSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardTwo.substr(0, cardTwoSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardFour.substr(0, cardFourSpace) && cardThree.substr(0, cardThreeSpace) == cardFive.substr(0,cardFiveSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardThree.substr(0,cardThreeSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardTwo.substr(0, cardTwoSpace) == cardFour.substr(0,cardFourSpace) || cardOne.substr(0,cardOneSpace) == cardFive.substr(0, cardFiveSpace) && cardThree.substr(0, cardThreeSpace) == cardFour.substr(0,cardFourSpace))
				{
					//2 pair
					x=2;
				}
				else
				{
					//1 pair
					x=1;
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
						//straight flush
						x=8;						
					}
					else if(hand[0] == "Ace" && hand[1] == "10" && hand[2] == "Jack" && hand[3] == "Queen" && hand[4] == "King")
					{
						// Royal Flush
						x=9;						
					}
					else
					{	
						//flush
						x=5;
					}
				}
				else if(hand[0] == "Ace" && hand[1] == "2" && hand[2] == "3" && hand[3] == "4" && hand[4] == "5" || hand[0] == "2" && hand[1] == "3" && hand[2] == "4" && hand[3] == "5" && hand[4] == "6" || hand[0] == "3" && hand[1] == "4" && hand[2] == "5" && hand[3] == "6" && hand[4] == "7" || hand[0] == "4" && hand[1] == "5" && hand[2] == "6" && hand[3] == "7" && hand[4] == "8" || hand[0] == "5" && hand[1] == "6" && hand[2] == "7" && hand[3] == "8" && hand[4] == "9" || hand[0] == "6" && hand[1] == "7" && hand[2] == "8" && hand[3] == "9" && hand[4] == "10" || hand[0] == "7" && hand[1] == "8" && hand[2] == "9" && hand[3] == "10" && hand[4] == "Jack" || hand[0] == "8" && hand[1] == "9" && hand[2] == "10" && hand[3] == "Jack" && hand[4] == "Queen" || hand[0] == "9" && hand[1] == "10" && hand[2] == "Jack" && hand[3] == "Queen" && hand[4] == "King")
				{
					//straight
					x=4;
				}
				else
				{
					//no pairs
					x=0;
				}
			}

			//Tell others the card that was found
			frequency[x]++;
			if(!found[x]){

				found[x]=true;
				for(int i = 0; i < numProcs; ++i)
				{
					if(i == rankX)
					{ // dont send to self
						continue;
					}
					MPI_Isend(&x, 1, MPI_INT, i, TAG_HAND, MPI_COMM_WORLD, &send_Request);
				}
			}
		}

		// check if found (at the end of each loop)
		// END OF LOOP
	}
	while( found[0] == false || found[1] == false || found[2] == false || found[3] == false || found[4] == false || found[5] == false ||found[6] == false || found[7] == false || found[8] == false ||found[9] == false );

	// stop the timer
	clock_t end = clock();

	// shut down slaves 
	for(int i = 1; i < numProcs; ++i){
		MPI_Isend(&i, 1, MPI_INT, i, TAG_KILL, MPI_COMM_WORLD, &send_Request);
	}

	// collect totals
	MPI_Status results;
	for(int i = 1; i < numProcs; ++i)
	{
		int slaveResults[10] = {0};		
		MPI_Recv(&slaveResults, 10, MPI_INT, i, TAG_KILL, MPI_COMM_WORLD,  &results);
		for(int idx = 0; idx < 10; ++idx)
		{
			frequency[idx] += slaveResults[idx];
		}
	}

	//Display results
	double totalHands = 0.0;
	for(int i = 0; i < 10; ++i){
		totalHands += frequency[i];
	}

	// report
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "===========================================================" << endl;
	cout << "      Hand Type       Fequency      Relative Frequency  (%)  " << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "No Pair                  "  << frequency[0] << "               "  <<  ((double)frequency[0]/totalHands) * 100 << endl;
	cout << "One Pair                 "  << frequency[1] << "               "  <<  ((double)frequency[1]/totalHands) * 100 << endl;
	cout << "Two Pair                 "  << frequency[2] << "               "  <<  ((double)frequency[2]/totalHands) * 100 << endl;
	cout << "Three of a Kind          "  << frequency[3] << "               "  <<  ((double)frequency[3]/totalHands) * 100 << endl;
	cout << "Straight                 "  << frequency[4] << "               "  <<  ((double)frequency[4]/totalHands) * 100 << endl;
	cout << "Flush                    "  << frequency[5] << "               "  <<  ((double)frequency[5]/totalHands) * 100 << endl;
	cout << "Full House               "  << frequency[6] << "               "  <<  ((double)frequency[6]/totalHands) * 100 << endl;
	cout << "Four of a Kind           "  << frequency[7] << "               "  <<  ((double)frequency[7]/totalHands) * 100 << endl;
	cout << "Straight Flush           "  << frequency[8] << "               "  <<  ((double)frequency[8]/totalHands) * 100 << endl;
	cout << "Royal Flush              "  << frequency[9] << "               "  <<  ((double)frequency[9]/totalHands) * 100 << endl;
	cout << "-----------------------------------------------------------    " << endl;
	cout << "Hands Generated		  " << totalHands << endl;
	cout << "Elapsed TIME (s)         " << elapsed_secs << endl;
	cout << "Number of processes: 	  " << numProcs << endl;

	cout << endl;
	cout << endl;
	cout << endl;

}

int main(int argc, char* argv[])
{
	if(MPI_Init(&argc, &argv) == MPI_SUCCESS)
	{
		// Obtain the rank and the # of processes
		MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
		MPI_Comm_rank(MPI_COMM_WORLD, &rankX);

		if (rankX == 0)
		{
			processMaster(numProcs);
		}
		else
		{
			processSlave(rankX);
		}
		MPI_Finalize();
	}
}
