//
// Created by Steven  Ly on 2024-12-01.
//

#ifndef SINGLETONFACADE_HPP
#define SINGLETONFACADE_HPP
#pragma once
#include "Population.hpp"

class SingletonFacade {
private:
    static SingletonFacade* instance;
    SingletonFacade() = default;

    struct Constants {
        static const int DEFAULT_CITIES_IN_TOUR = 32;
        static const int DEFAULT_POPULATION_SIZE = 32;
        static const int SHUFFLES = 64;
        static const int MAX_ITERATIONS = 1000;
        static const int MAP_BOUNDARY = 1000;
        static const int PARENT_POOL_SIZE = 5;
        static const int NUMBER_OF_PARENTS = 2;
        static const int NUMBER_OF_ELITES = 1;
        static constexpr double DEFAULT_MUTATION_RATE = 0.15;
        static constexpr double IMPROVEMENT_FACTOR = 2.4;
    };

public:
    static SingletonFacade* getInstance();
    void run(int citiesInTour = Constants::DEFAULT_CITIES_IN_TOUR,
             int populationSize = Constants::DEFAULT_POPULATION_SIZE,
             double mutationRate = Constants::DEFAULT_MUTATION_RATE);
};

#endif //SINGLETONFACADE_HPP
