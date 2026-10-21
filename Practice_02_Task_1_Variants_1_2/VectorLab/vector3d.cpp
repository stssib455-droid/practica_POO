#include "vector3d.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
Vector3D::Vector3D(): x(0),y(0),z(0) {}
Vector3D::Vector3D(double a,double b,double c):x(a),y(b),z(c) {
    if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(z))
        throw std::invalid_argument("Vector coordinates must be finite");
}
double Vector3D::length() const {
    // hypot avoids overflow of intermediate x*x for large finite coordinates.
    return std::hypot(x,y,z);
}
void Vector3D::print() const {std::cout << *this << '\n';}
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x+other.x,y+other.y,z+other.z);
}
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x-other.x,y-other.y,z-other.z);
}
Vector3D Vector3D::operator*(double factor) const {
    if (!std::isfinite(factor)) throw std::invalid_argument("Factor must be finite");
    return Vector3D(x*factor,y*factor,z*factor);
}
bool Vector3D::operator==(const Vector3D& other) const {
    constexpr double epsilon=1e-6;
    return std::abs(x-other.x)<epsilon && std::abs(y-other.y)<epsilon
        && std::abs(z-other.z)<epsilon;
}
std::ostream& operator<<(std::ostream& out,const Vector3D& v) {
    return out << '(' << v.x << ", " << v.y << ", " << v.z << ')';
}
