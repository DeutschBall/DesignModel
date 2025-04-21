#include <iostream>
#include <vector>
#include "observer.hpp"
using namespace std;
int main(){
  Subject * subject = new Subject();
  subject -> setAction("Imperial March!");
  StockObserver *ob1 = new StockObserver(subject,"sjh");
  StockObserver *ob2 = new StockObserver(subject,"dst");
  subject -> attach(ob1);
  subject -> attach(ob2);
  subject -> notify();

  return 0;
}