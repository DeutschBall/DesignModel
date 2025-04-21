#pragma once
#include "cash.hpp"
#include <string>
class CashFactory{
    public:
        static CashSuper* createCash(const std::string& type){
            CashSuper * cash = NULL;
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
            return cash;
        }
};