#pragma once
#include <iostream>
#include <vector>
#include <format>
#include <string>
using std::string;
using std::format;
using std::vector;

/// @brief 能源容器类, 不管是邮箱还是电池等等, 都是一种容器
class EnergyContainer{  
    private:
        /// @brief 本容器的能源容量
        double capacity;
        /// @brief 本容器剩余能量
        double remain;
    public:
        EnergyContainer(double c=1):capacity(c),remain(c){};
        void addEnergy(double adder=0){
            remain+=adder;
        }
        void useEnergy(double loser=0){
            remain-=loser;
        }
        double getRemain(){
            return remain;
        }
        double getCapacity(){  
            return capacity;
        }
        virtual string toString(){
            return format("(capacity = {0}, remain = {1})",capacity, remain);
        }
};
/// @brief 邮箱类
class FuelTank:public EnergyContainer{
    public:
        FuelTank(double c=1):EnergyContainer(c){};
        string toString(){
            return format("FuelTank({0})",EnergyContainer::toString());
        }
};
/// @brief 电池类
class BatteryPack:public EnergyContainer{
    public:
        BatteryPack(double c=1):EnergyContainer(c){};
        string toString(){
            return format("BatteryPack({0})",EnergyContainer::toString());
        }
};




///门基类, 如果有更高级的门, 则可以继承该类
class Door{
    public:
        virtual string toString(){
            return "Door";
        }
};




/// @brief 引擎类,引擎只关心消耗多少能源, 他不知道邮箱电池的存在. 
class Engine{
    private:
    double consumption; //能源单位功耗
    public:
        Engine(double c=1):consumption(c){};
        double getConsumtion(){
            return consumption;
        }
        virtual string toString(){
            return format("(consumption = {0})",consumption);
        }
};
class ElectricEngine:public Engine{
    public:
        ElectricEngine(double c=1):Engine(c){};
        string toString(){
            return format("ElectricEngine({0})",Engine::toString());
        }
};
class FuelEngine:public Engine{
    public:
        FuelEngine(double c=1):Engine(c){};
        string toString(){
            return format("FuelEngine({0})",Engine::toString());    
        }
};



///所有机动车的基类, 其子类按照用途分类,分成小轿车或者卡车, 而不是能源
///本基类中包含所有车辆必须的物件
class Auto{
    private:
        /// @brief 由于车辆可以有多个门,因此用vector
        vector<Door*> doors;
        /// @brief 由于车辆可以有多个邮箱或电池,因此用vector
        vector<EnergyContainer*> containers;
        /// @brief 由于车辆可以有多个发动机, 因此
        vector<Engine*> engines;

    public:
        //以下的接口提供给用户使用

        /// @brief 车辆补充能源
        /// @return 返回实际需要补充的能源数量
        double charge(){   
            double total_capacity=0;
            double total_remain=0;
            double current_capacity = 0;
            double current_remain = 0;
            for(auto container:containers){
                current_capacity = container->getCapacity();
                current_remain = container->getRemain();
                total_capacity+=current_capacity;
                total_remain+=current_remain;
                container->addEnergy(current_capacity-current_remain);
            }
            return total_capacity-total_remain;
        }

        /// @brief 车辆行驶
        /// @param distance 期望行驶距离
        /// @return 返回能源耗尽前的实际行驶距离
        double run(double distance){ 
            double per_consumption=0;   //单位距离能耗
            double total_consumption=0; //distance距离下的总能耗
            double want;                //还需要多少能源才能满足
            double current_remain;
            double real_distance=0;
            for(auto engine:engines){
                per_consumption+=engine->getConsumtion();
            }
            total_consumption = per_consumption*distance;
            want = total_consumption;
            
            for(auto container:containers){
                current_remain = container->getRemain();
                if(current_remain>=want){
                    container->useEnergy(want);
                    want = 0;
                    break;
                }
                else{
                    want-=current_remain;
                    container->useEnergy(current_remain);
                }
            }
            real_distance = want==0?distance:(total_consumption-want)/per_consumption;
            return real_distance;
        }
        virtual string toString(){
            string ans;
            string temp;
            for(auto door:doors){
                temp+='\t'+door->toString()+'\n';
            }
            ans+=format("Doors(\n{0})\n",temp);
            temp.clear();
    
            for(auto container:containers){
                temp+='\t'+container->toString()+'\n';
            }
            ans+=format("EnergyContainers(\n{0})\n",temp);
            temp.clear();
    
            for(auto engine:engines){
                temp+='\t'+engine->toString()+'\n';
            }
            ans+=format("Engines(\n{0})\n",temp);
            return ans;
        }
        ///以上的接口提供给用户使用


        ///以下的接口提供给builder使用
    public:
    virtual ~Auto(){
        for(auto door:doors){
            delete door;
        }
        for(auto container:containers){
            delete container;
        }
        for(auto engine:engines){
            delete engine;
        }
    }
    virtual void addDoors(Door* door){
        doors.push_back(door);
    }
    virtual void addEnergy(EnergyContainer *container){
        containers.push_back(container);
    }
    virtual void addEngines(Engine* engine){
        engines.push_back(engine);
    }

};


class Loader{
    private:
        int capacity;
        int used;
    public:
        Loader(int c=1):capacity(c),used(0){};
        void addLoad(int adder=0){
            used+=adder;
        }
        void loseLoad(int loser=0){
            used-=loser;
        }
        int getRemain(){
            return capacity-used;
        }
        virtual string toString(){
            return format("Loader(capacity = {0}, used = {1})",capacity,used);
        }
};



class Truck:public Auto{
    private:
        vector<Loader*>loaders;
    public:
        ~Truck(){
            for(auto loader:loaders){
                delete loader;
            }
        }
        void load(int loader_index,int adder){
            loaders[loader_index]->addLoad(adder);
        }
        void lose(int loader_index,int loser){
            loaders[loader_index]->loseLoad(loser);
        }
        void addLoader(Loader* loader){
            loaders.push_back(loader);
        }
        string toString(){
            string ans;
            string temp;
            for(auto loader:loaders){
                temp+='\t'+loader->toString()+'\n';
            }
            ans+=format("Loaders(\n{0})\n",temp);
            temp.clear();
            ans+=Auto::toString();
            ans = format("Truck(\n{0})\n",ans);
            return ans;
        }
};


class Car:public Auto{
    private:
        int population;
        int capacity;
    public:
        void onBoard(int adder){
            population+=adder;
        }
        void offBoard(int loser){
            population-=loser;
        }
        int getPopulation(){
            return population;
        }
};
