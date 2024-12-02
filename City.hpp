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
    // Constructs city with name and location
    City(const std::string& name, double x, double y);

    // Returns the city's name
    string getName() const { return name; }

    // Returns the city's x coordinate
    double getX() const { return x; }

    // Returns the city's y coordinate
    double getY() const { return y; }
};

#endif //CITY_HPP
