#include "Capybara.h"

#include "Capybara.h"

Capybara::Capybara() {
    _sprite.setTexture(_texture);
    _sprite.setScale({3.0, 3.0});
    _speedY = 0.0;
    _isJumping = false;
}

void Capybara::setTexture(std::string path) {
    _texture.loadFromFile(path);
}

void Capybara::setPosition(float x, float y) {
    _sprite.setPosition({x, y});
}

void Capybara::update(float dt) {
    // Гравитация
    _speedY += 500.0 * dt;
    _sprite.move({0.0, _speedY * dt});

    // Высота спрайта
    float spriteVisota = _sprite.getTexture()->getSize().y * _sprite.getScale().y;

    // Позиция "ног" (нижняя точка спрайта)
    float nogiY = _sprite.getPosition().y + spriteVisota;

    float groundLevel = 500.0;

    if (nogiY > groundLevel) {
        float newY = groundLevel - spriteVisota;
        _sprite.setPosition({_sprite.getPosition().x, newY});
        _speedY = 0.0;
        _isJumping = false;
    }
}

void Capybara::jump() {
    if (!_isJumping) {
        _speedY = -300.0;
        _isJumping = true;
    }
}

void Capybara::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

float Capybara::getY() const {
    return _sprite.getPosition().y;
}