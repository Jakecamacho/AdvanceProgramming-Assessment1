// # include "StdAfx.h" 
#include <thread>
#include "Game.h"
#include "GameComponent.h"


void Game:: Add(GameComponent* component){
    components[componentCount++] = component; // adds gamecomponent/drawablegamecomponent to array of pointers with type gamecomponent 
}

Game:: Game(int maxComponents){ 
    // maxComponents = 5;
    // components = new GameComponent * [maxComponents];
}

void Game:: SetInitialise(FP init){ // assigns the  address of function to initialise data member
    initialise = init;
}

void Game:: SetTerminate(FP term) { // assigns the  address of function to terminate data member
    terminate = term;
}

void Game:: Run() {
    initialise(); // invoked function with initalise pointer defined above
    cout<< "Initialising game" <<endl; 
    for (auto &component: components) { // for loop which stated for each component in the components array, loop through the number of components
        for (int i = 0; i < componentCount; i++){
            auto currentTime = chrono::system_clock::now(); //  points to current time 
            auto timeT = chrono::system_clock::to_time_t(currentTime); // converts current time to type time 
            tm *time = localtime(&timeT); // fills the tm struct with the current time 
            components[i] -> Update(time); // calls the update function on the component using the current time 
        };
        std::this_thread::sleep_for(std::chrono::milliseconds(TICKS_1000MS)); // ensure the game pauses for 1seconds each time 
    }
    terminate();
    cout<< "Terminating game" <<endl;
};

// standalone function is a function (subprogram that returns a single value) that is stored in a database 
// TICKS_1000MS time stuff 