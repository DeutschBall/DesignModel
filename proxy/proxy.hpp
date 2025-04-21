#pragma once
#include <iostream>
using std::cout;
using std::endl;

class RealSubject{
    public:
        void request(){
            std::cout << "RealSubject::request()" << std::endl;
        }
};

class Proxy{
    private:
        RealSubject* realSubject;
        void preRequest(){
            std::cout << "Proxy::preRequest()" << std::endl;
        }
        void postRequest(){
            std::cout << "Proxy::postRequest()" << std::endl;
        }
    public:
        Proxy(RealSubject* r):realSubject(r){}

        void request(){
            preRequest();           //前置操作
            realSubject->request();
            postRequest();          //后置操作
        }

};