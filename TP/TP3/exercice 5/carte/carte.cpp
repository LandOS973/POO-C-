#include "carte.h"

carte::carte(int x, int y):_taille(x,y){}

bool carte::peutAjouter(const element & E) const {
    return (E.getPosition().get_x() + E.getTaille().get_hauteur() <= _taille.get_hauteur()) && (E.getPosition().get_y() + E.getTaille().get_largeur() <= _taille.get_largeur());
}

void carte::ajout(const obstable &O)
{
    if(peutAjouter(O)) _obstables.push_back(O);

}

void carte::ajout(const personnage &P)
{
    if(peutAjouter(P)) _personnages.push_back(P);
}

void carte::ajout(const objetramassable &O)
{
    if(peutAjouter(O)) _objets.push_back(O);
}

void carte::afficher() const
{
    std::cout<<"Carte {\n Taille = hauteur:"<<_taille.get_hauteur() <<" - largeur:"<<_taille.get_largeur()<<std::endl;
    for (const auto &i : _obstables)
        std::cout<<"   Obstable "<<i.toString()<<std::endl;
    for (const auto &i : _personnages)
         std::cout<<"   Personnage "<<i.toString()<<std::endl;
    for (const auto &i : _objets)
        std::cout<<"   Objet "<<i.toString()<<std::endl;
    std::cout<<'}'<<std::endl;
}

bool carte::intersection(const element &A, const element &B) const
{
    auto positionAX = A.getPosition().get_x();
    auto positionBX = B.getPosition().get_x();
    auto positionAY = A.getPosition().get_y();
    auto positionBY = B.getPosition().get_y();
    auto rangeAX = positionAX + A.getTaille().get_hauteur();
    auto rangeBX = positionBX + B.getTaille().get_hauteur();
    auto rangeAY = positionAY + A.getTaille().get_largeur();
    auto rangeBY = positionBY + B.getTaille().get_largeur();
    if(positionAX >= positionBX && positionAX <= rangeBX && positionAY >= positionBY && positionAY <= rangeBY) return true;
    if(rangeAX >= positionBX && rangeAX <= rangeBX && rangeAY >= positionBY && rangeAY <= rangeBY) return true;
    return false;
}

void carte::majListeDesPerso(const personnage &P){
    for (auto &&i : _personnages)
        if(i.get_nom() == P.get_nom()){
            i.setPostion(P.getPosition().get_x(),P.getPosition().get_y());
            i.setPoints(P.points());
            break;
        }
}

bool carte::deplacer(personnage &P, int x, int y)
{
    personnage P2(P.getTaille().get_largeur(),P.getTaille().get_largeur(),P.getPosition().get_x()+x,P.getPosition().get_y()+y,"test");
    if(!peutAjouter(P2)) return false;
    for(const auto &i:_obstables) {
        if(intersection(P2,i)) return false;
    }
    P.setPostion(P.getPosition().get_x() + x,P.getPosition().get_y() + y);
    majListeDesPerso(P);
    return true;
}

void carte::ramasserObj(personnage &P)
{
    for(std::list<objetramassable>::iterator it = _objets.begin (); it != _objets.end (); ++it)
        if (intersection(P,*it))
        {
            P.ramasserObjet(*it);
            it = _objets.erase(it);
        }
    majListeDesPerso(P);
}

