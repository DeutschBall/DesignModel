#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
using std::vector;
using std::queue;
using std::ostream;
using std::cout;
using std::endl;
using std::deque;
using std::setw;
enum SnakeStatus{
    LIVE,
    SUISIDE,
    CRASH,
    WIN
};

enum Direction{
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum PointType{
    EMPTY,
    SNAKE_BODY,
    SNAKE_HEAD,
    WALL,
    FOOD
};
const char logo[] = {
    ' ',
    'O',
    '$',
    '+',
    'x'
};

struct Point{
    int x;
    int y;
};

class Snake{
    deque<Point> dq;

    public:
    void move(Point p){
        dq.push_front(p);
    }
    void lost(){
        dq.pop_back();
    }
    void grow(Point p){
        dq.push_back(p);
    }
    Point head(){
        return dq.front();
    }
    Point tail(){
        return dq.back();
    }
    int length(){
        return dq.size();
    }
};



class Matrix{

    vector<vector<PointType>> matrix;
    void init(int rows,int cols){
        matrix.resize(rows);
        for(auto &r:matrix){
            r.resize(cols);
        }
        for(auto &r:matrix){
            for(auto &c:r){
                c = EMPTY;
            }
        }
        for(int i=0;i<rows;i++){
            matrix[i][0] = WALL;
            matrix[i][cols-1] = WALL;
        }
        for(int j=0;j<cols;j++){
            matrix[0][j] = WALL;
            matrix[rows-1][j] = WALL;
        }
    }
public:
int rows;
int cols;
    Matrix(int rows,int cols):rows(rows),cols(cols){
        init(rows,cols);
    }
    void setPoint(int x,int y,PointType type){
        matrix[x][y] = type;
    }
    PointType getPoint(int x,int y){
        return matrix[x][y];
    }


};


class SnakeGame{

    Matrix map;
    Snake snake;
    bool hasFood;

    bool generateFood(){
        int food_x;
        int food_y;
        do{
            food_x = rand()%map.rows;
            food_y = rand()%map.cols;
        }while(map.getPoint(food_x,food_y)!= EMPTY);
        map.setPoint(food_x,food_y,FOOD);
        hasFood = true;
        return true;
    }
    public:
    
    SnakeGame(int rows,int cols):map(rows,cols){
        int row_center = rows/2;
        int col_center = cols/2;

    }
    bool start(){
        int col_center = map.cols/2;
        int row_center = map.rows/2;
        snake.move({row_center,col_center});
        map.setPoint(row_center,col_center,SNAKE_HEAD);
        if(!generateFood()){
            return false;
        }
        return true;
    }
    SnakeStatus move(Direction dir){
        Point head = snake.head();
        Point tail = snake.tail();
        int head_x = head.x;
        int head_y = head.y;

        int tail_x;
        int tail_y;

        int new_x = head_x;
        int new_y = head_y;
        
        switch(dir){
            case UP:
                new_x--;
                break;
            case DOWN:
                new_x++;
                break;
            case LEFT:
                new_y--;
                break;
            case RIGHT:
                new_y++;
                break;
            default:
                return LIVE;
                break;
        }
        new_x %= map.rows;
        new_y %= map.cols;
        tail_x = tail.x;
        tail_y = tail.y;
        snake.lost();
        map.setPoint(tail_x,tail_y,EMPTY);
        PointType type = map.getPoint(new_x,new_y);
        SnakeStatus status = LIVE;
        switch(type){
            case SNAKE_BODY:
                status =  SUISIDE;
                break;
            case WALL:
                status = CRASH;
                break;
            case FOOD:
                map.setPoint(new_x,new_y,SNAKE_BODY);
                snake.grow(tail);
                map.setPoint(tail_x,tail_y,SNAKE_BODY);
                hasFood = false;
                if(!generateFood())return WIN;
                status = LIVE;
            case EMPTY:
                snake.move({new_x,new_y});
                map.setPoint(new_x,new_y,SNAKE_HEAD);
                if(snake.length()>1)
                    map.setPoint(head_x,head_y,SNAKE_BODY);
                status = LIVE;
                break;
        }
        return LIVE;
    }


    void show(){
        for(int i=0;i<map.rows;i++){
            for(int j=0;j<map.cols;j++){
                PointType type = map.getPoint(i,j);
                cout<<setw(2)<<logo[type];
            }
            cout<<endl;
        }
    }
};
