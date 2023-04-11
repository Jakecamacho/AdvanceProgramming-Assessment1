#pragma once // Use header file only once when compiling source code
# include <iostream>

using namespace std;


class GameComponent {
private:
    int id; // this stores the gamecomponent/ drawablegamecomponent ID
    static int instances;  // this is a static variable and is used throughout the programme to holf the number of instance of GameComponent and DrawableGameComponent 

public:
    GameComponent(); // constructor 
    virtual void Update(const tm*); // date and time pointer (tm*) -- the const specifies to the complier that the variables value is constant to prevent the programmer modifying it 

};