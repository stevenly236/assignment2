//
// Created by Steven  Ly on 2024-11-30.
//

#ifndef TOUR_HPP
#define TOUR_HPP

#pragma once
#include <vector>
#include "City.hpp"

using namespace std;

class Tour {
private:
    vector<City*> cities;
    double fitness;
    double distance;

public:
    Tour(const vector<City*>& cities);
    Tour(const Tour& other);
    void shuffleCities();
    double calculateDistance();
    double getFitness() const { return fitness; }
    void setFitness(double f) { fitness = f; }
    double getDistance() const { return distance; }
    const vector<City*>& getCities() const { return cities; }
    bool containsCity(const City* city) const;
    void addCity(City* city);
    void mutate(double mutationRate);
};


#endif //TOUR_HPP
