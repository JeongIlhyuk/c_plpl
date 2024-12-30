#ifndef __POINT_H_
#define __POINT_H_

class Point{
    int x,y;

public:
    Point(int xpos,int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};
#endif