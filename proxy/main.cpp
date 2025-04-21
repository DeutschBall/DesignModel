#include <iostream>
#include "proxy.hpp"
using namespace std;
int main(){
    RealSubject *realSubject = new RealSubject();
    Proxy proxy(realSubject);
    proxy.request();
    return 0;
}