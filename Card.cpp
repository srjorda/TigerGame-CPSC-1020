#include "Card.h"
    
string Card::printCard() {
    if(color == purple) { return "purple:" + to_string(rank); }
    if(color == orange) { return "orange:" + to_string(rank); }
    return "Tiger:" + to_string(rank);
}
int Card::getRank() 
    { return rank; }
Card::Color Card::getColor() 
    { return color; }
int Card::getValue() 
    { return rank * color; }