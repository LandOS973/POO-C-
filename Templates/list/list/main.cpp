#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    std::list<int> L;

    // ERASE
    std::list<int>::iterator it;
    for (it = L.begin(); it != L.end(); ++it){
        if(conditional){
            L.erase(it);
            return;
        }
    }

    // Loop Iterator
    std::list<sommet>::const_iterator it;
    for (it = L.begin(); it != L.end(); ++it){

    }

    // ajout
    L.push_back(5);

    //tout supprimer
    L.clear();
    return 0;
}
