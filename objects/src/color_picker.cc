#include "color_picker.h"
#include "controller.h"
#include <cmath>

namespace {
bool CircleContains(sf::Vector2<float> const &center, float r, float x,
                    float y) {
  auto res = Controller::CalcEuclideanDistance(center, {x, y});
  return Controller::FpvAreEqual(res, static_cast<double>(r)) || res < r;
}
} // namespace

Color ColorPicker::pick() {
  auto const w_title = "Color Picker";
  auto const w_width = 500;
  auto const w_height = 500;
  sf::ContextSettings w_settings;
  w_settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(w_width, w_height), w_title,
                          sf::Style::Default, w_settings);

  auto radius = 150.0f;
  auto point_count = 360;

  auto x_offset = (w_width - radius * 2) / 2;
  auto y_offset = (w_height - radius * 2) / 2;

  auto center = sf::Vector2<float>(x_offset + radius - 50, y_offset + radius);

  sf::VertexArray pallete(sf::TriangleFan, point_count);
  pallete[0].position = center;

  sf::CircleShape pallete_border(radius, point_count);
  pallete_border.setFillColor(sf::Color::Transparent);
  pallete_border.setOutlineColor(sf::Color::Black);
  pallete_border.setOutlineThickness(2);
  pallete_border.setPosition(center.x - radius, center.y - radius);

  double h = 0.0;
  double s = 0.0;
  double v = 100.0;
  for (auto i = 1; i <= point_count; ++i) {
    auto [r, g, b] = HsvToRgb(i, 100, v);
    float x = center.x + std::cos(Controller::DegreeToRadian(i)) * radius;
    float y = center.y + std::sin(Controller::DegreeToRadian(i)) * radius;
    auto color = sf::Color(r, g, b);
    sf::Vertex v({x, y}, color);
    pallete[i] = std::move(v);
  }
  pallete.append(pallete[1]);

  auto pallete_picker_r = 3;
  auto pallete_picker_bt = 2;
  auto pallete_picker_size = (pallete_picker_r << 1) + (pallete_picker_bt << 1);
  sf::CircleShape pallete_picker(pallete_picker_r);
  pallete_picker.setFillColor(sf::Color::Transparent);
  pallete_picker.setOutlineColor(sf::Color::Black);
  pallete_picker.setOutlineThickness(pallete_picker_bt);
  pallete_picker.setPosition(center.x - pallete_picker_r - pallete_picker_bt,
                             center.y - pallete_picker_r - pallete_picker_bt);

  auto offset = 50;
  auto picked_color_r = 25;

  auto slider_w = 50;
  auto slider_h = int(radius * 2) - offset - picked_color_r * 2;
  sf::VertexArray slider(sf::Quads, 4);
  auto p1 = sf::Vector2<float>(center.x + radius + offset, center.y - radius);
  auto p2 = sf::Vector2<float>(p1.x + slider_w, p1.y);
  auto p3 = sf::Vector2<float>(p1.x, p1.y + slider_h);
  auto p4 = sf::Vector2<float>(p3.x + slider_w, p3.y);
  slider[0] = std::move(p1);
  slider[0].color = sf::Color::White;
  slider[1] = std::move(p2);
  slider[1].color = sf::Color::White;
  slider[2] = std::move(p4);
  slider[2].color = sf::Color::Black;
  slider[3] = std::move(p3);
  slider[3].color = sf::Color::Black;

  auto sp_w = 20;
  auto sp_half_h = 10;
  auto sp_bt = 1;
  sf::ConvexShape slider_picker(3);
  slider_picker.setPoint(0, p2);
  slider_picker.setPoint(1, {p2.x + sp_w, p2.y - sp_half_h});
  slider_picker.setPoint(2, {p2.x + sp_w, p2.y + sp_half_h});
  slider_picker.setFillColor(sf::Color::White);
  slider_picker.setOutlineColor(sf::Color::Black);
  slider_picker.setOutlineThickness(sp_bt);
  auto move = [&slider_picker](float d_x, float d_y) {
    for (auto i = 0; i < slider_picker.getPointCount(); i++) {
      auto p = slider_picker.getPoint(i);
      p.x += d_x;
      p.y += d_y;
      slider_picker.setPoint(i, p);
    }
  };

  sf::RectangleShape slider_border(
      {static_cast<float>(slider_w), static_cast<float>(slider_h)});
  slider_border.setPosition(p1);
  slider_border.setFillColor(sf::Color::Transparent);
  auto bw_spectre = 150;
  slider_border.setOutlineColor(sf::Color(bw_spectre, bw_spectre, bw_spectre));
  slider_border.setOutlineThickness(2);

  sf::CircleShape picked_color(picked_color_r);
  picked_color.setPosition(p3.x, p3.y + offset);
  picked_color.setFillColor(sf::Color::White);
  picked_color.setOutlineColor(sf::Color::Black);
  picked_color.setOutlineThickness(2);

  bool mouse_hold = false;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::MouseButtonPressed: {
        mouse_hold = true;
      } break;
      case sf::Event::MouseButtonReleased:
        mouse_hold = false;
        break;
      }
    }

    if (mouse_hold) {

      auto [x, y] = sf::Mouse::getPosition(window);
      if (slider.getBounds().contains(x, y)) {
        y -= p1.y;
        // y -= slider_border.getPosition().y;
        if (y <= 0) {
          // slider_picker.move(0, p2.y - slider_picker.getPoint(0).y);
          move(0, p2.y - slider_picker.getPoint(0).y);
          v = 100;
        } else if (y >= slider_h) {
          // slider_picker.move(0, p3.y - slider_picker.getPoint(0).y);
          move(0, p3.y - slider_picker.getPoint(0).y);
          v = 0;
        } else {
          // slider_picker.move(0, p1.y + y - slider_picker.getPoint(0).y);
          move(0, p1.y + y - slider_picker.getPoint(0).y);
          v = 100 - static_cast<float>(y) / slider_h * 100;
        }

        auto d_x = x - center.x;
        auto d_y = y - center.y;

        auto [r, g, b] = HsvToRgb(h, s, v);
        auto curr = sf::Color(r, g, b);

        slider_picker.setFillColor(curr);
        picked_color.setFillColor(curr);

      } else if (CircleContains(center, radius, x, y)) {
        pallete_picker.setPosition(x - pallete_picker_r - pallete_picker_bt,
                                   y - pallete_picker_r - pallete_picker_bt);
        auto d_x = x - center.x;
        auto d_y = y - center.y;
        h = Controller::RadianToDegree(Controller::CalcAngle(d_x, d_y));

        {
          auto p1 = sf::Vector2<int>(x, y);
          auto p2 = sf::Vector2<int>(static_cast<int>(center.x),
                                     static_cast<int>(center.y));
          s = Controller::CalcEuclideanDistance(p1, p2);
        }

        s = s / radius * 100;

        auto [r, g, b] = HsvToRgb(h, s, v);
        auto [r_max, g_max, b_max] = HsvToRgb(h, s, 100.0);

        auto curr = sf::Color(r, g, b);
        picked_color.setFillColor(curr);
        slider_picker.setFillColor(curr);

        auto brightest_color = sf::Color(r_max, g_max, b_max);
        slider[0].color = brightest_color;
        slider[1].color = brightest_color;
      }
    }
    window.clear(sf::Color(255, 255, 255));

    window.draw(pallete);
    window.draw(pallete_border);
    window.draw(pallete_picker);
    window.draw(slider);
    window.draw(slider_border);
    window.draw(slider_picker);
    window.draw(picked_color);
    window.display();
  }

  return HsvToRgb(h, s, v);
}

