#pragma once
#include <iostream>
#include <string>
#include <format>
using std::cout;
using std::string;
using std::format;
class Component{
    public:
    virtual string toString() = 0;
};

class Coffee :public Component{
    public:
    string toString(){
        return "Coffee";
    }
};
class Americano :public Coffee{
    public:
    string toString(){
        return "Americano";
    }
};




class Flavour :public  Component{      //Decorator
    private:
    Component* component;
    public:
    void setComponent(Component* c){
        component = c;
    }
    virtual string getName(){
        return "Flavour";
    }
    string toString(){
        string str = format("({0}),{1}",component->toString(),getName());
        return str;
    }
};

class Ice: public Flavour{
    public:
    string getName(){
        return "Ice";
    }
};
class Milk:public Flavour{
    public:
    string getName(){
        return "Milk";
    }
};

