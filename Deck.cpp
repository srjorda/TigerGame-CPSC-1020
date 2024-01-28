#include "Deck.h"

Deck::Deck() {
    for(int i = 1; i <= 10; i++)
        deck.push_back({i, Card::purple});
    for(int i = 1; i <= 10; i++)
        deck.push_back({i, Card::orange});
    deck.push_back({10, Card::Tiger});
}

void Deck::refresh() {
    deck.clear();
    for(int i = 1; i <= 10; i++)
        deck.push_back({i, Card::purple});
    for(int i = 1; i <= 10; i++)
        deck.push_back({i, Card::orange});
    deck.push_back({10, Card::Tiger});
}

void Deck::shuffle() {
    srand(unsigned(time(0)));
    random_shuffle(deck.begin(), deck.end());
}

Card Deck::drawCard() {
    Card c = deck[0];
    deck.erase(deck.begin());
    return c;
}

int Deck::getDeckSize() {
    return deck.size();
}