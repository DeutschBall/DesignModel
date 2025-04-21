#pragma once
#include <iostream>
using std::cout, std::endl;

class Context;
class State;
class InitState;
class StartState;
class RunningState;

class State{
    public:
        virtual void handle(Context* context) = 0;   
};


class Context{
    protected:
        State*  state;
    public:
        Context(State*  s):state(s){}
        State* getState(){
            return state;
        }
        void setState(State*  s){
            if(state!=NULL){
                delete state;
                state = NULL;
            }
            state = s;
        }
        void request(){
            state->handle(this);
        }
        virtual ~Context(){
            if(state!=NULL){
                delete state;
                state = NULL;
            }
        }
};
class RunningState: public State{
    public:
        void handle(Context* context);
};

class StartState: public State{
    public:
        void handle(Context* context);
};
class InitState : public State{
    public:
         void handle(Context* context);
};

void RunningState::handle(Context* context){
    cout << "RunningState::handle()" << endl;
    context->setState(new StartState());
}

void InitState::handle(Context* context){
    cout << "InitState::handle()" << endl;
    context->setState(new StartState());
}

void StartState::handle(Context* context){
    cout << "StartState::handle()" << endl;
    context->setState(new RunningState());
}