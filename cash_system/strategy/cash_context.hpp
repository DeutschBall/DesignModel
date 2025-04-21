#pragma once
#include <vector>
#include "cash.hpp"


class CashContext {
    private:
        std::vector<CashSuper *> cashes;        //多重活动
    public:
        void addCashStrategie(CashSuper *cash){
            cashes.push_back(cash);
        }
        double calculate(double money){
            double result = money;
            for(auto cash:cashes){
                result = cash->cash(result);
            }
            return result;
        }
        virtual ~CashContext(){
            for(auto cash:cashes){
                if(cash!=nullptr){
                    delete cash;
                }
            }   
        }
};