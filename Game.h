#pragma once 
#include <iostream>
#include "GameComponent.h"

using namespace std;


typedef void (*FP)(); // initialises the function pointer 

class Game {
private:
    int componentCount = 0; // holds the number of components in an array
    GameComponent* components[5]{}; //initalise game component array to 5 
    FP initialise; //pointer to initialise function 
    FP terminate; //pointer to terminate function 
    int TICKS_1000MS = 1000; //holds the value of 1000 miliseconds so the game runs for 1s 
public:
    void Add(GameComponent*);
    Game(int maxComponents); // constructor with the parameter maxComponents 
    void Run(); //declaration to run the function 
    void SetInitialise(FP init); // declaration to initalise the function 
    void SetTerminate(FP term); // declaration to terminate the function 
};