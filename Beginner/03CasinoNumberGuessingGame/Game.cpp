#include "Game.h"

Game::Game(){
    std::cout << "Choose difficulty (1-3): ";
    std::cin >> gameDifficulty;

    prize = 1;
    score = 0;

    switch (gameDifficulty)
    {
    case 1:
        range = 10;
        break;
    case 2:
        range = 30;
        break;
    
    case 3:
        range = 50;
        break;

    default: // If difficulty is not any of opttions, default to easy
        gameDifficulty = 1;
        range = 10;
        break;
    }

    // Init random seed
    srand(time(NULL));
}

int Game::getRandomNumber(){
    //Generate number between 1 and range
    return rand() % range + 1;
}

void Game::givePrize(){
    score += prize;
}

void Game::losingMessage(){
    std::cout << "Poor you. The game finished with " << score << " of score :C \n";
    keepRunning = false;
}

void Game::earningMessage(){
    std::cout << "You matched it! You earn " << prize << " points!\n";
    updateScore();
    std::cout << "Now you own " << score << " points\n";
    std::cout << "Wanna keep playing? 0 = NO, 1 = YES: ";
    int decission = 0;
    std::cin >> decission;

    switch (decission)
    {
    case 0:
        losingMessage();
        break;
    case 1:
        std::cout << "Ok here we go! \n";
        break;
    default:
        losingMessage();
        break;
    }
}

void Game::updateScore(){
    score += prize;
}

int Game::getScore(){
    return score;
}

int Game::getDifficulty(){
    return gameDifficulty;
}

int Game::runGame(){
    keepRunning = true;
    
    std::cout << "Hey! This is a casino game, \nI'll think of a number and if you match it, you'll earn score!\n Let's Begin!\n\n";

    while(keepRunning){
        int rnd = getRandomNumber();

        std::cout << "Hey! Choose a number between 1 and " << range << ": ";
        int guess = 0;
        std::cin >> guess;
        std::cout << "The number was " << rnd << "\n";
        if(guess == rnd){
            earningMessage();
        } else{
            losingMessage();
        }
    }

    return 0;
}