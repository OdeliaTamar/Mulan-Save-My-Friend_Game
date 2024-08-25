#pragma once

#include "BaseObject.h"
#include"Utilities.h"
#include <iostream>
#include <typeinfo>
class Level;
// Sample struct for exception throwing
struct UnknownCollision : public std::runtime_error
{

    UnknownCollision(BaseObject& a, BaseObject& b)
        : std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
    {
    }


};
void processCollision(BaseObject& object1, BaseObject& object2,Level& l);
