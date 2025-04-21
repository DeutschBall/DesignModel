#include <iostream>
#include <memory>
#include "command.hpp"
using namespace std;
int main(){
    shared_ptr<Executor> executor = make_shared<Executor>();                //接受者
    shared_ptr<Command> command = make_shared<EchoCommand>(executor);       //命令类型
    shared_ptr<Invoker> invoker = make_shared<Invoker>(command,";whomai");  //执行者, 需要告知命令参数
    invoker->invoke();  //执行预先设置好的命令,与参数

    invoker->setCommand(make_shared<IfconfigCommand>(executor)); //设置新的命令
    invoker->setArgline("eth0"); //设置新的参数
    invoker->invoke();  //执行新的命令,与参数
    return 0;
}