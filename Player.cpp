#include <iostream>
#include <vector>
#include <string>

class Player {
private:
    std::string name;
    int position;
    std::string color;
public:
    Player(const std::string& n, const std::string& c)
        : name(n), position(0), color(c) {
    }

    void move(int spaces) {
        position += spaces;
        std::cout << color << name << "\033[0m перемещается в исходное положение " << position << std::endl;
    }

    int getPosition() const { return position; }
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
};