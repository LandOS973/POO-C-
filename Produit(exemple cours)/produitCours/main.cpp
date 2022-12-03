#include <iostream>
#include "produitperissable.h"
#include "produitculturel.h"
#include "stockptr.h"
#include "stockuniqueptr.h"
#include "stockvectors.h"

int main()
{
    produitculturel P1("manga",100);
    produitperissable P2 ("101010","banane",100);

    // POINTEUR
    std::cout<<"POINTEUR\n";
    stockptr S;
    S.ajouter(P1);
    S.ajouter(P2);
    stockptr S2;
    S2 = S;
    std::cout<<(S2==S)<<"\n";
    std::cout<<S<<"\n";

    // UNIQUE PTR
    std::cout<<"Unique pointeur \n";
    auto p3 = std::make_unique<produitculturel>("manga",100);
    auto p4 = std::make_unique<produitperissable>("1001","banane",100);
    stockuniqueptr S3;
    S3.ajouter(std::move(p3));
    S3.ajouter(std::move(p4));
    stockuniqueptr Stockuniquecopie = S3;
    std::cout<<Stockuniquecopie<<"\n";
    std::cout<<(S3==Stockuniquecopie)<<"\n\n";

    // VECTORS
    std::cout<<"Vector normal\n";
    stockvectors S4;
    S4.ajouter(produitculturel("manga",100));
    S4.ajouter(produitperissable("1001","banane",100));
    std::cout<<S4;
    return 0;
}
