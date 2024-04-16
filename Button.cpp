#include "Button.hpp"

Button::Button(std::string caption, sf::Font &font, unsigned int fontSize, int x, int y) {
    this->caption = sf::Text(caption, font, fontSize);
    this->caption.setPosition(x, y);
    this->rectangle = sf::FloatRect(this->caption.getGlobalBounds());
}

sf::Text &Button::getCaption() { return caption; }

sf::FloatRect &Button::getRectangle() { return rectangle; }

void Button::setFontColor(sf::Color const &c) {
    caption.setFillColor(c);
}

void Button::setStyle(sf::Uint32 const &style) {
    caption.setStyle(style);
}

bool Button::contains(sf::Vector2<int> const &point) {
    sf::Vector2f p(point.x, point.y);
    return rectangle.contains(p);
}

void Button::update(sf::RenderWindow &w) {
    setStyle(sf::Text::Regular);
    setFontColor(sf::Color::Red);
    if (contains(sf::Mouse::getPosition(w))) {
        setStyle(sf::Text::Underlined);
        setFontColor(sf::Color::Blue);
    }
    w.draw(caption);
}

Button::~Button() {
}