Color ColorPicker::HsvToRgb(double h, double s, double v) {
  auto h_i = (int)h / 60 % 6;

  double tmp = (100 - s) * v;
  double v_min = tmp == 0 ? 0 : tmp / 100;

  double a = (v - v_min) * (Controller::fpvMod(h, 60)) / 60;
  double v_inc = v_min + a;

  double v_dec = v - a;

  uint8_t r, g, b;
  switch (h_i) {
  case 0:
    r = v * 255 / 100;
    g = v_inc * 255 / 100;
    b = v_min * 255 / 100;
    break;
  case 1:
    r = v_dec * 255 / 100;
    g = v * 255 / 100;
    b = v_min * 255 / 100;
    break;
  case 2:
    r = v_min * 255 / 100;
    g = v * 255 / 100;
    b = v_inc * 255 / 100;
    break;
  case 3:
    r = v_min * 255 / 100;
    g = v_dec * 255 / 100;
    b = v * 255 / 100;
    break;
  case 4:
    r = v_inc * 255 / 100;
    g = v_min * 255 / 100;
    b = v * 255 / 100;
    break;
  case 5:
    r = v * 255 / 100;
    g = v_min * 255 / 100;
    b = v_dec * 255 / 100;
    break;
  }
  return {r, g, b};
}