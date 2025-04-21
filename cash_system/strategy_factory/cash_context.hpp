#pragma once
#include <vector>
#include "cash.hpp"
#include <string>

class CashContext {
    private:
        CashSuper * cash;   
    public:
        CashContext(const std::string &type){
            if(type=="正常收费"){
                cash = new CashNormal();
            }
            else if(type == "8折收费"){
                cash = new CashDiscount(0.8);
            }
            else if(type == "满20减5"){
                cash = new CashReturn(20,5);
            }
            else{
                cash = new CashNormal();
            }
        }

        double calculate(double money){
            return cash->cash(money);
        }
        virtual ~CashContext(){
            if(cash!=NULL){
                delete cash;
                cash = NULL;
            }
        }
};