//
// Created by Steven  Ly on 2024-12-01.
//

#ifndef POPULATION_HPP
#define POPULATION_HPP
#pragma once
#include <vector>
#include "Tour.hpp"

using namespace std;

class Population {
private:
    vector<Tour*> tours;
    Tour* eliteTour;
    double baseDistance;
    const int parentSize;

public:
    Population(const vector<City*>& cities, int populationSize, int parentSize);
    ~Population();
    void evaluateFitness();
    Tour* selectParent();
    Tour* crossover(const vector<Tour*>& parents);
    void evolve(double mutationRate, int numberOfParents, int numberOfElites);
    double getBaseDistance() const { return baseDistance; }
    Tour* getEliteTour() const { return eliteTour; }
    const vector<Tour*>& getTours() const { return tours; }
};


#endif //POPULATION_HPP
