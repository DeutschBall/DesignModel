#include <iostream>
#include "flyweight.hpp"
using namespace std;
int main(){
    auto db = make_shared<UserDB>();
    db->insertUser(make_shared<User>("Alice", "123456"));
    db->insertUser(make_shared<User>("Bob", "abcdef"));

    auto online = make_shared<UserOnline>(db);
    string alice_token = online->login("Alice", "123456");
    string bob_token = online->login("Bob", "abcdef");
    cout<<alice_token<<endl;
    cout<<bob_token<<endl;

    auto alice = online->getUserByToken(alice_token);
    auto bob = online->getUserByToken(bob_token);
    cout<<alice->getUsername()<<endl;
    cout<<alice->getPassword()<<endl;

    return 0;
}