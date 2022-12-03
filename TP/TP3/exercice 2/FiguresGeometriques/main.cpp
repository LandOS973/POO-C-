#include <iostream>
#include "segment.h"
#include "texte.h"
#include "rectangle.h"
#include "triangle.h"
#include "point.h"

using namespace std;

int main()
{
    rectangle R(1,2,3,1,1,2,2,3,3,4,4);
    std::cout<<R.estCarre();
    return 0;
}
