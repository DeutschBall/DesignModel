#include <iostream>
#include "composite.hpp"
#include <string>
#include <memory>
using namespace std;
//1+2+3*4*5+6+7*8+9 = 134
int main(){
    shared_ptr<Operator> oplus = make_shared<AddOperator>();
    oplus->addOperand(make_shared<Operand>(1));
    oplus->addOperand(make_shared<Operand>(2));
    shared_ptr<Operator> omulti1 = make_shared<MultiplyOperator>();
    oplus->addOperand(omulti1);
    oplus->addOperand(make_shared<Operand>(6));
    shared_ptr<Operator> omulti2 = make_shared<MultiplyOperator>();
    oplus->addOperand(omulti2);
    oplus->addOperand(make_shared<Operand>(9));


    omulti1->addOperand(make_shared<Operand>(3));
    omulti1->addOperand(make_shared<Operand>(4));
    omulti1->addOperand(make_shared<Operand>(5));

    omulti2->addOperand(make_shared<Operand>(7));
    omulti2->addOperand(make_shared<Operand>(8));

    cout<<oplus->visit()<<endl;

    return 0;
}