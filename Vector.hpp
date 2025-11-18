#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

class Vector {
private:
    std::vector<double> data;

public:
    Vector();
    Vector(const std::vector<double>& d);

    double length() const;
    double minElement() const;

    bool operator>(const Vector& other) const;
    double operator*(const Vector& other) const;

    void print() const;
};

#endif
