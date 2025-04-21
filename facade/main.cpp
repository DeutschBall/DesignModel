#include <iostream>
#include "facade.hpp"
using namespace std;
int main(){ 
    Facade * facade = new Facade();
    facade->method();           //facade封装了多个子系统,对外提供一个接口,子系统对外不可见
    delete facade;
    return 0;
}