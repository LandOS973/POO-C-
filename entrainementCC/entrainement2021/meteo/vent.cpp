#include "vent.h"


vent::vent(const direction &direction, const datereleve &d) : releve(d),
    _direction(direction)
{}

std::string vent::typereleve() const
{
    return "vent";
}

std::string vent::tostring() const
{
    std::string s;
    switch (_direction) {
    case direction::nord: s = "nord";break;
    case direction::sud: s = "sud";break;
    case direction::est: s = "est";break;
    case direction::ouest: s = "ouest";break;
    default:break;
    }
    return releve::tostring() + " " + s;
}

releve *vent::clone() const
{
    return new vent(*this);
}
