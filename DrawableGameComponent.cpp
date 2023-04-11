# include "DrawableGameComponent.h"

DrawableGameComponent:: DrawableGameComponent(int x, int y): GameComponent(){
        this->x = x; // sets x coordinate 
        this->y = y; // sets x coordinate 
        direction = right; // set direction as right as stated in the assignment brief
}; 

void DrawableGameComponent:: Update(const tm* eventTime){
    GameComponent::Update(eventTime); // inherits update method from Gamocomponent, printing ID and updated time (polymorphism)
    ChangeDirection(); // selects a direction and then generates a random number to cast a new direction 
    Draw(); // output the co-ordinates 
};

void DrawableGameComponent:: ChangeDirection(){

        srand(time(NULL)); // generates random seed using the computer internal clock 
        int randomNumber = (rand() % 4) + 1; // generates random number between 1-4
        while (randomNumber == direction) // while the number = the current, then genarate a new one as we do not want the same one 
        randomNumber = (rand() % 4) + 1; 
        direction = static_cast<Direction>(randomNumber); // set direction 

        if (randomNumber == 1) // this sets the direction depending on what random number has been generated 
        {
            direction = up; 
        }
        else if (randomNumber == 2)
        {
            direction = down;
        }
        else if (randomNumber == 3)
        {
            direction = left;
        }
        else if (randomNumber == 4)
        {
            direction = right;
        };

        switch (direction) {
        case left: // case statement for the change in direction 
            x--; // Decrement X co-ordinate by 1
            if (x < 0) { // ensure the new value of X is not less than 0 and if it is then reset it to 0
                x = 0; 
            }
            directionSelected = "Left"; // Set direction "Left"
            break;
        case right: 
            x++; // Increment X co-ordinate by 1
            if (x >
                SCREEN_WIDTH) { //ensure the new value of X is not more than the width of the screen which is set within the header file and if it is then reset it to 80 
                x = SCREEN_WIDTH; 
            }
            directionSelected = "Right"; // Set direction "Right"
            break;
        case up: 
            y++; // Increment X co-ordinate by 1
            if (y >
                SCREEN_HEIGHT) { // ensure the new value of Y is not more than the height of the screen and if so then reset to 20 
                y = SCREEN_HEIGHT; 
            }
            directionSelected = "Up"; /// Set direction "up"
            break;
        case down: 
            y--;// Decrement Y co-ordinate by 1
            if (y < 0) { // ensure the new value of Y is not less than 0 and if so then reset to 0 
                y = 0; 
            }
            directionSelected = "Down"; // Set direction "down"
            break;
        }
};

void DrawableGameComponent:: Draw(){
        cout << directionSelected << " : " << "X Coordinate : " << x << ", Y Coordinate : " << y << endl; // displayed the current direction and co-ordinates
};