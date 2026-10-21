#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <iosfwd>
class Vector3D {
private:
    double x, y, z;
public:
    Vector3D();
    Vector3D(double x_value, double y_value, double z_value);
    double get_x() const { return x; }
    double get_y() const { return y; }
    double get_z() const { return z; }
    double length() const;
    void print() const;
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(double factor) const;
    bool operator==(const Vector3D& other) const;
    friend std::ostream& operator<<(std::ostream& output, const Vector3D& vector);
};
#endif
