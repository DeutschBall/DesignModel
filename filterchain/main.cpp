#include <iostream>
#include <vector>
#include <memory>
#include "filter.hpp"
using namespace std;
int main(){
    string request = "Hello&world|>aab";
    string response;

    shared_ptr<FilterChain> filterchain = make_shared<FilterChain>();
    filterchain->addFilter(make_shared<SecureFilter>());
    filterchain->addFilter(make_shared<UpplerCaseFilter>());
    filterchain->doFilter(request,response);
    cout<< request<<endl;
    cout<< response<<endl;
    return 0;
}