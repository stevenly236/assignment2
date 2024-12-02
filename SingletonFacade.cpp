//
// Created by Steven  Ly on 2024-12-01.
//

#include "SingletonFacade.hpp"
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

SingletonFacade* SingletonFacade::instance = nullptr;

SingletonFacade* SingletonFacade::getInstance() {
    if (instance == nullptr) {
        instance = new SingletonFacade();
    }
    return instance;
}

void SingletonFacade::run(int citiesInTour, int populationSize, double mutationRate) {
    vector<City*> cities;

    for (int i = 0; i < citiesInTour; i++) {
        double x = rand() % (Constants::MAP_BOUNDARY + 1);
        double y = rand() % (Constants::MAP_BOUNDARY + 1);
        cities.push_back(new City("City" + to_string(i), x, y));
    }

    Population population(cities, populationSize, Constants::PARENT_POOL_SIZE);
    double baseDistance = population.getBaseDistance();
    cout << "Original elite: Distance: " << fixed
              << setprecision(2) << baseDistance << "\n";

    cout << "(";
    for (const City* city : population.getEliteTour()->getCities()) {
        cout << city->getName() << "->";
    }
    cout << population.getEliteTour()->getCities()[0]->getName() << ")\n";

    cout << "--- STARTING ALGORITHM ---\n";

    int iteration = 0;
    while (iteration < Constants::MAX_ITERATIONS) {
        double oldDistance = population.getEliteTour()->getDistance();
        population.evolve(mutationRate, Constants::NUMBER_OF_PARENTS, Constants::NUMBER_OF_ELITES);
        double newDistance = population.getEliteTour()->getDistance();

        cout << "Iteration: " << iteration << "\n";

        if (newDistance < oldDistance) {
            cout << "NEW ELITE FOUND:\n";
            cout << "Distance: " << fixed
                      << setprecision(2) << newDistance << "\n";
        } else {
            cout << "Elite distance: " << fixed
                      << setprecision(2) << newDistance << "\n";
            cout << "Best non-elite distance: " << fixed
                      << setprecision(2)
                      << population.getTours()[1]->getDistance() << "\n";
        }

        double improvement = baseDistance / newDistance;
        cout << "Improvement over base: " << fixed
                  << setprecision(5) << improvement << "\n";

        if (improvement >= Constants::IMPROVEMENT_FACTOR) {
            break;
        }

        cout << "\n";

        iteration++;
    }

    cout << "--- FINISHED ALGORITHM ---\n";
    cout << "Total iterations: " << iteration << "\n";

    cout << "Original elite:\nDistance: " << fixed
              << setprecision(2) << baseDistance << "\n(";
    Tour* finalTour = population.getEliteTour();
    double finalDistance = finalTour->getDistance();

    for (const City* city : finalTour->getCities()) {
        cout << city->getName() << "->";
    }
    cout << finalTour->getCities()[0]->getName() << ")\n";

    cout << "Best elite:\nDistance: " << fixed
              << setprecision(2) << finalDistance << "\n";

    double finalImprovement = baseDistance / finalDistance;
    if (finalImprovement >= Constants::IMPROVEMENT_FACTOR) {
        cout << "Improvement factor reached!\n";
    } else {
        cout << "Improvement factor not reached.\n";
    }
    cout << "Improvement factor: " << fixed
              << setprecision(5) << finalImprovement << "\n";

    for (City* city : cities) {
        delete city;
    }
}
