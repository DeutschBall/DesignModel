#include <iostream>
#include <cstdlib>
#include "snake.hpp"
using namespace std;
int main(){
    SnakeGame game(10,10);
    game.show();
    game.start();
    game.show();
    char op;
    SnakeStatus status;
    while(op=getchar()){
        // system("clear");
        Direction direction;
        switch(op){
            case 'a':
                direction = LEFT;
                break;
            case 's':
                direction = DOWN;
                break;
            case 'd':
                direction = RIGHT;
                break;
            case 'w':
                direction = UP;
                break;
            default:
                direction = NONE;
                break;
        }
        status = game.move(direction);
        game.show();
        if(status!=LIVE)break;
    }
    cout<<"Game Over"<<endl;
    return 0;
}