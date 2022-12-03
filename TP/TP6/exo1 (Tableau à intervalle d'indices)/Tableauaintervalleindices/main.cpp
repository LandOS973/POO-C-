#include <iostream>
#include "tableau.h"

using namespace std;

int main()
{
    arrayint A(0,10);
    try{
        A.set(5,5);
        std::cout<<A[15];
    }catch(const exceptionarrayint &e){
        std::cout<<e.what();
    }
    return 0;
}
