#ifndef HAND_H_
#define HAND_H_

#include "Card.h"
#include "Deck.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Hand {
    private:
        vector<Card> hand;
    public:
        Hand() = default;
        
        Hand(Deck &deck, int N);
        void fill(Deck &deck, int N);
        string printHand();
        Card dealCard(int num);
        int getHandSize();
        
};

#endif // HAND_H_
