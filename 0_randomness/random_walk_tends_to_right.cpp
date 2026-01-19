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

    void step(const int width, const int height) {
        std::uniform_real_distribution<double> dist(0, 1);

        if (const double choice = dist(rng); choice < 0.4) x++;
        else if (choice < 0.6) x--;
        else if (choice < 0.8) y++;
        else y--;

        x = std::clamp(x, 0, width - 1);
        y = std::clamp(y, 0, height - 1);
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

        walker.step(WIDTH, HEIGHT);
        walker.show(canvas);

        texture.update(canvas);

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
