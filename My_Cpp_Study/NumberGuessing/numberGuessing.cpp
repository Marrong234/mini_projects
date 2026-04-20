#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){

    srand(time(0));
    int answerNumber = rand() % 100 + 1;
    int guessingNumber;
    int tries = 0;

    std::cout << "===Welcome to the number guessing game===\n";
    
    do{
        std::cout << "What is your guess?(1~100): ";
        std::cin >> guessingNumber;
        tries++;

        if(guessingNumber > answerNumber){
            std::cout << "---Too Big---\n";
        }
        else if(guessingNumber < answerNumber){
            std::cout << "---Too Small---\n";
        }
        else{
            std::cout << "====Correct!===\n";
            std::cout << "Number of tries: " << tries << "\n";
            break;
        }

    }while(guessingNumber != answerNumber);

    std::cout << "Game over";


    return 0;
}