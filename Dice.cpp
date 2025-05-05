#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

class Dice {
private:
    int sides;
    std::mt19937 gen;
public:
    Dice(int s = 6) : sides(s) {
        gen.seed(std::chrono::system_clock::now().time_since_epoch().count());
    }

    int roll() {
        std::uniform_int_distribution<> dist(1, sides);
        return dist(gen);
    }
};