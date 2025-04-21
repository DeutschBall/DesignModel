#include <iostream>
#include "singleton.hpp"
using namespace std;

int main(){
    SingletonLazy &singletonlazy = SingletonLazy::getSingletonLazy();
    cout<<&singletonlazy<<endl;
    return 0;
}