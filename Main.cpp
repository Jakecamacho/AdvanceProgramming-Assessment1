#include <iostream>
#include "Game.h" // include Game header file 
#include "DrawableGameComponent.h" // include DrawableGameComponent header file 
#include "GameComponent.h" // include GameComponent header file 

using namespace std;

void initialiseGame (){
    cout << "The game has been initialised" << endl; // delcared and defined the intialise function which is invoked when it has the standalone function address.
}

void terminateGame (){
    cout << "The game has now finished" << endl; // delcared and defined the terminate function which is invoked when it has the standalone function address.
}

int main(){
    Game game(1); // creates a dynamic instance of the game
    game.SetInitialise(initialiseGame); // this invokes the SetIntialise Function 
    game.SetTerminate (terminateGame);// this invokes the SetTerminate Function
    game.Add(new GameComponent()); // this adds a GameComponent to the Game object which will have an ID of 1 
    game.Add(new DrawableGameComponent(0,0)); //this add a DrawableGameComponent to the game object which will have an IF of 2 and will also have a position of (x=0, y=0)
    game.Run(); // invokes the game 
}