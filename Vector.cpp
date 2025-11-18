#include "Vector.hpp"
#include <cmath>
#include <iostream>
#include <limits>

Vector::Vector() {}

Vector::Vector(const std::vector<double>& d) : data(d) {}

double Vector::length() const {
    double s = 0;
    for (double x : data) s += x * x;
    return std::sqrt(s);
}

double Vector::minElement() const {
    double mn = std::numeric_limits<double>::max();
    for (double x : data) if (x < mn) mn = x;
    return mn;
}

bool Vector::operator>(const Vector& other) const {
    return this->length() > other.length();
}

double Vector::operator*(const Vector& other) const {
    double sum = 0;
    size_t n = std::min(data.size(), other.data.size());
    for (size_t i = 0; i < n; i++)
        sum += data[i] * other.data[i];
    return sum;
}

void Vector::print() const {
    std::cout << "[ ";
    for (double x : data) std::cout << x << " ";
    std::cout << "]";
}

