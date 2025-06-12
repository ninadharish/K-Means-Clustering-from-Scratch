#include "point.hpp"

Point::Point(double x_, double y_) {
    x = x_;
    y = y_;
}

double Point::get_x() {
    return x;
}

double Point::get_y() {
    return y;
}

void Point::print() {
    std::cout << "(" << x << ", " << y << ")" << "\n";
}

Point::~Point() { }

std::ostream& operator<<(std::ostream& os, Point& p) {
    return os << "(" << p.get_x() << ", " << p.get_y() << "\n";
}
