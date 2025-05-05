#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include "Player.cpp"
#include "Board.cpp"
#include "Dice.cpp"


class Game {
private:
    std::vector<Player> players;
    Board board;
    Dice dice;
    int currentPlayerIndex;

public:
    Game(const std::vector<std::string>& playerNames) : currentPlayerIndex(0) {
        std::vector<std::string> colors = { "\033[31m", "\033[32m", "\033[34m", "\033[33m" };
        for (size_t i = 0; i < playerNames.size(); ++i) {
            players.emplace_back(playerNames[i], colors[i]);
        }
    }

    void startGame() {
        std::cout << "Игра началась! Набери как можно скорее " << board.getSpacesCount() << " Очков!" << std::endl;
    }

    void playTurn() {
        Player& currentPlayer = players[currentPlayerIndex];
        std::cout << "\n" << currentPlayer.getColor() << currentPlayer.getName() << "'твоя очередь\033[0m" << std::endl;

        int roll = dice.roll();
        std::cout << "Крутанул: " << roll << std::endl;

        currentPlayer.move(roll);

        if (currentPlayer.getPosition() >= board.getSpacesCount()) {
            std::cout << currentPlayer.getColor() << "\n" << currentPlayer.getName() << " Выйграл!\033[0m" << std::endl;
            return;
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    bool isGameOver() const {
        for (const auto& player : players) {
            if (player.getPosition() >= board.getSpacesCount()) {
                return true;
            }
        }
        return false;
    }
};

// test
