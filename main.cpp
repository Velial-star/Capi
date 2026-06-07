#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Capybara.h"

int main() {
    sf::RenderWindow window({800, 600}, "Capibara Jump");

    Capybara::setTexture("C:/Users/velia/CLionProjects/untitled/assets/capibara.png");
    Capybara capibara;
    capibara.setPosition(100, 400);

    // Создаём пол (серая полоска)
    sf::RectangleShape ground;
    ground.setSize({800, 20});  // Ширина 800, высота 20
    ground.setFillColor(sf::Color(128, 128, 128));  // Серый цвет
    ground.setPosition({0, 500});  // Пол на координате y = 500

    sf::Clock clock;




    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            capibara.jump();
        }
        capibara.update(dt);

        window.clear();
        window.draw(ground);
        window.draw(capibara);
        window.display();
    }

    return 0;
}