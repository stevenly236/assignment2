//
// Created by Steven  Ly on 2024-11-30.
//


#include "SingletonFacade.hpp"

int main() {
    SingletonFacade* facade = SingletonFacade::getInstance();
    facade->run();
    delete facade;
    return 0;
}