//
// Created by velia on 08.06.2026.
//

#include "obj.h"

Obstacle::Obstacle() {
    // Создаём прямоугольник 50×50 пикселей
    _shape.setSize({50, 50});

    // Красный цвет (255, 0, 0) = RGB
    _shape.setFillColor(sf::Color(255, 0, 0));

    // Скорость: 200 пикселей/сек влево
    _speed = 200;

    // Активно по умолчанию
    _isActive = true;
}

void Obstacle::setPosition(float x, float y) {
    // Ставим прямоугольник в координаты (x, y)
    _shape.setPosition({x, y});
}

void Obstacle::update(float dt) {
    // Двигаем влево: скорость × время
    // _speed = 200, dt = 0.016 → move на 3.2 пикселя
    _shape.move({-_speed * dt, 0});
    // - = влево, 0 = не двигаем по Y
}

void Obstacle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // Рисую прямоугольник на target (окно игры)
    target.draw(_shape, states);
}

bool Obstacle::isOutside() const {
    // Если левый край прямоугольника < -100
    // Ушло за левую границу экрана
    return _shape.getPosition().x < -100;
}

sf::Vector2f Obstacle::getPosition() const {
    // Возвращаем текущую позицию (x, y)
    return _shape.getPosition();
}

sf::Rect<float> Obstacle::getRect() const {
    // Возвращаем прямоугольник для проверки столкновений
    return _shape.getGlobalBounds();
}