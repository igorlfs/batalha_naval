#include "computer.hpp"
#include "human.hpp"
#include <iostream>
void printTrackingGrid(const players::player &tracked,
                       const players::player &traking);
void printPrimaryGrid(const players::player &defender,
                      const players::player &attacker);
int main() {
  // TODO:
  //
  // Change ship's state when attacking
  // Was target hit?
  //
  // Win condition
  // Consider using unsigned for pairs
  // Correct input
  // Colors
  players::human person;
  players::computer cpu;
  players::computer cpu2;
  while (1) {
    printTrackingGrid(cpu, person);
    person.attack();
    cpu.attack();
    printPrimaryGrid(person, cpu);
  }
  return 0;
}
void printTrackingGrid(const players::player &tracked,
                       const players::player &traking) {
  tracked.printHeader();
  char col = '0';
  for (int i = 0; i < players::ROWS; ++i) {
    tracked.printSeparator();
    std::cout << ' ' << col;
    std::cout << " │ ";
    for (int j = 0; j < players::COLS; ++j) {
      if (traking.wasAnAttempt({i, j})) {
        std::cout << 'x';
      } else {
        std::cout << 'o';
      }
      if (j != players::COLS - 1) {
        std::cout << " │ ";
      }
    }
    ++col;
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // Stop execution to analize stuff
  std::cin >> col;
}
void printPrimaryGrid(const players::player &defender,
                      const players::player &attacker) {
  defender.printHeader();
  char col = '0';
  for (int i = 0; i < players::ROWS; ++i) {
    defender.printSeparator();
    std::cout << ' ' << col;
    std::cout << " │ ";
    for (int j = 0; j < players::COLS; ++j) {
      if (attacker.wasAnAttempt({i, j})) {
        std::cout << 'x';
      } else {
        std::cout << defender.grid[i][j];
      }
      if (j != players::COLS - 1) {
        std::cout << " │ ";
      }
    }
    ++col;
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
