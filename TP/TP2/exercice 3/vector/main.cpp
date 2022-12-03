#include <iostream>
#include <vector>

using namespace std;

int maxParIteration(vector<int> const & V){
    int max = V.front();
    for (auto i(V.begin()); i != V.end(); ++i) {
        max < *i ? max = *i : max;
    }
    return max;
}

int maxParBoucle(vector<int> const & V){
    int max = V.front();
    for (auto i : V) {
        max < i ? max = i : max;
    }
    return max;
}

int maxParIndice(vector<int> const & V){
    int max = V.front();
    for (std::vector<int>::size_type i(0); i<V.size(); ++i)
        max < V[i] ? max = V[i] : max;
    return max;
}

int main()
{
    // j'avais ecrit les fonction de saisi mais oneDrive DE MERDE a tout perdu donc nique ça mere je l'ai refais pas et allez tous vous faire enculé chez Microsoft
    vector<int> V = {1,23,55,47};
    cout<<maxParIndice(V);

    return 0;
}
