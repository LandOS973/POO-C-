#ifndef POSITION_H
#define POSITION_H
#include <iostream>


class position
{
private:
    unsigned int _x;
    unsigned int _y;
public:
    position(unsigned int x, unsigned int y);
    unsigned int x() const;
    void setX(unsigned int newX);
    unsigned int y() const;
    void setY(unsigned int newY);
    bool operator==(const position &p) const;
    bool operator!=(const position &p) const;
    std::string tostring() const;
    friend std::ostream & operator<<(std::ostream &os,position const &S);
};

#endif // POSITION_H
