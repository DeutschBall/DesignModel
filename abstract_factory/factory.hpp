#pragma once
#include <iostream>
using std::cout;
using std::endl;
class AbstractComputer{
    public:
        virtual void compute() = 0;
};
class MacBook: public AbstractComputer{
    public:
        void compute(){
            std::cout << "Computing on MacBook" << std::endl;
        }
};
class LenovoPad: public AbstractComputer{
    public:
        void compute(){
            std::cout << "Computing on LenovoPad" << std::endl;
        }
};




class AbstractCellPhone{
    public:
        virtual void call() = 0;
};
class IPhone: public AbstractCellPhone{
    public:
        void call(){
            std::cout << "Calling from Apple cellphone" << std::endl;
        }
};
class LenovoCellPhone: public AbstractCellPhone{
    public:
        void call(){
            std::cout << "Calling from Lenovo cellphone" << std::endl;
        }
};



class ITAbstractFactory{
    public:
        virtual AbstractCellPhone* manuCellPhone() = 0;
        virtual AbstractComputer* manuComputer() = 0;
};

class AppleFactory: public ITAbstractFactory{
    public:
        AbstractCellPhone* manuCellPhone(){
            return new IPhone();
        }
        AbstractComputer* manuComputer(){
            return new MacBook();
        }
};

class LenovoFactory: public ITAbstractFactory{
    public:
        AbstractCellPhone* manuCellPhone(){
            return new LenovoCellPhone();
        }
        AbstractComputer* manuComputer(){
            return new LenovoPad();
        }
};
