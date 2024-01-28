#include "Hand.h"
#include "Deck.h"
#include "Card.h"

Hand::Hand(Deck &deck, int N) {
    for(int i = 0; i < N; i++)
        hand.push_back(deck.drawCard());
}

void Hand::fill(Deck &deck, int N) {
    hand.clear();
    for(int i = 0; i < N; i++)
        hand.push_back(deck.drawCard());
}

string Hand::printHand() {
    string str;
    int i = 0;
    for(Card c : hand) {
        str += "[" + to_string(i + 1) + "] " + c.printCard() + " ";
        i++;
    }
    return str;
}

Card Hand::dealCard(int num) {
    Card c = hand[num - 1];
    hand.erase(hand.begin() + num - 1);
    return c;
}

int Hand::getHandSize() {
    return hand.size();
}