#pragma once
#include <iostream>
#include <memory>
#include <vector>
using std::shared_ptr;
using std::vector;
using std::make_shared;
enum Identity{  //幺元
    AddIdentity = 0,
    MultiplyIdentity = 1,
};
class Component{
    public:
        virtual double visit()=0;
};
class Operand:public Component{
    double value;
    public:
        Operand(double value):value(value){};
        double visit(){
            return value;
        }
        void setValue(double value){
            this->value = value;
        }
};
class Operator:public Component{
    private:
        vector<shared_ptr<Component>> operands; //此处operands可能是一个真的Operand, 也可能是一个Operator
        virtual double handle(double a,double b) = 0;
    public:
        double visit(){
            double result = getBase();
            for(auto operand:operands){
                result = handle(result,operand->visit());
            }
            return result;
        }
        void addOperand(shared_ptr<Component> operand){
            operands.push_back(operand);
        }
        virtual double getBase() = 0;
};

class MultiplyOperator:public Operator{
    private:
        double handle(double a,double b){
            return a*b;
        }
        double getBase(){
            return MultiplyIdentity;
        }
    public:

};
class AddOperator:public Operator{
    private:
        double handle(double a,double b){
            return a+b;
        }
        double getBase(){
            return AddIdentity;
        }
    public:
        
};
