#ifndef POINT_H
#define POINT_H
#include <iostream>


class point
{
    int _x;
    int _y;
public:
    point();
    point(int x, int y);
    point(point const & P);
    ~point();
    int const & getX() const;
    int const & getY() const;
    void setX(int x);
    void setY(int y);
    void translation(point const & P);
    void afficherPoint() const;
    static double distance(point const & P1, point const & P2);
};

#endif // POINT_H
