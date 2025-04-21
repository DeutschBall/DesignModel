#pragma once
#include "visitor.hpp"
#include "algorithm.hpp"


class Visitor : public AbstractVisitor
{
    public:
    virtual double visitOperatorPlus(shared_ptr<OperatorPlus> oprator){
        double result = 0;
        int number_of_operands = oprator->getNumberOfOperands();
        for(int i=0;i<number_of_operands;i++){
            result += visit(oprator->getOperandByIndex(i));
        }
        return result;
    }
    virtual double visitOperatorMultiply(shared_ptr<OperatorMultiply> oprator){
        double result = 1.0;
        int number_of_operands = oprator->getNumberOfOperands();
        for(int i=0;i<number_of_operands;i++){
            auto operand = oprator->getOperandByIndex(i);
            result *= operand->accept(shared_ptr<Visitor>(this));
        }
        return result;
    }
    virtual double visitOperand(shared_ptr<Operand> operand){
        return operand->getValue();
    }
};