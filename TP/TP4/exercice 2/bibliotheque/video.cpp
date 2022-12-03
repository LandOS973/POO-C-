#include "video.h"

support video::getTypeSupport() const
{
    return typeSupport;
}

video::video(support typeSupport, const std::string &nomAuteur, const std::string &titre) : document(nomAuteur, titre),
    typeSupport(typeSupport)
{}

float video::cout() const
{
    return 70;
}

bool video::empruntable() const
{
    return true;
}

std::string video::type() const
{
    return "video";
}

void video::sortie(std::ostream &os) const
{
    document::sortie(os);
    std::string s;
    switch (typeSupport) {
    case support::BluRay:
        s = "BluRay";
        break;
    case support::DVD:
        s = "DVD";
        break;
    case support::BluRay3D:
        s = "BluRay3D";
        break;
    default:
        break;
    }
    os<<"type de support "<<s;
}

document *video::clone() const
{
    return new video(*this);
}


