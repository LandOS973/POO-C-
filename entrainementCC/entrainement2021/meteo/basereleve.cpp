#include "basereleve.h"

basereleve::basereleve()
{

}

bool basereleve::ajout(const temperature &t)
{
    for(const auto &T : _temperatures){
        if(datereleve::comparememejour(T.d(),t.d())) return false;
    }
    _temperatures.push_back(t);
    return true;
}

bool basereleve::ajout(const vent &v)
{
    for(const auto &T : _vents){
        if(datereleve::comparememejour(T.d(),v.d())) return false;
    }
    _vents.push_back(v);
    return true;
}

bool basereleve::ajout(const precipitation &p)
{
    for(const auto &T : _precipitations){
        if(datereleve::comparememejour(T.d(),p.d()) && p.prec() == T.prec()) return false;
    }
    _precipitations.push_back(p);
    return true;
}

void basereleve::sortirrecents(std::ostream &os, const datereleve &d)
{
    for(const auto &T : _vents){
        if(datereleve::compareavant(T.d(),d)) T.sortiesurflux(os);
    }
    for(const auto &T : _precipitations){
        if(datereleve::compareavant(T.d(),d)) T.sortiesurflux(os);
    }
    for(const auto &T : _temperatures){
        if(datereleve::compareavant(T.d(),d)) T.sortiesurflux(os);
    }
}

float basereleve::tempmoyenne(const datereleve &d)
{
    int count = 0;
    int total = 0;
    for(const auto &T : _temperatures){
        if(T.d() == d){
            count++;
            total += T.temp();
        }
    }
    return total / count;
}
/*. Écrire une méthode tempsdangereux retournant les datereleve pour lesquels il y a un relevé de
vent, une température inférieure à 2, et des précipitations de neige ou grêle.*/
const std::vector<datereleve> &basereleve::tempsdangereux()
{
    std::vector<datereleve> V;
    for(const auto &T : _temperatures){
        if(T.temp() < 20) V.push_back(T.d());
    }
    for(const auto &T : _precipitations){
        if(T.prec() == type::grele || T.prec() == type::neige) V.push_back(T.d());
    }
    return V;
}
