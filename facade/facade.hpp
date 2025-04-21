#pragma once
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class SubSystemA{
    public:
        void methodA(){
            cout << "SubSystemA operation" << endl;
        }
};
class SubSystemB{
    public:
        void methodB(){
            cout << "SubSystemB operation" << endl;
        }
};


class Facade{
    private:
        SubSystemA * a;
        SubSystemB * b;
    public:
        Facade(){
            a = new SubSystemA();
            b = new SubSystemB();
        }
        ~Facade(){
            delete a;
            delete b;
        }
        void method(){
            a->methodA();
            b->methodB();
        }
};






