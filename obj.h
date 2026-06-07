//
// Created by velia on 08.06.2026.
//

#ifndef MYSFMLGAME_OBJ_H
#define MYSFMLGAME_OBJ_H

#include <string>
#include <SFML/Graphics.hpp>
// SFML/Graphics — библиотека для рисования (прямоугольники, спрайты)

class Obstacle {
    // Переменные класса (состояние препятствия):
    sf::RectangleShape _shape;  // Форма: прямоугольник
    float _speed;                // Скорость движения (пикселей/сек)
    bool _isActive;              // Активно ли ещё (можно удалить)

public:
    Obstacle();                          // Создать препятствие
    void setPosition(float x, float y);  // Поставить в точку (x, y)
    void update(float dt);                 // Обновить ( move на dt)
    void draw(sf::RenderTarget &target, sf::RenderStates states) const; // Рисовать
    bool isOutside() const;                // Проверить: ушло за экран?
    sf::Vector2f getPosition() const;      // Получить позицию
    sf::Rect<float> getRect() const;       // Получить прямоугольник (для коллизий)
};

#endif //MYSFMLGAME_OBJ_H
