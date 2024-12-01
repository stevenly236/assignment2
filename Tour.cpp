//
// Created by Steven  Ly on 2024-11-30.
//

#include "Tour.hpp"
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

Tour::Tour(const vector<City*>& cities) : cities(cities), fitness(0), distance(0) {
    shuffleCities();
    calculateDistance();
}

Tour::Tour(const Tour& other)
    : cities(other.cities), fitness(other.fitness), distance(other.distance) {}

void Tour::shuffleCities() {
    random_device rd;
    default_random_engine generator(rd());
    shuffle(cities.begin(), cities.end(), generator);
}

double Tour::calculateDistance() {
    distance = 0;
    for (size_t i = 0; i < cities.size(); i++) {
        City* from = cities[i];
        City* to = cities[(i + 1) % cities.size()];

        double dx = from->getX() - to->getX();
        double dy = from->getY() - to->getY();
        distance += sqrt(dx * dx + dy * dy);
    }
    fitness = 1.0 / distance;
    return distance;
}

bool Tour::containsCity(const City* city) const {
    return find(cities.begin(), cities.end(), city) != cities.end();
}

void Tour::addCity(City* city) {
    cities.push_back(city);
}

void Tour::mutate(double mutationRate) {
    for (size_t i = 0; i < cities.size() - 1; i++) {
        if ((rand() % 100) / 100.0 < mutationRate) {
            swap(cities[i], cities[i + 1]);
        }
    }
    calculateDistance();
}
