#pragma once 
#include "GameComponent.h"
#include <iostream>


using namespace std;

class DrawableGameComponent : public GameComponent{
private:
    void ChangeDirection(); // declares the change direction function 
    void Draw(); // declaration for the draw function 
    int x; 
    int y;
    string directionSelected; // this holds the value of the direction

public:
        enum Direction {left, right, up, down};
    Direction direction;
    DrawableGameComponent(int x, int y); // constructor with the parameters x and y 
    const int SCREEN_HEIGHT = 20; // set the screenheight to 0.2 
    const int SCREEN_WIDTH = 80; // set screenwidth to 0.8 
    void Update(const tm* eventTime); //  declares the update function 
};