#ifndef DECK_H_
#define DECK_H_

#include "Card.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class Deck {
    private:
        vector<Card> deck;
    public:
        Deck();
        
        void refresh();
        void shuffle();
        Card drawCard();
        int getDeckSize();
};
  

#endif // DECK_H_
