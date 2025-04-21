#pragma once
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::list;
using std::find;


class Observerable{ //观察者接口
  public:
    virtual void update()=0;
    virtual string getSubjectAction()=0;
};

class Subjectable //发布者接口
{
  public:
    virtual void attach(Observerable* observer) = 0;
    virtual void detach(Observerable* observer) = 0;
    virtual void notify() = 0;
    virtual string getAction() = 0;
    virtual void setAction(string action) = 0;
};

class Subject:public Subjectable{
  protected:
    list<Observerable*> observers;
    string action;
  public:
    void attach(Observerable* observer){
      observers.push_back(observer);
    }
    void detach(Observerable* observer){
      observers.remove(observer);
    }
    void notify(){
      for(auto observer:observers){
        observer->update();
      }
    }
    string getAction(){
      return action;
    }
    void setAction(string action){
      this->action = action;
    }
};





class Observer:public Observerable{
  protected:
    Subjectable* subject;
  public:
    Observer(Subjectable* subject){
      this->subject = subject;
    }
    void update(){
      cout<<"Observer update: "<<getSubjectAction()<<endl;
    }
    string getSubjectAction(){
      return subject->getAction();
    }
};

class StockObserver:public Observer{
  protected:
    string name;
  public:
    StockObserver(Subjectable* subject,string name):Observer(subject){
      this->name = name;
    }
    void update(){
      cout<<name<<" stock observer update: "<<getSubjectAction()<<endl;
    }
};