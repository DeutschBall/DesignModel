#include <iostream>
#include "resume.hpp"
using namespace std;
int main(){
    Resume *resume = new Resume();
    resume->setName("John");
    resume->setTelephone("1234567890");
    resume->setAge(25);
    cout<<(*resume)<<endl;

    Resume *resume2 = resume->clone();
    resume2->setName("Jane");
    cout<<(*resume2)<<endl;

    return 0;
}