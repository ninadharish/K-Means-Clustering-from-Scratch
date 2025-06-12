#ifndef point_hpp
#define point_hpp

#include<iostream>


class Point {
    public:
        double x;
        double y;
        Point(double x_, double y_) ;
        double get_x();
        double get_y();
        void print();
        friend std::ostream operator<<(std::ostream os, Point p);
        ~Point();
};



#endif