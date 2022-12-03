#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class test{
public:
    test(int a);
    int x;
};

test::test(int a):x(a){}

int main()
{
    std::vector<int> V;
    for(std::vector<int>::size_type i(0); i<V.size(); ++i){

    }

    // ERASE
    for (std::vector<int>::iterator it = V.begin(); it != V.end();)
    {
        if (*it == 4)
            it = V.erase(it);
        else
            ++it;
    }

    //tout supprimer
    V.clear();

    // ajout
    V.push_back(5);

    // FIND (include algorithm)
    std::vector<int>::iterator i = find(V.begin(), V.end(), 5);
    if (i != V.end()) {
        std::cout<<"trouvé!";
    } else {
        std::cout<<"pas trouvé!";
    }



    // FIND IF (fonction anonyme)
    std::vector<test> v;
    v.push_back(test(1));
    int valRecherché = 1;
    auto f = std::find_if(v.begin(),v.end(),[valRecherché](auto const &p){
        return (p.x == valRecherché);
    });
    if(f == v.end()){
        std::cout<<"pas trouvé!";
    }else{
        std::cout<<"trouvé!";
    }

    return 0;
}
