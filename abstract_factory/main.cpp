#include <iostream>
#include "factory.hpp"
using namespace std;
int main(){
    ITAbstractFactory* factory = new AppleFactory();            //品牌工厂
    AbstractComputer* computer = factory->manuComputer();       //
    computer->compute();

    return 0;
}