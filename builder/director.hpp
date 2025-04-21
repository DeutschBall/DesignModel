#pragma once
#include "builder.hpp"
class AutoDirector{
    AutoBuilder* builder;
    public:
        void setBuilder(AutoBuilder* b){
            builder=b;
        }
        Auto * build(){
            return builder->build();
        }
};