#include <iostream>
#include "uno.hpp"
#include <string>

//Card Class Methods

Card::Card(int acolor, int anumber, std::string aname)
{
    color = acolor;
    number = anumber;
    name = aname;
}

int Card::getColor()
{
    return color;
}
int Card::getNumber()
{
    return number;
}
std::string Card::getName()
{
    return name;
}