//
//  Test.h
//  PokerTrainer
//
//  Created by Fairchild on 10/31/12.
//  Copyright (c) 2012 Matt Giannetto. All rights reserved.
//

#ifndef PokerTrainer_Test_h
#define PokerTrainer_Test_h

//Test Card
void testCard() {
    Card testCard = Card();
    testCard.setValue(ACE);
    testCard.setSuit(SPADE);
    testCard.print();
};

//Test Deck
void testDeck() {
    Deck testDeck = Deck();
    cout << "New Deck:" << endl;
    testDeck.print();
    cout << endl;
    testDeck.shuffle();
    cout << "Shuffled Deck:" << endl;
    testDeck.print();
};

//Test Hand
void testHand() {
    Hand testHand = Hand();
    
    Card testCard1 = Card(ACE, SPADE);
    Card testCard2 = Card(KING, SPADE);
    Card testCard3 = Card(QUEEN, SPADE);
    Card testCard4 = Card(JACK, SPADE);
    Card testCard5 = Card(TEN, SPADE);
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

}

//Set Hand
void testHandEval(Value c1_, Value c2_, Value c3_, Value c4_, Value c5_, Value c6_, Value c7_, string expected) {
    
    Hand testHand = Hand();
    
    Card testCard1 = Card(c1_, SPADE);
    Card testCard2 = Card(c2_, HEART);
    Card testCard3 = Card(c3_, DIAMOND);
    Card testCard4 = Card(c4_, CLUB);
    Card testCard5 = Card(c5_, SPADE);
    Card testCard6 = Card(c6_, HEART);
    Card testCard7 = Card(c7_, DIAMOND);
    
    testHand.addCard(testCard1);
    testHand.addCard(testCard2);
    testHand.addCard(testCard3);
    testHand.addCard(testCard4);
    testHand.addCard(testCard5);
    testHand.addCard(testCard6);
    testHand.addCard(testCard7);
    
    testHand.evalRank();
    
    string result = "False";
    
    if (expected == testHand.showBestCards()) {
        result = "True ";
    }
    
    cout << "Result  : " << result << "      Rank : " << testHand.getRank() << endl << "Expected: " << expected << endl << "Actual  : " << testHand.showBestCards() << endl << endl;

    
};

//Test Hand Sort and Ranks
void testHandRank() {
    
    /*
     Possibilities of groupings that need to be re-sorted, for 5 cards
     Z Y Y X X | 1 2 2 0 0 | Type 1
     Z Y Y Y Y | 1 4 0 0 0 | Type 2
     Z Z Y Y Y | 2 3 0 0 0 | Type 2
     Z Y Y Y X | 1 3 1 0 0 | Type 2
     Z Y Y X W | 1 2 1 1 0 | Type 2
     Z Y X X X | 1 1 3 0 0 | Type 3
     Z Y X X W | 1 1 2 1 0 | Type 3
     Z Y X W W | 1 1 1 2 0 | Type 4
     Z Z Y X X | 2 1 2 0 0 | Type 5
     2 3 4 5 A | 1 1 1 1 1 | Type 6 (Ace low straight)
     Z Y X W V | 1 1 1 1 1 | No additional sorting necessary
     */
 
    //Type 1
    cout << "Type 1" << endl;
    cout << "-----------------------------" << endl;
    testHandEval(KING, QUEEN, QUEEN, JACK, JACK, TEN, EIGHT, "Q|H Q|D J|C J|S K|S");
    testHandEval(KING, QUEEN, QUEEN, JACK, JACK, TEN, TEN, "Q|H Q|D J|C J|S K|S");
    testHandEval(KING, QUEEN, QUEEN, JACK, TEN, TEN, EIGHT, "Q|H Q|D T|S T|H K|S");
    testHandEval(KING, QUEEN, JACK, JACK, TEN, TEN, EIGHT, "J|D J|C T|S T|H K|S");
    testHandEval(TEN, TEN, EIGHT, JACK, KING, QUEEN, JACK, "J|C J|D T|S T|H K|S");
    
    //Type 2
    cout << "Type 2" << endl;
    cout << "-----------------------------" << endl;
    testHandEval(KING, QUEEN, QUEEN, QUEEN, QUEEN, TEN, EIGHT, "Q|H Q|D Q|C Q|S K|S");
    testHandEval(KING, QUEEN, QUEEN, JACK, JACK, JACK, JACK, "J|C J|S J|H J|D K|S");
    testHandEval(KING, QUEEN, JACK, QUEEN, QUEEN, TEN, QUEEN, "Q|H Q|C Q|S Q|D K|S");
    testHandEval(KING, QUEEN, QUEEN, QUEEN, JACK, TEN, KING, "Q|D Q|C Q|H K|S K|D");
    testHandEval(KING, QUEEN, QUEEN, JACK, JACK, JACK, KING, "J|S J|H J|C K|S K|D");
    testHandEval(KING, QUEEN, JACK, QUEEN, QUEEN, KING, JACK, "Q|C Q|S Q|H K|S K|H");
    testHandEval(KING, QUEEN, QUEEN, QUEEN, JACK, TEN, EIGHT, "Q|H Q|D Q|C K|S J|S");
    testHandEval(KING, QUEEN, QUEEN, JACK, NINE, EIGHT, SEVEN, "Q|H Q|D K|S J|C 9|S");
    
    //Type 3
    cout << "Type 3" << endl;
    cout << "-----------------------------" << endl;
    testHandEval(KING, QUEEN, EIGHT, JACK, JACK, JACK, SIX, "J|C J|S J|H K|S Q|H");
    testHandEval(KING, QUEEN, JACK, FIVE, FOUR, THREE, JACK, "J|D J|D K|S Q|H 5|C");
    
    //Type 4
    cout << "Type 4" << endl;
    cout << "-----------------------------" << endl;
    testHandEval(KING, QUEEN, JACK, SIX, EIGHT, TWO, SIX, "6|C 6|D K|S Q|H J|D");
    
    //Type 5
    cout << "Type 5" << endl;
    cout << "-----------------------------" << endl;
    testHandEval(KING, QUEEN, KING, JACK, FOUR, THREE, JACK, "K|S K|D J|C J|D Q|H");
    
    //Type 6
    cout << "Type 6" << endl;
    cout << "-----------------------------" << endl;
    testHandEval(TWO, THREE, FOUR, FIVE, ACE, ACE, ACE, "5|C 4|D 3|H 2|S 1|D");
    testHandEval(ACE, TWO, THREE, FOUR, FIVE, THREE, JACK, "5|S 4|C 3|H 2|H 1|S");
    testHandEval(ACE, KING, QUEEN, FIVE, TWO, THREE, FOUR, "5|C 4|D 3|H 2|S 1|S");
    
};

//Test Player
void testPlayer() {
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
};

//Test Round
void testRound() {
    Round round = Round();

    round.dealPockets();
    round.dealPockets();
    round.dealFlop();
    round.dealTurn();
    round.dealRiver();
    round.evalHands();
    round.printBoard();
    round.printHands();
};

//Test Game
void testGame() {
         
};

#endif
