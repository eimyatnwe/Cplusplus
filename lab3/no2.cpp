#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

class GuessNumberGame {
    public:
        int secretNumber;

        GuessNumberGame() {
            srand(static_cast<unsigned int>(std::time(0)));
            secretNumber = std::rand() % 101;  
        }

        void play(){
            int guess;
            int trial = 1;
            cout << "Guess the number (between 0 and 100): ";
            cin >> guess;
            while(trial < 10){
               
                if (guess > secretNumber){
                    cout << "Lower than your Number.Try again: ";
                    cin >> guess;
                }else if(guess < secretNumber){
                    cout << "Higher than your Number. Try again: ";
                    cin >> guess;
                }else if(guess == secretNumber){
                    cout << "Congratulations. You win.";
                    break;
                }
                trial++;
            }
           cout << "You Lose. The correct number is: "<< secretNumber; 
        }
};

int main() {
   GuessNumberGame game;
   game.play();
   return 0;
}
