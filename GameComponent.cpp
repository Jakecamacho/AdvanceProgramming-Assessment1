# include "GameComponent.h"

int GameComponent:: instances;

GameComponent:: GameComponent(){
    ++instances;
    this->id = instances;
};

void GameComponent:: Update(const tm* time) {
    cout << "Object ID : " << id << " Updated @ " << asctime(time) << endl;
}