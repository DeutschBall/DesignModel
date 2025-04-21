#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <functional>
using namespace std;
class User{
    protected:
        string username;
        string password;
    public:
        User(string username,string password):username(username),password(password){}
        User(const User& other):username(other.username),password(other.password){}
        string getUsername(){
            return username;
        }
        string getPassword(){
            return password;
        }

};

class UserDB{
    protected:
        vector<shared_ptr<User>> userlist;
    public:
        shared_ptr<User> selectUserByUsername(string username){
            for(auto user:userlist){
                if(user->getUsername() == username){
                    return user;
                }
            }
            return nullptr;
        }
        void insertUser(shared_ptr<User> user){
            userlist.push_back(make_shared<User>(*user));
        }
};

class UserOnline{
    protected:
        hash<string> hasher;
        map<string, shared_ptr<User>> sessions;
        shared_ptr<UserDB> userdb;
    public:
        UserOnline(shared_ptr<UserDB> userdb):userdb(userdb){}


        string login(string username,string password){
            shared_ptr<User> user = userdb->selectUserByUsername(username);
            if(user==nullptr||user->getPassword() != password){
                return "Invalid username or password";
            }
            string token = username + password + to_string(hasher(username+password));
            if(sessions.find(token)== sessions.end()){
                sessions[token] = user;
            }
            return token;
        }
        shared_ptr<User> getUserByToken(string token){  //一个token只产生一个User对象, 只要是同一个token, 就返回已经登录的对象
            if(sessions.find(token)== sessions.end()){
                return nullptr;
            }
            return sessions[token];
        }
        void logout(string token){
            sessions.erase(token);
        }
};
