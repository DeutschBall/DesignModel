#pragma once 
#include <memory>
#include "acceptable.hpp"
// #include "algorithmvisitor.hpp"
using namespace std;
class Visitor;
class Operand : public Acceptable
{
protected:
    double value;

public:
    Operand(double value)
    {
        this->value = value;
    }
    double accept(shared_ptr<Visitor> visitor)
    {
        return visitor->visitOperand(shared_ptr<Operand>(this));
    }
    double getValue(){
        return value;
    }
};
class Operator : public Acceptable
{
protected:
    vector<shared_ptr<Acceptable>> operands;

public:
    void addOperand(shared_ptr<Acceptable> operand)
    {
        operands.push_back(operand);
    }
    shared_ptr<Acceptable> getOperandByIndex(int index){
        return operands[index];
    }
    int getNumberOfOperands(){
        return operands.size();
    }
};
class OperatorPlus : public Operator
{
public:
    double accept(shared_ptr<Visitor> visitor)
    {
        return visitor->visitOperatorPlus(shared_ptr<OperatorPlus>(this));
    }
};
class OperatorMultiply : public Operator
{
public:
    double accept(shared_ptr<Visitor> visitor)
    {
        return visitor->visitOperatorMultiply(shared_ptr<OperatorMultiply>(this));
    }
};
