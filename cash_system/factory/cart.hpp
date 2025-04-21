#pragma once
#include <vector>
#include "order.hpp"
class Cart{
    std::vector<Order> orders;
    public:
    void addOrder(Order order){
        orders.push_back(order);
    }
    double sum(){
        double total = 0;
        for(auto order:orders){
            total += order.sum();
        }
        return total;
    }
};