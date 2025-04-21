#pragma once 
#include <string>
#include <iostream>
#include <format>
#include <memory>
#include <set>
using namespace std;
class Executor{ //Receiver
    protected:
    string filte(string command){  //命令过滤器
        static set<char> blacklist = {//黑名单过滤
            '|','&','(',')','<','>',';'
        };
        string result;
        for(auto c:command){
            if(!blacklist.count(c)){
                result += c;
            }
        }
        return result;
    }
    public:

    int execute(string command){
        cout<<"Executing command: "<<command<<endl;
        command = filte(command);
        cout<<"Filtered command: "<<command<<endl;
        return system(command.c_str());
    }
};


class Command {
    protected:
        shared_ptr<Executor> executor;
        virtual string getCommand() = 0;
    public:
        Command(shared_ptr<Executor> e):executor(e){};
        void execute(string argline=""){
            string command = format("{0} {1}",getCommand(),argline);   //getCommand由具体类型实现
            executor->execute(command);
        }
        
};

class EchoCommand: public Command{
    protected:
    string getCommand(){
        return "echo";
    }
    public:
        EchoCommand(shared_ptr<Executor> e):Command(e){};

};

class IfconfigCommand: public Command{
    protected:
    string getCommand(){
        return "ifconfig";
    }
    public:
        IfconfigCommand(shared_ptr<Executor> e):Command(e){};

};

class Invoker{
    private:
        shared_ptr<Command> command;//命令类型
        string argline;                //命令参数
    public:
        Invoker(shared_ptr<Command> c,string argline):command(c),argline(argline){};
        void setCommand(shared_ptr<Command> c){
            command = c;
        }
        void setArgline(string argline){
            this->argline = argline;
        }
        void invoke(){
            command->execute(argline);
        }
};