#include <iostream>
#include "builder.hpp"
#include "auto.hpp"
#include "director.hpp"
using namespace std;
int main(){
    AutoDirector director;
    director.setBuilder(new ElectricTruckBuilder());
    Auto* auto1 = director.build();
    cout<<auto1->toString()<<endl;



    double real_distance = auto1->run(20);
    cout<<"Real distance: "<<real_distance<<endl;
    cout<<auto1->toString()<<endl;
    double charged = auto1->charge();
    cout<<"Charged: "<<charged<<endl;   
    delete auto1;
    return 0;
}