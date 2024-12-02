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
    // Creates new tour from city list
    Tour(const vector<City*>& cities);

    // Copy Constructor
    Tour(const Tour& other);

    // Randomly shuffles cities in tour
    void shuffleCities();

    // Calculates total distance of tour
    double calculateDistance();

    // Returns tour's fitness score value
    double getFitness() const { return fitness; }

    // Sets new fitness score value
    void setFitness(double f) { fitness = f; }

    // Returns total distance of tour
    double getDistance() const { return distance; }

    // Returns vector containing tour cities
    const vector<City*>& getCities() const { return cities; }

    // Checks if city exists in tour
    bool containsCity(const City* city) const;

    // Adds new city to tour
    void addCity(City* city);

    // Swaps cities next to each other randomly (via mutateRate)
    void mutate(double mutationRate);
};


#endif //TOUR_HPP
