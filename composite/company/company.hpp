#pragma once
#include <vector>
#include <memory>
#include <string>
using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;



class Department{
    private:
        string name;
        vector<shared_ptr<Department>> departments;
        virtual string report(){
            return "normal department";
        }
    public:
        Department(string name):name(name){};
        void addDepartment(shared_ptr<Department> department){
            departments.push_back(department);
        }
        
        string toString(int tab){
            string indent;
            for(int i=0;i<tab;i++)indent+=" ";
            string ans = indent + name + ": "+report()+'\n';
            ans+= indent+ "{";
            if(!departments.empty()){
                ans+='\n';
                for(auto department:departments){
                    ans += department->toString(tab+4) + "\n";
                }
                ans+=indent;
            }
            ans += "}";
            return ans;
        }

};

class HumanResource:public Department{
    private:
        string report(){
            return "seeking for talents...";
        }
    public:
        HumanResource():Department("Human Resource"){};
};
class Finance:public Department{
    private:
        string report(){
            return "managing financial resources...";
        }
    public:
        Finance():Department("Finance"){};
};
class Marketing:public Department{
    private:
        string report(){
            return "promoting products...";
        }
    public:
        Marketing():Department("Marketing"){};
};
class Sales:public Department{
    private:
        string report(){
            return "selling products...";
        }
    public:
        Sales():Department("Sales"){};
};

class Company: public Department{
    private:
        string report(){
            return "headerquater";
        }
    public:
        Company(string name):Department(name){
            addDepartment(make_shared<HumanResource>());
            addDepartment(make_shared<Finance>());
            addDepartment(make_shared<Marketing>());
        };
};