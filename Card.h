#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <iostream>
using namespace std;

class Card {
    public:
        enum Color { Tiger = 0, purple = 1, orange = 2 };
    private:
        int rank {0};
        Color color {purple};
        int value {0};
    public:
        Card() : rank{0}, color{purple}, value{0} {};
        Card(int rank, Color color) : rank(rank), color(color) {};
        
        string printCard();
        
        int getRank();
        Color getColor();
        int getValue();
};
  

#endif // CARD_H_
