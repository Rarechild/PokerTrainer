//
//  main.cpp
//  Poker
//
//  Created by Fairchild on 10/12/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#include <string>
#include <sstream>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Round.h"
#include "Game.h"

using namespace std;

int main(int argc, const char * argv[])
{
    //Seed random number generator
    srand((unsigned)time(NULL));
    
    //Test Card
    /*
    Card testCard = Card();
    testCard.setValue(ACE);
    testCard.setSuit(SPADE);
    testCard.print();
    */
    
    //Test Deck
    /*
    Deck testDeck = Deck();
    cout << "New Deck:" << endl;
    testDeck.print();
    cout << endl;
    testDeck.shuffle();
    cout << "Shuffled Deck:" << endl;
    testDeck.print();
    */
    
    //Test Hand
    /* Hand testHand = Hand();
    
    Card testCard1 = Card(ACE, SPADE);
    Card testCard2 = Card(KING, SPADE);
    Card testCard3 = Card(QUEEN, SPADE);
    Card testCard4 = Card(JACK, SPADE);
    Card testCard5 = Card(FIVE, SPADE);
    Card testCard6 = Card(NINE, SPADE);
    Card testCard7 = Card(EIGHT, SPADE);
    
    testHand.addCard(testCard1);
    testHand.addCard(testCard2);
    testHand.addCard(testCard3);
    testHand.addCard(testCard4);
    testHand.addCard(testCard5);
    testHand.addCard(testCard6);
    testHand.addCard(testCard7);
    
    testHand.evalRank();
     
    cout << "First Card: " << endl;
    testHand.printCard(0);
    cout << endl;
    cout << "Pocket: " << endl;
    testHand.printPocket();
    cout << endl;
    cout << "Board: " << endl;
    testHand.printBoard();
    cout << endl;
    cout << "All Cards: " << endl;
    testHand.printAllCards();
    cout << endl;
    cout << "Best Cards: " << endl;
    testHand.printBestCards();
    cout << endl;
    cout << "Rank: " << endl;
    testHand.printRank();
    cout << endl;
    cout << "Hand Value: " << endl;
    testHand.printHandValue();
    */
    
    //Test Player
    /*
    int playerCount = 2;
    vector<Player> players;
    players.reserve(playerCount);
    
    for (int player = 0; player < playerCount; player++) {
        string name;
        stringstream number;
        name = "Player ";
        number << player + 1;
        players[player] = Player(name + number.str());
    }
    
    Card testCard1 = Card(ACE, SPADE);
    Card testCard2 = Card(KING, SPADE);
    Card testCard3 = Card(QUEEN, SPADE);
    Card testCard4 = Card(JACK, SPADE);
    Card testCard5 = Card(ACE, HEART);
    Card testCard6 = Card(KING, HEART);
    Card testCard7 = Card(QUEEN, HEART);
    Card testCard8 = Card(JACK, HEART);
    Card testCard9 = Card(TEN, HEART);
    
    players[0].addCard(testCard1);
    players[0].addCard(testCard2);
    players[1].addCard(testCard3);
    players[1].addCard(testCard4);
    players[0].addCard(testCard5);
    players[1].addCard(testCard5);
    players[0].addCard(testCard6);
    players[1].addCard(testCard6);
    players[0].addCard(testCard7);
    players[1].addCard(testCard7);
    players[0].addCard(testCard8);
    players[1].addCard(testCard8);
    players[0].addCard(testCard9);
    players[1].addCard(testCard9);
    
    for (int player = 0; player < playerCount; player++) {
        
        players[player].evalRank();
        
        cout << players[player].getName() << endl;
        cout << "---------------------------------" << endl;
        
        cout << "All Cards: " << endl;
        players[player].printAllCards();
        cout << endl;
        
        cout << "Best Cards: " << endl;
        players[player].printBestCards();
        cout << endl;
        
        cout << "Hand Value: " << endl;
        players[player].printHandValue();
        cout << endl;
     }
     */
    
    //Test Round
    Round round = Round();
    
    round.dealPockets();
    round.dealPockets();
    round.dealFlop();
    round.dealTurn();
    round.dealRiver();
    round.evalHands();
    round.printBoard();
    round.printHands();
    
    //Test Game
    

    
    return 0;
}

