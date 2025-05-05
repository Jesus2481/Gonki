#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <thread>
#include "Game.cpp"

int main() 
{
    setlocale(LC_ALL, "ru");
    std::vector<std::string> players;
    int playerCount;

    std::cout << "������� ����� ������� (2-4): ";
    std::cin >> playerCount;

    for (int i = 0; i < playerCount; ++i) {
        std::string name;
        std::cout << "������� ������ " << i + 1 << " ���: ";
        std::cin >> name;
        players.push_back(name);
    }

    Game game(players);
    game.startGame();

    while (!game.isGameOver()) {
        game.playTurn();
    }

    return 0;
}