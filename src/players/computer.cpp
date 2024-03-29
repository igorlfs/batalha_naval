#include "players/computer.hpp"
#include <iostream>
#include <random>
// https://stackoverflow.com/a/13445752
int randomNumber(int floor, int ceiling) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(floor,
                                                                  ceiling);
    return dist(rng);
}
using namespace Players;
computer::computer() {
    this->initializeGrid();
    this->initializeShips();
    for (int i = 0; i < TOTAL_SHIPS; ++i) {
        this->ships[i]->setDirection(chooseDirection());
        this->ships[i]->setCells(chooseShipPosition(*this->ships[i]));
        this->insertShipInGrid(*this->ships[i]);
    }
}
bool computer::chooseDirection() const { return randomNumber(0, 1); }
pair<uint, uint> computer::chooseShipPosition(const Ships::ship &ship) const {
    pair<uint, uint> position;
    do {
        position = {randomNumber(0, ROWS - 1), randomNumber(0, COLS - 1)};
    } while (this->isOutOfBounds(ship, position) == true ||
             this->isOverlaping(ship, position) == true);
    return position;
}
pair<uint, uint> computer::chooseAttackPosition() {
    pair<uint, uint> attackPosition;
    do {
        attackPosition = {randomNumber(0, ROWS - 1), randomNumber(0, COLS - 1)};
    } while (this->wasAttacked(attackPosition) == true);
    this->alreadyAttacked.insert(attackPosition);
    return attackPosition;
}
