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
#include "Test.h"

using namespace std;

int main(int argc, const char * argv[])
{
    //Seed random number generator
    srand((unsigned)time(NULL));
    
    testRound();
    
    return 0;
}

