#include <iostream>
#include "volunteer.hpp"

int main(){
    VolunteerFactory * factory = new StudentFactory();  //此工厂创建的志愿者均为学生志愿者


    Volunteer *volunteer = factory->createVolunteer();
    volunteer->doVolunteerWork();

    delete factory;
    delete volunteer;

    factory = new SoldierFactory();                     //此工厂创建的志愿者均为士兵志愿者
    volunteer = factory->createVolunteer();
    volunteer->doVolunteerWork();

    delete factory;
    delete volunteer;


    return 0;
}