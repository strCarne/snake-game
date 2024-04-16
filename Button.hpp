#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
  Button(std::string caption, sf::Font &font, unsigned int fontSize, int x,
         int y);

  sf::Text &getCaption();
  sf::FloatRect &getRectangle();

  void setFontColor(sf::Color const &c);

  void setStyle(sf::Uint32 const &style);

  bool contains(sf::Vector2<int> const &point);

  virtual void update(sf::RenderWindow &w);

  virtual ~Button();

protected:
  sf::Text caption;
  sf::FloatRect rectangle;
};

#endif