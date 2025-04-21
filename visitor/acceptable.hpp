#pragma once 
#include <memory>
// #include "visitor.hpp"
using namespace std;
class AbstractVisitor;
class Acceptable
{
public:
    virtual double accept(shared_ptr<AbstractVisitor> visitor) = 0;
};

