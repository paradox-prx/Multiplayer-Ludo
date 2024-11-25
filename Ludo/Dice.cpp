// Dice.cpp
#include "Dice.h"
#include <cstdlib>
#include <ctime>

Dice::Dice() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

int Dice::roll() {
    return (std::rand() % 6) + 1;
}
