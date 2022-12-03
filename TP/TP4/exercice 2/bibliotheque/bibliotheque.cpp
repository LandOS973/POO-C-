#include "bibliotheque.h"

bibliotheque::bibliotheque()
{

}

bibliotheque::~bibliotheque()
{
    for(auto p : _documents){
        delete p;
    }
}

bibliotheque::bibliotheque(const bibliotheque &S)
{
    for(const auto &p : S._documents){
        _documents.push_back(p->clone());
    }
}

bibliotheque &bibliotheque::operator=(const bibliotheque &s)
{
    if(this != &s){
        for(auto p: _documents){
            delete p;
        }
        _documents.clear();
        for(auto const &p : s._documents){
            _documents.push_back(p->clone());
        }
    }
    return *this;
}

// pareil de operator= (question 6)
bibliotheque &bibliotheque::copie(const bibliotheque &s)
{
    if(this != &s){
        for(auto p: _documents){
            delete p;
        }
        _documents.clear();
        for(auto const &p : s._documents){
            _documents.push_back(p->clone());
        }
    }
    return *this;
}

void bibliotheque::ajouter(const document &p)
{
    _documents.push_back(p.clone());
}

int bibliotheque::typeDeVideo(const support &S) const
{
    int count = 0;
    for(auto const & i : _documents){
        auto vid = dynamic_cast<video const *>(i);
        if(vid != nullptr){
            if(vid->getTypeSupport() == S) count++;
        }
    }
    return count;
}

const document &bibliotheque::acces(int i) const
{
    return *(_documents.at(i));
}

std::ostream & operator<<(std::ostream &os,bibliotheque const &S){
    for(auto const &p: S._documents){
        p->sortie(os);
        os<<"\n";
    }
    return os;
}


