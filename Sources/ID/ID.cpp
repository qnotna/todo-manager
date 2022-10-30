#include <ctime>
#include <iostream>

#include "ID.hpp"

ID::ID() {
    this->raw_value = rand() % 100 + 1;
}

ID::~ID() = default;

int ID::get_raw_value() {
    return this->raw_value;
}

void ID::seed() {
    srand(time(NULL));
}