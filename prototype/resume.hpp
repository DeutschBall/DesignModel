#pragma once
#include <string>
#include <format>
using std::string;
using std::ostream;
using std::format;

class Cloneable {
    public:
        virtual Cloneable *clone() = 0;
};


class Resume:Cloneable{
    string name;
    string telephone;
    int age;
    
    public:
        Resume *clone(){
            return new Resume(*this);
        }
        Resume(string name="", string telephone="", int age=0):name(name),telephone(telephone),age(age){};
        void setName(string name){this->name = name;}
        void setTelephone(string telephone){this->telephone = telephone;}
        void setAge(int age){this->age = age;}
        string getName(){return name;}
        string getTelephone(){return telephone;}
        int getAge(){return age;}
        string toString()const{
            return format("Resume(Name = {0} , Tel = {1}, Age = {2})",name,telephone,age);
        }
        friend ostream &operator<<(ostream &os, const Resume &resume){
            os<<resume.toString();
            return os;
        }
};



