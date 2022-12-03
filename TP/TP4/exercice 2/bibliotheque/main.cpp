#include <iostream>
#include "video.h"
#include "livres.h"
#include "periodique.h"
#include "bibliotheque.h"

using namespace std;

int main()
{
    livres L(false,60,"yo","yo");
    periodique P(5,40,"yo","yo");
    video V(support::BluRay,"yo","yo");
    bibliotheque B;
    B.ajouter(V);
    B.ajouter(video(support::DVD,"yo","yo"));
    std::cout<<B<<"\n";
    std::cout<<B.typeDeVideo(support::DVD);
    return 0;
}
