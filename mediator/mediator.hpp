#pragma once
#include <memory>
#include <vector>
#include <format>
#include <iostream>
using namespace std;
class Message;
class Client;
class Server;
class Message{
    protected:
        int client_id;
        string words;
    public:
    Message(int client_id, string words):client_id(client_id), words(words){};
        string toString(){
            return format("client {0}: {1}", client_id, words);
        }
};

class Client{
    protected:
        int id;
        shared_ptr<Server> server;
        vector<Message> messages;
    public:
        Client(const Client&other){
            id=other.id;
            server=other.server;
        }
        Client(int id, shared_ptr<Server> server):id(id), server(server){};
        void receive(Message message){
            messages.push_back(message);
        }
        void send(string words);
        vector<Message> getMessages(){
            return messages;
        }
        void queryAllMessages();
        void readMessage(){
            for(auto message:messages){
                cout<<message.toString()<<endl;
            }
        }
};



class Server{
    protected:
        vector<Message> messages;
        int index_sent;
        int index_received;
        vector<shared_ptr<Client>> clients;
    public:
        void receive(Message message){
            messages.push_back(message);
            index_received++;
        }
        void send();
        void addClient(shared_ptr<Client> client);
        vector<Message> getMessages(){
            return messages;
        }
};