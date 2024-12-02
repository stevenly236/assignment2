// Steven Ly A01383591
// Created by Steven  Ly on 2024-11-30.
//


#include <iostream>
#include "SingletonFacade.hpp"

using namespace std;

int main() {
    int citiesInTour;
    int populationSize;
    double mutationRate;

    cout << "Enter the number of cities: ";
    cin >> citiesInTour;

    cout << "Enter the population size: ";
    cin >> populationSize;

    cout << "Enter the mutation rate: ";
    cin >> mutationRate;

    if (citiesInTour <= 0) {
        cerr << "Invalid number of cities. Using default value of 32." << endl;
        citiesInTour = 32;
    }

    if (populationSize <= 0) {
        cerr << "Invalid population size. Using default value of 32." << endl;
        populationSize = 32;
    }

    if (mutationRate <= 0 || mutationRate > 1) {
        cerr << "Invalid mutation rate. Using default value of 0.15." << endl;
        mutationRate = 0.15;
    }

    SingletonFacade* facade = SingletonFacade::getInstance();
    facade->run(citiesInTour, populationSize, mutationRate);
    delete facade;
    return 0;
}
