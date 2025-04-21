#pragma once 
#include <iostream>

class SingletonLazy{
    private:
        SingletonLazy(){
            std::cout<<"SingletonLazy constructor called"<<std::endl;
        }
        // ~SingletonLazy()=default;
    public:
        // SingletonLazy(const SingletonLazy &) = delete;
        // SingletonLazy& operator=(const SingletonLazy&) = delete;
    public:
        static SingletonLazy& getSingletonLazy(){
            static SingletonLazy instance;
            return instance;
        }
};
