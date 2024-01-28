#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    bool again = false;
    int gamesPlayed = 0;
    vector<int> compScores;
    vector<int> humanScores;
    int compRoundW = 0;
    int compGameW = 0;
    int humanRoundW = 0;
    int humanGameW = 0;
    
    int input;
    Card compPlay(0, Card::purple);
    Card humanPlay(0, Card::purple);
    
    Deck deckOfCards;
    
    Player computer(deckOfCards, 5);
    Player human(deckOfCards, 5);
    
    cout << "Welcome to TigerGame!" << endl;
    
  do {
    gamesPlayed++;
    computer.score = 0;
    human.score = 0;
    
    deckOfCards.refresh();
    deckOfCards.shuffle();
    
    cout << "How many cards would you like to play with? ";
    do {
        cin >> input;
        if(input > 10 || input <= 0) 
            cout << "That won't work!\nHow many cards would you like to play with? ";
    } while(input > 10 || input <= 0);
  
    computer.hand.fill(deckOfCards, input);
    human.hand.fill(deckOfCards, input);
    
    cout << "The deck has shuffled and each player has drawn " << input 
         << ((input==1)?(" card."):(" cards.")) << endl;
    
  // 3. Play designated number of rounds. In each round:
    for(int i = 1; human.hand.getHandSize() != 0; i++) {
        cout << "Round " << i << endl << "-------" << endl;
        
  //    - Have computer deal a card from their hand.
        compPlay = computer.hand.dealCard(1);
        cout << "The computer plays: " << compPlay.printCard() << endl;
        
  //    - Show human their hand of cards so that they can make a selection.
        cout << "Your hand: " << human.hand.printHand() << endl;
        
  //    - Have human deal their card. 
        cout << "Which card do you want to play? ";
        cin >> input;
        humanPlay = human.hand.dealCard(input);
        cout << "You played: " << humanPlay.printCard() << endl;
        
  //    - Determine who won the round and update points accordingly.
        if(compPlay.getValue() == 0 || humanPlay.getValue() == 0) {
            cout << "The Tiger card was played. The game is over!" << endl << endl;
            (humanPlay.getValue() == 0) ? (human.score += 20) : (computer.score += 20);
            (humanPlay.getValue() == 0) ? (humanRoundW++) : (compRoundW++);
            for(int i = 1; i != human.hand.getHandSize() + i; i++)
                human.hand.dealCard(1);
        }
        else if(compPlay.getValue() == humanPlay.getValue() ) {
            cout << "Tie!" << endl << endl;
        }
        else if(compPlay.getValue() > humanPlay.getValue() ) {
            cout << "The computer wins this round!" << endl << endl;
            computer.score += compPlay.getValue() + humanPlay.getValue();
            compRoundW++;
        }
        else if(compPlay.getValue() < humanPlay.getValue() ) {
            cout << "You win this round!" << endl << endl;
            human.score += compPlay.getValue() + humanPlay.getValue();
            humanRoundW++;
        }
        
  //    - Print results for current round.
        if(human.hand.getHandSize() != 0) {
            cout << "Current scores:" << endl 
                 << "Human: " << human.score << endl
                 << "Computer: " << computer.score << endl << endl;
        }
    }
    
  // 4. Print final game results.  
    cout << "FINAL SCORE:" << endl 
         << "Human: " << human.score << endl
         << "Computer: " << computer.score << endl << endl;
    compScores.push_back(computer.score);
    humanScores.push_back(human.score);
    
    if(computer.score == human.score ) 
        cout << "It's a tie!"; 
    else if(computer.score > human.score ) 
        { cout << "The computer has won!"; compGameW++; }
    else if(computer.score < human.score ) 
        { cout << "Human has won!"; humanGameW++; }
        
    cout << endl << "\n[1] Play Again\n[2] Quit\n";
    cin >> input;
    ((input == 1) ? (again = true) : (again = false));
    
    cout << endl;
    
  } while( again == true );
  
  cout << "SUMMARY:" << endl
       << "Games Played: " << gamesPlayed << endl;
       
  cout << "Computer Scores by Game: ";
  for(int score : compScores)
    cout << setw(4) << right << score;
  cout << "\nYour Scores by Game    : ";
  for(int score : humanScores)
    cout << setw(4) << right << score;

    
  cout << "\nThe computer won " << compGameW << ((compGameW == 1) ? " game" : " games")
       << " and " << compRoundW << ((compRoundW == 1) ? " round." : " rounds.");
       
  cout << "\nYou won " << humanGameW << ((humanGameW == 1) ? " game" : " games")
       << " and " << humanRoundW << ((humanRoundW == 1) ? " round." : " rounds.");

  return 0;
}
