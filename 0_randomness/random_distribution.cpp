//
// Created by Vo Doan Minh Hieu on 12/17/25.
//
#include <sfml/Graphics.hpp>
#include <random>
#include <vector>


int main() {
    const int WIDTH = 640;
    const int HEIGHT = 240;
    const int TOTAL = 20;

    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Random Distribution");
    window.setFramerateLimit(60);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, TOTAL - 1);

    std::vector<int> randomCounts(TOTAL, 0);

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        int index = dist(gen);
        randomCounts[index]++;

        window.clear(sf::Color::White);

        float w = static_cast<float>(WIDTH) / TOTAL;

        for (int x = 0; x < TOTAL; x++) {
            sf::RectangleShape rect;
            rect.setSize({w - 1, static_cast<float>(randomCounts[x])});
            rect.setPosition(sf::Vector2f(x * w, HEIGHT - randomCounts[x]));
            rect.setFillColor(sf::Color::Black);
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(2);

            window.draw(rect);
        }

        window.display();
    }

    return 0;
}