// Note: There is no Player.cpp file.
// The player class is simple enough to
// implement everything in Player.h

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Hand.h"
#include "Deck.h"
#include <vector>
using namespace std;

class Player {
    private:
    public:
        Hand hand;
        int score {0};

        Player() = default;
        Player(Deck &deck, int N) : hand(deck, N), score(0) {}
};  

#endif // PLAYER_H_
