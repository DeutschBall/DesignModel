#pragma once
#include <memory>
#include <vector>
#include <iostream>
// #include "acceptable.hpp"
using namespace std;
class Acceptable;
class AbstractVisitor
{
public:
    
    virtual double visit(shared_ptr<Acceptable> acceptable) = 0;

};
