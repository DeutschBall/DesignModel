#pragma once 
#include <iostream>
#include <mutex>
#include <memory>
using std::mutex;
using std::unique_ptr;
using std::make_unique;
class final SingletonLazy{
    private:
        SingletonLazy(){
            std::cout<<"SingletonLazy constructor called"<<std::endl;
        }
        ~SingletonLazy()=default;
    public:
        SingletonLazy(const SingletonLazy &) = delete;
        SingletonLazy& operator=(const SingletonLazy&) = delete;
        SingletonLazy(SingletonLazy&&) = delete;
        SingletonLazy& operator=(SingletonLazy&&) = delete;
    public:
        static SingletonLazy& getSingletonLazy(){
            static SingletonLazy instance;
            return instance;
        }
};

class SingletonHungry{
    private:
        static SingletonHungry *singletonhungry;//只能以指针形式实现,如果作为类的成员变量,则会造成循环引用
        SingletonHungry(){
            std::cout<<"SingletonHungry constructor called"<<std::endl;
        }
        ~SingletonHungry()=default;
    public:
        SingletonHungry(const SingletonHungry &) = delete;
        SingletonHungry& operator=(const SingletonHungry&) = delete;
        SingletonHungry(SingletonHungry&&) = delete;
        SingletonHungry& operator=(SingletonHungry&&) = delete;
    public:
        static SingletonHungry& getSingletonHungry(){
            return *singletonhungry;
        }
};
SingletonHungry *SingletonHungry::singletonhungry = new SingletonHungry;