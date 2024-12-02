//
// Created by Steven  Ly on 2024-11-30.
//

#ifndef CITY_HPP
#define CITY_HPP

#pragma once
#include <string>

using namespace std;

class City {
private:
    string name;
    double x;
    double y;

public:
    City(const std::string& name, double x, double y);
    string getName() const { return name; }
    double getX() const { return x; }
    double getY() const { return y; }
};

#endif //CITY_HPP
