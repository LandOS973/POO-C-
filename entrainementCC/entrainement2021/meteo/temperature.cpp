#include "temperature.h"
#include <math.h>
#include <iostream>

int temperature::temp() const
{
    return _temp;
}

temperature::temperature(int temp, const datereleve &d) : releve(d),
    _temp(temp)
{}

std::string temperature::typereleve() const
{
    return "temperature";
}

std::string temperature::tostring() const
{
    return releve::tostring() + std::to_string(_temp/10) + "°C";
}

releve *temperature::clone() const
{
    return new temperature(*this);
}
