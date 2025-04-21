#pragma once
#include <iostream>


class Volunteer{
    public:
        virtual void doVolunteerWork()=0;
};

class Student:public Volunteer{
    public:
        void doVolunteerWork(){
            std::cout << "Student Volunteer work" << std::endl;
        }
};

class Soldier:public Volunteer{
    public:
        void doVolunteerWork(){
            std::cout << "Soldier Volunteer work" << std::endl;
        }
};

class VolunteerFactory{
    public:
        virtual Volunteer* createVolunteer() = 0;
};
class StudentFactory:public VolunteerFactory{
    public:
        Volunteer* createVolunteer(){
            return new Student();
        }
};
class SoldierFactory:public VolunteerFactory{
    public:
        Volunteer* createVolunteer(){
            return new Soldier();
        }
};