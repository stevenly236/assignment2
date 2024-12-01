//
// Created by Steven  Ly on 2024-12-01.
//

#include "Population.hpp"
#include <random>
#include <algorithm>

using namespace std;

Population::Population(const vector<City*>& cities, int populationSize, int parentSize)
    : parentSize(parentSize) {
    for (int i = 0; i < populationSize; i++) {
        tours.push_back(new Tour(cities));
    }
    evaluateFitness();
    eliteTour = new Tour(*tours[0]);
    baseDistance = eliteTour->getDistance();
}

Population::~Population() {
    for (Tour* tour : tours) {
        delete tour;
    }
}

void Population::evaluateFitness() {
    sort(tours.begin(), tours.end(),
        [](const Tour* a, const Tour* b) {
            return a->getFitness() > b->getFitness();
        });
}

Tour* Population::selectParent() {
    vector<Tour*> parentPool;

    for (int i = 0; i < parentSize; i++) {
        int randomIndex = rand() % tours.size();
        parentPool.push_back(tours[randomIndex]);
    }

    return *max_element(parentPool.begin(), parentPool.end(),
        [](const Tour* a, const Tour* b) {
            return a->getFitness() < b->getFitness();
        });
}

Tour* Population::crossover(const vector<Tour*>& parents) {
    int crossoverSection = rand() % parents[0]->getCities().size();
    vector<City*> childCities;

    for (int i = 0; i <= crossoverSection; i++) {
        childCities.push_back(parents[0]->getCities()[i]);
    }

    for (const City* city : parents[1]->getCities()) {
        if (!any_of(childCities.begin(), childCities.end(),
            [city](const City* c) { return c == city; })) {
            childCities.push_back(const_cast<City*>(city));
        }
    }

    return new Tour(childCities);
}

void Population::evolve(double mutationRate, int numberOfParents, int numberOfElites) {
    vector<Tour*> newTours;

    for (int i = 0; i < numberOfElites && i < tours.size(); i++) {
        newTours.push_back(new Tour(*tours[i]));
    }

    while (newTours.size() < tours.size()) {
        vector<Tour*> parents;
        for (int i = 0; i < numberOfParents; i++) {
            parents.push_back(selectParent());
        }
        Tour* child = crossover(parents);
        newTours.push_back(child);
    }

    int toursToMutate = static_cast<int>(tours.size() * ((rand() % 11 + 20) / 100.0));

    for (int i = numberOfElites; i < toursToMutate + numberOfElites && i < newTours.size(); i++) {
        newTours[i]->mutate(mutationRate);
    }

    for (Tour* tour : tours) {
        delete tour;
    }
    tours = newTours;

    evaluateFitness();
    if (tours[0]->getFitness() > eliteTour->getFitness()) {
        Tour* newElite = new Tour(*tours[0]);
        delete eliteTour;
        eliteTour = newElite;
    }
}
