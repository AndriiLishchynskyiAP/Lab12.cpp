#include <iostream>
#include <vector>
#include <algorithm>
#include "Vector.hpp"

int main() {
    int n;
    std::cout << "Кількість векторів: ";
    std::cin >> n;

    std::vector<Vector> arr;

    for (int i = 0; i < n; i++) {
        int k;
        std::cout << "\nКількість елементів у векторі " << i + 1 << ": ";
        std::cin >> k;

        std::vector<double> temp(k);
        std::cout << "Введіть елементи: ";
        for (int j = 0; j < k; j++) std::cin >> temp[j];

        arr.emplace_back(temp);
    }

    std::sort(arr.begin(), arr.end(),
        [](const Vector& a, const Vector& b) {
            return a.minElement() > b.minElement();
        }
    );

    std::cout << "\nВектори після сортування:\n";
    for (auto& v : arr) {
        v.print();
        std::cout << "  min element = " << v.minElement() << "\n";
    }

    Vector maxV = arr.front();
    Vector minV = arr.back();

    double result = maxV * minV;

    std::cout << "\nСкалярний добуток:\n";
    maxV.print();
    std::cout << "  і  ";
    minV.print();
    std::cout << "\nРезультат = " << result << "\n";

    return 0;
}
