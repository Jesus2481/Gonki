#include <iostream>
#include <vector>
#include <string>

class Board {
private:
    int spaces;
public:
    Board(int s = 30) : spaces(s) {}

    int getSpacesCount() const { return spaces; }
};