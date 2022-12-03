#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::vector<int> V;
    for(std::vector<int>::size_type i(0); i<_produits.size(); ++i){

    }

    // ERASE
    for (std::vector<int>::iterator it = V.begin(); it != V.end();)
    {
        if (conditional)
            it = V.erase(it);
        else
            ++it;
    }

    // ajout
    V.push_back(5);

    //tout supprimer
    V.clear();

    // FIND (include algorithm)
    std::vector<int>::interator i = find(V.begin(), V.end(), elementacherché);
    if (i != V.end()) {
        // found it
    } else {
        // doesn't exist
    }

    // FIND IF (fonction anonyme)
    for (int i = 1; i < V.size(); ++i) {
        auto f = std::find_if(V.begin(),V.end(),[i](auto const &p){
            return (p->id() == i); // exemple de condition
        });
        if(f == V.end()){
            // rien trouvé;
        }else{
            // trouvé !;
        }
    }

    return 0;
}
