#include <memory>
#include <vector>
#include <format>
#include "mediator.hpp"
using namespace std;

void Client::send(string words)
{
    server->receive(Message(id, words));
}
void Client::queryAllMessages()
{
    messages = server->getMessages();
}

void Server::send()
{
    for (int &i = index_sent; i < index_received; i++)
    {
        for (auto &client : clients)
        {
            client->receive(messages[i]);
        }
    }
}
void Server::addClient(shared_ptr<Client> client)
{
    clients.push_back(client);
}
