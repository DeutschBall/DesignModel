#pragma once
#include <iostream>
#include "auto.hpp"

class AutoBuilder{   
    protected:
    public:
    virtual void buildEngine()=0;
    virtual void buildEnergyContainer()=0;
    virtual void buildDoor()=0;
    virtual Auto* build(){
        buildEngine();
        buildEnergyContainer();
        buildDoor();
        return NULL;
    }
};

///需要装载功能接口
class BuildLoadable{
    public:
    virtual void buildLoader() = 0;
};

class TruckBuilder:public AutoBuilder, BuildLoadable{
    protected:
        Truck* product;
    public:
    void buildDoor(){
        product->addDoors(new Door());
        product->addDoors(new Door());
    }
    void buildLoader(){
        product->addLoader(new Loader(100));
    }
    TruckBuilder(){
    }
    Auto* build(){
        product = new Truck();
        AutoBuilder::build();
        buildLoader();
        return product;
    }
};
class ElectricTruckBuilder:public TruckBuilder{

    void buildEngine(){
        product->addEngines(new ElectricEngine(5));
    }
    void buildEnergyContainer(){
        product->addEnergy(new BatteryPack(50));
    }
};

class FuelTruckBuilder:public TruckBuilder{

    void buildEngine(){
        product->addEngines(new FuelEngine(10));
    }
    void buildEnergyContainer(){
        product->addEnergy(new FuelTank(100));
    }
};