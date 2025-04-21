#include <iostream>
#include <memory>
#include "algorithm.hpp"
#include "algorithmvisitor.hpp"
using namespace std;
int main(){
    //1+2+3*4*5+6*7+8

    auto operand1 = make_shared<Operand>(1);
    auto operand2 = make_shared<Operand>(2);
    auto operand3 = make_shared<Operand>(3);
    auto operand4 = make_shared<Operand>(4);
    auto operand5 = make_shared<Operand>(5);
    auto operand6 = make_shared<Operand>(6);
    auto operand7 = make_shared<Operand>(7);
    auto operand8 = make_shared<Operand>(8);


    auto root = make_shared<OperatorPlus>();
    
    auto operatorMultiply1 = make_shared<OperatorMultiply>();
    auto operatorMultiply2 = make_shared<OperatorMultiply>();

    operatorMultiply1->addOperand(operand3);
    operatorMultiply1->addOperand(operand4);
    operatorMultiply1->addOperand(operand5);

    operatorMultiply2->addOperand(operand6);
    operatorMultiply2->addOperand(operand7);

    root->addOperand(operand1);
    root->addOperand(operand2);
    root->addOperand(operatorMultiply1);
    root->addOperand(operatorMultiply2);
    root->addOperand(operand8);

    auto visitor = make_shared<Visitor>();

    cout<<visitor->visit(root)<<endl;

    return 0;
}