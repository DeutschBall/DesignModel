#include <iostream>
#include "state.hpp"
using namespace std;
int main(){
    Context * context = new Context(new InitState());
    for(int i=0;i<=10;i++){
        context->request();
    }

    return 0;
}