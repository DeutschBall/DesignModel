#pragma once
class Order{
    private:
    double price;
    int count;

    public:
    Order(double p=0,int c=1):price(p),count(c){};
    double sum(){
        return price*count;
    }

};