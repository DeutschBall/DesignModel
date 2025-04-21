#pragma once
#include "cart.hpp"

class CashSuper{
    public:
        virtual double cash(int money)=0;
};

class CashNormal:public CashSuper{
    public:
        double cash(int money){
            return money;
        }
};

class CashDiscount:public CashSuper{
    private:
        double discount;
    public:
        double cash(int money){
            return money*discount;
        }
        CashDiscount(double discount = 1.0):discount(discount){}
};

class CashReturn:public CashSuper{
    private:
        double condition;
        double cashback;
    public:
        double cash(int money){
            double total = money;
            if(total>=condition){
                total -= cashback;
            }
            return total;
        }
        CashReturn(double condition, double cashback):condition(condition),cashback(cashback){}
};
