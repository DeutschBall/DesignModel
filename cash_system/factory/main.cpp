#include <iostream>
#include "cart.hpp"
#include "cash_factory.hpp"
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

    CashSuper * cash = CashFactory::createCash("8折收费");
    
    double result = cash->cash(sum);
    
    cout<<result<<endl;

    return 0;
}