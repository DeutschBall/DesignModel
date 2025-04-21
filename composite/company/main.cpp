#include <iostream>
#include <memory>
#include "Component.hpp"
using namespace std;

int main(){
    shared_ptr<Department> root = make_shared<Company>("shan dong");

    shared_ptr<Department> jinan = make_shared<Company>("ji nan");
    shared_ptr<Department> qingdao = make_shared<Company>("qingdao");
    shared_ptr<Department> taian = make_shared<Company>("taian");

    root->addDepartment(jinan);
    root->addDepartment(qingdao);
    root->addDepartment(taian);
    cout<<root->toString(0)<<endl;
    return 0;
}