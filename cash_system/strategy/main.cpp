#include <iostream>
#include "cart.hpp"
#include "cash_context.hpp"
#include "cash.hpp"
using namespace std;

int main(){
    Cart cart;
    cart.addOrder({5.2,3});
    cart.addOrder({1.5,2});
    cart.addOrder({3.7,1});
    cart.addOrder({2.3,4});
    cart.addOrder({4.1,1});
    double sum = cart.sum();

    CashContext cashContext;
    cashContext.addCashStrategie(new CashDiscount(0.8));
    cashContext.addCashStrategie(new CashReturn(20,5)); //多种促销策略

    double result = cashContext.calculate(sum);
    cout<<result<<endl;

    return 0;
}