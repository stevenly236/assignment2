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
    // Creates initial population of random tours
    Population(const vector<City*>& cities, int populationSize, int parentSize);

    // Population destructor
    ~Population();

    // Sorts tours by fitness value
    void evaluateFitness();

    // Chooses parent tour for crossover
    Tour* selectParent();

    // Creates child tour from parent tours
    Tour* crossover(const vector<Tour*>& parents);

    // Creates next gen of tours
    void evolve(double mutationRate, int numberOfParents, int numberOfElites);

    // Returns initial best tour distance
    double getBaseDistance() const { return baseDistance; }

    // Returns the current best tour
    Tour* getEliteTour() const { return eliteTour; }

    // Returns all tours in population
    const vector<Tour*>& getTours() const { return tours; }
};


#endif //POPULATION_HPP
