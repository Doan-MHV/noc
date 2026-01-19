//
// Created by Vo Doan Minh Hieu on 12/18/25.
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
        std::uniform_real_distribution<double> x_step(-2.75, 3);
        std::uniform_real_distribution<double> y_step(-2.75, 3);

        x += x_step(rng);
        y += y_step(rng);
    }

    void show(sf::Image &img) const {
        img.setPixel(sf::Vector2u(static_cast<int>(x), static_cast<int>(y)), sf::Color::Black);
    }

private:
    double x, y;
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