//
// Created by Vo Doan Minh Hieu on 12/16/25.
//
#include <SFML/Graphics.hpp>
#include <random>

class Walker {
public:
    Walker(const int width, const int height) : rng(std::random_device{}()) {
        x = width / 2;
        y = height / 2;
    }

    void step() {
        std::uniform_int_distribution<int> dist(0, 3);

        if (const int choice = dist(rng); choice == 0) x++;
        else if (choice == 1) x--;
        else if (choice == 2) y++;
        else y--;
    }

    void show(sf::Image &img) const {
        img.setPixel(sf::Vector2u(x, y), sf::Color::Black);
    }

private:
    int x, y;
    std::mt19937 rng;
};

int main() {
    const int WIDTH = 640;
    const int HEIGHT = 240;

    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Random Walker");
    window.setFramerateLimit(60);

    sf::Image canvas({WIDTH, HEIGHT}, sf::Color::White);

    sf::Texture texture;
    if (!texture.loadFromImage(canvas)) {
        // error
    }
    sf::Sprite sprite(texture);

    Walker walker(WIDTH, HEIGHT);

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        walker.step();
        walker.show(canvas);

        texture.update(canvas);

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
