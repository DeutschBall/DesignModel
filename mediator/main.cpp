#include <iostream>
#include <vector>
#include <memory>
#include "mediator.hpp"
using namespace std;
int main(){
    shared_ptr<Server> server = make_shared<Server>();
    shared_ptr<Client> client1 = make_shared<Client>(1,server);
    shared_ptr<Client> client2 = make_shared<Client>(2,server);
    shared_ptr<Client> client3 = make_shared<Client>(3,server);

    server->addClient(client1);
    server->addClient(client2);
    server->addClient(client3);

    client1->send("Hello from client 1!");
    client2->send("Hello from client 2!");
    
    client3->readMessage();
    cout<<"---------------------------"<<endl;
    server->send();
    client3->readMessage();
    cout<<"---------------------------"<<endl;

    
    auto client4 = make_shared<Client>(4,server);
    server->send();                     //server并无新的消息广播
    client4->readMessage();             //client4新加入, 不知道历史消息
    cout<<"---------------------------"<<endl;
    client4->queryAllMessages();        //client4向服务器查询所有历史消息
    client4->readMessage();

    return 0;
}