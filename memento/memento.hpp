#pragma once
#include <vector>
#include <memory>
#include <string>
using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;



class State{//此类用于保存对象状态
    public:
        double healthy_power;
        double experience;
        int level;
        double attack;
        double defense;        
        State(double h=100,double e=0,int l=0,double a=10,double d=10):healthy_power(h),experience(e),level(l),attack(a),defense(d){}
        State(const State &s){
            healthy_power = s.healthy_power;
            experience = s.experience;
            level = s.level;
            attack = s.attack;
            defense = s.defense;
        }
        State(shared_ptr<State> state){
            healthy_power = state->healthy_power;   
            experience = state->experience;
            level = state->level;
            attack = state->attack;
            defense = state->defense;
        }
        string toString(){
            return "Healthy Power: "+std::to_string(healthy_power)+", Experience: "+std::to_string(experience)+", Level: "+std::to_string(level)+", Attack: "+std::to_string(attack)+", Defense: "+std::to_string(defense);
        }
};

class Memento{      //备忘录类,负责存储
    private:
        shared_ptr<State>state;
    public:
        Memento(shared_ptr<State>state){
            this->state = make_shared<State>(state);
        }
        shared_ptr<State> getState(){
            return state;
        }
};

class Player{       //Originator
    private:
        string name;
        shared_ptr<State> state;
    public:
        shared_ptr<Memento> createMemento(){
            return make_shared<Memento>(state);
        }
        void setMemento(shared_ptr<Memento>memento){
            state = memento->getState();
        }
        Player(string n):name(n){
            state = make_shared<State>();
        }
        string toString(){
            return "Name: "+name+", State: "+state->toString();
        }
        void levelUp(){
            state->healthy_power += 10;
            state->level++;
            state->attack += 10;
            state->defense += 10;
        }
};

class Caretaker{    //负责存储所有状态快照
    private:
        vector<shared_ptr<Memento>> mementos;
    public:
        void addMemento(shared_ptr<Memento>memento){
            mementos.push_back(memento);
        }
        shared_ptr<Memento> getMementoByIndex(int index){
            return mementos[index];
        }
};