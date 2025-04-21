#include "Coffee.hpp"
#include <iostream>
using namespace std;
int main(){
    Coffee * americano = new Americano();
    Flavour * flavour1 = new Ice();
    Flavour * flavour2 = new Milk();

    flavour1->setComponent(americano);
    flavour2->setComponent(flavour1);
    cout << flavour2->toString() << endl;



    return 0;
}