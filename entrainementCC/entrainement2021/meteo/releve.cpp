#include "releve.h"

const datereleve &releve::d() const
{
    return _d;
}

releve::releve(const datereleve &d) : _d(d)
{}

std::string releve::tostring() const
{
    return _d.tostring() + " " + typereleve() + " ";
}

void releve::sortiesurflux(std::ostream &os) const
{
    os<<tostring();
}
