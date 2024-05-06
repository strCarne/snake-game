#include <SFML/Graphics.hpp>
#include <cstddef>
#include <iostream>
#include <objects>
#include <string>

#include "SFML/UI/CheckBox.hpp"
#include "SFML/UI/ComponentEvent.hpp"
#include "SFML/UI/ComponentObserver.hpp"
#include "SFML/UI/Format/LongFormat.hpp"
#include "SFML/UI/Format/UnsignedLongFormat.hpp"
#include "SFML/UI/FormattedTextField.hpp"
#include "SFML/UI/Label.hpp"
#include "SFML/UI/TextField.hpp"
#include "game.h"
#include "game_field.h"
#include "include/color_picker.h"
#include "include/display_object.h"
#include "include/menu2.h"
#include "include/menu_item.h"
#include "include/menu_item2.h"
#include "include/object_factory.h"
#include "include/object_params.h"
#include "include/rectangle.h"
#include "include/text.h"

Game::Game(std::string const w_name, int w_width, int w_height,
           int w_border_thickness, int fps_limit)
    : w_name_(w_name), w_width_(w_width), w_height_(w_height),
      w_border_thickness_(w_border_thickness), fps_limit_(fps_limit) {}

void Game::Run() const {

  // CONFIG START

  sf::ContextSettings settings;
  settings.antialiasingLevel = kAntialiasingLevel;

  sf::RenderWindow window(sf::VideoMode(w_width_, w_height_), w_name_,
                          sf::Style::Default, settings);

  window.setFramerateLimit(fps_limit_);

  sf::RectangleShape w_border(
      {static_cast<float>(w_width_), static_cast<float>(w_height_)});
  w_border.setFillColor(sf::Color::White);

  // CONFIG END

  GameField game_field(0, 0, 0 + w_border_thickness_, 0 + w_border_thickness_,
                       w_width_ - (w_border_thickness_ << 1),
                       w_height_ - (w_border_thickness_ << 1), 25, 0xFF, 0xFF,
                       0xFF, 0x24, 0x23, 0x24);

  std::string font_path = kResourcesPath / kFontsPath / kDefaultFontPath;

  ObjectFactory factory;
  ObjectParams params;
  params.x_ap_ = game_field.x1_client_;
  params.y_ap_ = game_field.y1_client_;
  params.x1_ = 10;
  params.y1_ = 10;
  params.x2_ = 60;
  params.y2_ = 40;
  params.border_thickness_ = 1;
  params.r_fill_ = 0;
  params.g_fill_ = 0;
  params.b_fill_ = 255;
  params.type = ObjectParams::kRectangle;
  params.text = new Text("TEXT", font_path, 14);
  params.d_x = 175;
  params.d_y = 0;
  // Default callback is defined right before <Add> button in debug menu's
  // initialization, so it can capture the most possible things required in its
  // clojure.

  Menu2 menu;
  MenuItem2 *selector = nullptr;

  Menu2 debug_menu;
  MenuItem2 *dbg_selector = nullptr;
  bool debug_is_on = false;

  auto padding = 10;
  auto dbg_item_w = 120;
  auto dbg_item_h = 40;

  auto dbg_p1_x =
      game_field.x2_client_ - dbg_item_w - game_field.x_ap_ - padding;
  auto dbg_p1_y = game_field.y1_client_ - game_field.y_ap_ + padding;

  auto dbg_font_size = 16;

  bool callback_info_clicked = false;

  // DBG::EDIT START
  ObjectParams old_params;
  bool edit_is_on = false;
  MenuItem2 edit_btn(
      new Rectangle(game_field.x_ap_, game_field.y_ap_, dbg_p1_x, dbg_p1_y,
                    dbg_item_w, dbg_item_h, 2, 131, 240, 253),
      new Text("Edit", font_path, dbg_font_size),
      [&selector, &params, &factory, &edit_is_on,
       &old_params](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            std::cout << item->FullName() << ": ";

            edit_is_on ^= true;
            item->focused_ = edit_is_on;
            item->active_ = edit_is_on;

            if (edit_is_on) {
              std::cout << "entered in the edit mode.\n";
              if (selector != nullptr) {
                old_params = params;
                params = ObjectParams(selector->base_.get());
                params.d_x = old_params.d_x;
                params.d_y = old_params.d_y;
                params.type = ObjectParams::DefineType(selector->base_.get());
                params.text = old_params.text;
              }
            } else {
              if (selector != nullptr) {
                selector->base_.reset(factory.create(params, false));
                auto t = params.text->Clone();
                selector->text_.reset(t);
                // params = old_params;
                // params.d_x = old_params.d_x;
                // params.d_y = old_params.d_y;
              }
              std::cout << "left the edit mode.\n";
            }
          }
        } break;
        }
      },
      MenuItem2::kLeft);

  sf::Font ui_font;
  ui_font.loadFromFile(font_path);
  auto ui_font_size = 14;

  bool ui_positioned = false;

  sf::Texture checkboxImg;
  checkboxImg.loadFromFile("resources/checkbox.png");
  sf::Texture checkboxSelImg;
  checkboxSelImg.loadFromFile("resources/checkbox_selected.png");
  sf::ui::CheckBox checkbox_use_delta(checkboxImg, checkboxSelImg);
  checkbox_use_delta.setFont(ui_font);
  checkbox_use_delta.setText("Use delta");
  checkbox_use_delta.setFontColor(sf::Color::Black);
  checkbox_use_delta.setFontSize(ui_font_size);

  int inline_padding = 10;

  sf::Texture buttonImg;
  buttonImg.loadFromFile("resources/rsz_rsz_button.png");

  sf::Texture buttonFocImg;
  buttonFocImg.loadFromFile("resources/rsz_1rsz_button_focused.png");

  // EDIT_D BEGIN
  sf::ui::Label label_d_x(ui_font, "d_x: ");
  label_d_x.setFontColor(sf::Color::Black);
  label_d_x.setFontSize(ui_font_size);

  sf::ui::FormattedTextField tf_d_x(buttonImg, buttonFocImg, ui_font,
                                    new sf::ui::LongFormat,
                                    std::to_string(params.d_x));
  tf_d_x.setFontSize(ui_font_size);
  tf_d_x.setFontColor(sf::Color::Black);
  tf_d_x.setMaxLength(14);

  sf::ui::Label label_d_y(ui_font, "d_y: ");
  label_d_y.setFontColor(sf::Color::Black);
  label_d_y.setFontSize(ui_font_size);

  sf::ui::FormattedTextField tf_d_y(buttonImg, buttonFocImg, ui_font,
                                    new sf::ui::LongFormat,
                                    std::to_string(params.d_y));

  tf_d_y.setFontSize(ui_font_size);
  tf_d_y.setFontColor(sf::Color::Black);
  tf_d_y.setMaxLength(14);

  struct : public sf::ui::ComponentObserver {
    sf::ui::TextField *tf;
    int *param;
    void onComponentEvent(const sf::ui::ComponentEvent &event) override {
      switch (event.type) {
      case sf::ui::ComponentEvent::FocusLost: {
        *param = std::stoi((*tf).getText().toAnsiString());
      } break;
      }
    }
  } tf_d_x_handler, tf_d_y_handler;

  tf_d_x_handler.tf = &tf_d_x;
  tf_d_x_handler.param = &params.d_x;
  tf_d_x.addObserver(&tf_d_x_handler);

  tf_d_y_handler.tf = &tf_d_y;
  tf_d_y_handler.param = &params.d_y;
  tf_d_y.addObserver(&tf_d_y_handler);

  auto edit_d = new MenuItem2(
      new Rectangle(
          0, 0, 0, 0,
          buttonImg.getSize().x + label_d_x.getSize().x + inline_padding * 3,
          label_d_x.getSize().y + tf_d_x.getSize().y + inline_padding * 3, 2,
          131, 240, 253),
      new Text("", font_path, dbg_font_size),
      [&label_d_x, &tf_d_x, &label_d_y,
       &tf_d_y](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        label_d_x.updateEvent(e);
        tf_d_x.updateEvent(e);
        label_d_y.updateEvent(e);
        tf_d_y.updateEvent(e);
      });
  edit_btn.submenu_->Add(edit_d);
  // EDIT_D END

  // EDIT_TYPE BEGIN
  auto edit_type_w = dbg_item_w << 1;

  bool edit_type_picked = false;
  auto edit_type = new MenuItem2(
      new Rectangle(0, 0, 0, 0, edit_type_w, dbg_item_h, 2, 131, 240, 253),
      new Text(ObjectParams::TypeToString(params.type), font_path,
               dbg_font_size),
      [&edit_type_picked](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            edit_type_picked ^= true;
            item->focused_ = edit_type_picked;
            item->active_ = edit_type_picked;
          }
        } break;
        }
      },
      MenuItem2::kLeft);

  auto pick_circle = new MenuItem2(
      new Rectangle(0, 0, 0, 0, edit_type_w, dbg_item_h, 2, 131, 240, 253),
      new Text(ObjectParams::TypeToString(ObjectParams::kCircle), font_path,
               dbg_font_size),
      [&edit_type, &edit_type_picked,
       &params](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            params.type = ObjectParams::kCircle;
            edit_type_picked = false;
            edit_type->text_->text_ =
                ObjectParams::TypeToString(ObjectParams::kCircle);
            edit_type->focused_ = edit_type_picked;
            edit_type->active_ = edit_type_picked;
          }
        } break;
        }
      });
  edit_type->submenu_->Add(pick_circle);

  auto pick_ellipse = new MenuItem2(
      new Rectangle(0, 0, 0, 0, edit_type_w, dbg_item_h, 2, 131, 240, 253),
      new Text(ObjectParams::TypeToString(ObjectParams::kEllipse), font_path,
               dbg_font_size),
      [&edit_type, &edit_type_picked,
       &params](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            params.type = ObjectParams::kEllipse;
            edit_type_picked = false;
            edit_type->text_->text_ =
                ObjectParams::TypeToString(ObjectParams::kEllipse);
            edit_type->focused_ = edit_type_picked;
            edit_type->active_ = edit_type_picked;
          }
        } break;
        }
      });
  edit_type->submenu_->Add(pick_ellipse);

  auto pick_line = new MenuItem2(
      new Rectangle(0, 0, 0, 0, edit_type_w, dbg_item_h, 2, 131, 240, 253),
      new Text(ObjectParams::TypeToString(ObjectParams::kLine), font_path,
               dbg_font_size),
      [&edit_type, &edit_type_picked,
       &params](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            params.type = ObjectParams::kLine;
            edit_type_picked = false;
            edit_type->text_->text_ =
                ObjectParams::TypeToString(ObjectParams::kLine);
            edit_type->focused_ = edit_type_picked;
            edit_type->active_ = edit_type_picked;
          }
        } break;
        }
      });
  edit_type->submenu_->Add(pick_line);

  auto pick_rectangle = new MenuItem2(
      new Rectangle(0, 0, 0, 0, edit_type_w, dbg_item_h, 2, 131, 240, 253),
      new Text(ObjectParams::TypeToString(ObjectParams::kRectangle), font_path,
               dbg_font_size),
      [&edit_type, &edit_type_picked,
       &params](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            params.type = ObjectParams::kRectangle;
            edit_type_picked = false;
            edit_type->text_->text_ =
                ObjectParams::TypeToString(ObjectParams::kRectangle);
            edit_type->focused_ = edit_type_picked;
            edit_type->active_ = edit_type_picked;
          }
        } break;
        }
      });
  edit_type->submenu_->Add(pick_rectangle);

  auto pick_triangle = new MenuItem2(
      new Rectangle(0, 0, 0, 0, edit_type_w, dbg_item_h, 2, 131, 240, 253),
      new Text(ObjectParams::TypeToString(ObjectParams::kTriangle), font_path,
               dbg_font_size),
      [&edit_type, &edit_type_picked,
       &params](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            params.type = ObjectParams::kTriangle;
            edit_type_picked = false;
            edit_type->text_->text_ =
                ObjectParams::TypeToString(ObjectParams::kTriangle);
            edit_type->focused_ = edit_type_picked;
            edit_type->active_ = edit_type_picked;
          }
        } break;
        }
      });
  edit_type->submenu_->Add(pick_triangle);

  edit_btn.submenu_->Add(edit_type);
  // EDIT_TYPE END

  // EDIT_X_Y BEGIN
  sf::ui::Label label_x1(ui_font, "x1: ");
  label_x1.setFontColor(sf::Color::Black);
  label_x1.setFontSize(ui_font_size);

  sf::ui::FormattedTextField tf_x1(buttonImg, buttonFocImg, ui_font,
                                   new sf::ui::LongFormat,
                                   std::to_string(params.x1_));
  tf_x1.setFontSize(ui_font_size);
  tf_x1.setFontColor(sf::Color::Black);
  tf_x1.setMaxLength(14);

  sf::ui::Label label_y1(ui_font, "y1: ");
  label_y1.setFontColor(sf::Color::Black);
  label_y1.setFontSize(ui_font_size);

  sf::ui::FormattedTextField tf_y1(buttonImg, buttonFocImg, ui_font,
                                   new sf::ui::LongFormat,
                                   std::to_string(params.y1_));

  tf_y1.setFontSize(ui_font_size);
  tf_y1.setFontColor(sf::Color::Black);
  tf_y1.setMaxLength(14);

  struct : public sf::ui::ComponentObserver {
    sf::ui::TextField *tf;
    int *param;
    int *depending_param;
    void onComponentEvent(const sf::ui::ComponentEvent &event) override {
      switch (event.type) {
      case sf::ui::ComponentEvent::FocusLost: {
        auto size = (*depending_param) - (*param);
        *param = std::stoi((*tf).getText().toAnsiString());
        *depending_param = (*param) + size;
      } break;
      }
    }
  } tf_x1_handler, tf_y1_handler;

  tf_x1_handler.tf = &tf_x1;
  tf_x1_handler.param = &params.x1_;
  tf_x1_handler.depending_param = &params.x2_;
  tf_x1.addObserver(&tf_x1_handler);

  tf_y1_handler.tf = &tf_y1;
  tf_y1_handler.param = &params.y1_;
  tf_y1_handler.depending_param = &params.y2_;
  tf_y1.addObserver(&tf_y1_handler);

  auto edit_x1_y1 = new MenuItem2(
      new Rectangle(
          0, 0, 0, 0,
          buttonImg.getSize().x + label_x1.getSize().x + inline_padding * 3,
          label_x1.getSize().y + tf_x1.getSize().y + inline_padding * 3, 2, 131,
          240, 253),
      new Text("", font_path, dbg_font_size),
      [&label_x1, &tf_x1, &label_y1,
       &tf_y1](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        label_x1.updateEvent(e);
        tf_x1.updateEvent(e);
        label_y1.updateEvent(e);
        tf_y1.updateEvent(e);
      });
  edit_btn.submenu_->Add(edit_x1_y1);
  // EDIT_X_Y END

  // EDIT_W_H BEGIN
  sf::ui::Label label_w(ui_font, "w: ");
  label_w.setFontColor(sf::Color::Black);
  label_w.setFontSize(ui_font_size);

  sf::ui::FormattedTextField tf_w(buttonImg, buttonFocImg, ui_font,
                                  new sf::ui::UnsignedLongFormat,
                                  std::to_string(params.x2_ - params.x1_));

  tf_w.setFontSize(ui_font_size);
  tf_w.setFontColor(sf::Color::Black);
  tf_w.setMaxLength(14);

  sf::ui::Label label_h(ui_font, "h: ");
  label_h.setFontColor(sf::Color::Black);
  label_h.setFontSize(ui_font_size);

  sf::ui::FormattedTextField tf_h(buttonImg, buttonFocImg, ui_font,
                                  new sf::ui::UnsignedLongFormat,
                                  std::to_string(params.y2_ - params.y1_));

  tf_h.setFontSize(ui_font_size);
  tf_h.setFontColor(sf::Color::Black);
  tf_h.setMaxLength(14);

  struct : public sf::ui::ComponentObserver {
    sf::ui::TextField *tf;
    int *param;
    int *influencing_param;
    void onComponentEvent(const sf::ui::ComponentEvent &event) override {
      switch (event.type) {
      case sf::ui::ComponentEvent::FocusLost: {
        int size = std::stoi((*tf).getText().toAnsiString());
        *param = *influencing_param + size;
      } break;
      }
    }
  } tf_w_handler, tf_h_handler;

  tf_w_handler.tf = &tf_w;
  tf_w_handler.influencing_param = &params.x1_;
  tf_w_handler.param = &params.x2_;
  tf_w.addObserver(&tf_w_handler);

  tf_h_handler.tf = &tf_h;
  tf_h_handler.influencing_param = &params.y1_;
  tf_h_handler.param = &params.y2_;
  tf_h.addObserver(&tf_h_handler);

  auto edit_w_h = new MenuItem2(
      new Rectangle(
          0, 0, 0, 0,
          buttonImg.getSize().x + label_w.getSize().x + inline_padding * 3,
          label_x1.getSize().y + tf_w.getSize().y + inline_padding * 3, 2, 131,
          240, 253),
      new Text("", font_path, dbg_font_size),
      [&label_w, &tf_w, &label_h, &tf_h](MenuItem2 *item, sf::RenderWindow &w,
                                         sf::Event &e) {
        label_w.updateEvent(e);
        tf_w.updateEvent(e);
        label_h.updateEvent(e);
        tf_h.updateEvent(e);
      });
  edit_btn.submenu_->Add(edit_w_h);
  // EDIT_W_H END

  // EDIT_BT START
  sf::ui::Label label_bt(ui_font, "bt: ");
  label_bt.setFontColor(sf::Color::Black);
  label_bt.setFontSize(ui_font_size);

  sf::ui::FormattedTextField tf_bt(buttonImg, buttonFocImg, ui_font,
                                   new sf::ui::UnsignedLongFormat,
                                   std::to_string(params.border_thickness_));

  tf_bt.setFontSize(ui_font_size);
  tf_bt.setFontColor(sf::Color::Black);
  tf_bt.setMaxLength(14);

  struct : public sf::ui::ComponentObserver {
    sf::ui::TextField *tf;
    int *param;
    void onComponentEvent(const sf::ui::ComponentEvent &event) override {
      switch (event.type) {
      case sf::ui::ComponentEvent::FocusLost: {
        *param = std::stoi((*tf).getText().toAnsiString());
      } break;
      }
    }
  } tf_bt_handler;

  tf_bt_handler.tf = &tf_bt;
  tf_bt_handler.param = &params.border_thickness_;
  tf_bt.addObserver(&tf_bt_handler);

  auto edit_bt = new MenuItem2(
      new Rectangle(
          0, 0, 0, 0,
          buttonImg.getSize().x + label_w.getSize().x + inline_padding * 3,
          label_x1.getSize().y + tf_w.getSize().y + inline_padding * 3, 2, 131,
          240, 253),
      new Text("", font_path, dbg_font_size),
      [&label_bt, &tf_bt](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        label_bt.updateEvent(e);
        tf_bt.updateEvent(e);
      });
  edit_btn.submenu_->Add(edit_bt);
  // EDIT_BT END

  // EDIT_FILL START
  auto edit_fill = new MenuItem2(
      new Rectangle(0, 0, 0, 0, dbg_item_w, dbg_item_h, 2, 131, 240, 253),
      new Text("Fill", font_path, dbg_font_size),
      [&params](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            ColorPicker picker;
            auto [r, g, b] = picker.pick();
            params.r_fill_ = r;
            params.g_fill_ = g;
            params.b_fill_ = b;
            item->base_->r_fill_ = r;
            item->base_->g_fill_ = g;
            item->base_->b_fill_ = b;
          }
        } break;
        }
      });
  edit_btn.submenu_->Add(edit_fill);
  // EDIT_FILL END

  // EDIT_STROKE START
  auto edit_stroke = new MenuItem2(
      new Rectangle(0, 0, 0, 0, dbg_item_w, dbg_item_h, 2, 131, 240, 253),
      new Text("Stroke", font_path, dbg_font_size),
      [&params](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            ColorPicker picker;
            auto [r, g, b] = picker.pick();
            params.r_stroke_ = r;
            params.g_stroke_ = g;
            params.b_stroke_ = b;
            item->base_->r_fill_ = r;
            item->base_->g_fill_ = g;
            item->base_->b_fill_ = b;
          }
        } break;
        }
      });
  edit_btn.submenu_->Add(edit_stroke);
  // EDIT_STROKE END

  // EDIT_TEXT BEGIN
  sf::ui::Label label_text(ui_font, "text: ");
  label_text.setFontColor(sf::Color::Black);
  label_text.setFontSize(ui_font_size);

  sf::ui::TextField tf_text(buttonImg, buttonFocImg, ui_font,
                            params.text->text_);

  tf_text.setFontSize(ui_font_size);
  tf_text.setFontColor(sf::Color::Black);
  tf_text.setMaxLength(14);

  struct : public sf::ui::ComponentObserver {
    sf::ui::TextField *tf;
    std::string *param;
    void onComponentEvent(const sf::ui::ComponentEvent &event) override {
      switch (event.type) {
      case sf::ui::ComponentEvent::FocusLost: {
        *param = (*tf).getText().toAnsiString();
      } break;
      }
    }
  } tf_text_handler;

  tf_text_handler.tf = &tf_text;
  tf_text_handler.param = &params.text->text_;
  tf_text.addObserver(&tf_text_handler);

  auto edit_text = new MenuItem2(
      new Rectangle(
          0, 0, 0, 0,
          buttonImg.getSize().x + label_text.getSize().x + inline_padding * 3,
          label_x1.getSize().y + tf_text.getSize().y + inline_padding * 3, 2,
          131, 240, 253),
      new Text("", font_path, dbg_font_size),
      [&label_text, &tf_text](MenuItem2 *item, sf::RenderWindow &w,
                              sf::Event &e) {
        label_text.updateEvent(e);
        tf_text.updateEvent(e);
      });
  edit_btn.submenu_->Add(edit_text);
  // EDIT_TEXT END

  // EDIT_TEXT_SIZE START
  sf::ui::Label label_font_size(ui_font, "Font size: ");
  label_font_size.setFontColor(sf::Color::Black);
  label_font_size.setFontSize(ui_font_size);

  sf::ui::FormattedTextField tf_font_size(
      buttonImg, buttonFocImg, ui_font, new sf::ui::UnsignedLongFormat,
      std::to_string(params.text->font_size_));

  tf_font_size.setFontSize(ui_font_size);
  tf_font_size.setFontColor(sf::Color::Black);
  tf_font_size.setMaxLength(14);

  struct : public sf::ui::ComponentObserver {
    sf::ui::TextField *tf;
    int *param;
    void onComponentEvent(const sf::ui::ComponentEvent &event) override {
      switch (event.type) {
      case sf::ui::ComponentEvent::FocusLost: {
        *param = std::stoi((*tf).getText().toAnsiString());
      } break;
      }
    }
  } tf_font_size_handler;

  tf_font_size_handler.tf = &tf_font_size;
  tf_font_size_handler.param = &params.text->font_size_;
  tf_font_size.addObserver(&tf_font_size_handler);

  auto edit_font_size = new MenuItem2(
      new Rectangle(
          0, 0, 0, 0,
          buttonImg.getSize().x + label_w.getSize().x + inline_padding * 3,
          label_x1.getSize().y + tf_w.getSize().y + inline_padding * 3, 2, 131,
          240, 253),
      new Text("", font_path, dbg_font_size),
      [&label_font_size, &tf_font_size](MenuItem2 *item, sf::RenderWindow &w,
                                        sf::Event &e) {
        label_font_size.updateEvent(e);
        tf_font_size.updateEvent(e);
      });
  edit_btn.submenu_->Add(edit_font_size);
  // EDIT_TEXT_SIZE END

  // EDIT_TEXT_FILL START
  auto edit_text_fill = new MenuItem2(
      new Rectangle(0, 0, 0, 0, dbg_item_w, dbg_item_h, 2, 131, 240, 253),
      new Text("Text Fill", font_path, dbg_font_size),
      [&params](MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            ColorPicker picker;
            auto [r, g, b] = picker.pick();
            params.text->r_fill_ = r;
            params.text->g_fill_ = g;
            params.text->b_fill_ = b;
            item->base_->r_fill_ = r;
            item->base_->g_fill_ = g;
            item->base_->b_fill_ = b;
          }
        } break;
        }
      });
  edit_btn.submenu_->Add(edit_text_fill);
  // EDIT_TEXT_FILL END

  debug_menu.Add(&edit_btn);
  dbg_p1_y += dbg_item_h + padding;

  // DBG::EDIT END
  auto callback = [&menu, &selector, &callback_info_clicked, &edit_is_on](
                      MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
    switch (e.type) {
    case sf::Event::MouseButtonReleased: {
      auto [x, y] = sf::Mouse::getPosition(w);

      if (!edit_is_on && item->base_->Contains(x, y)) {
        std::cout << item->FullName() << ": catched the click.\n";
        callback_info_clicked = true;

        if (selector != nullptr) {
          menu.ApplyToPath(selector, [](MenuItem2 *i) { i->active_ = false; });
          selector->focused_ = false;
        }

        menu.ApplyToPath(
            item, [](MenuItem2 *i) { i->active_ = true; }, false);
        item->focused_ = true;

        selector = item;
      }
    } break;
    }
  };
  // DBG::ADD START
  MenuItem2 add_btn(
      new Rectangle(game_field.x_ap_, game_field.y_ap_, dbg_p1_x, dbg_p1_y,
                    dbg_item_w, dbg_item_h, 2, 131, 240, 253),
      new Text("Add", font_path, dbg_font_size),
      [&menu, &selector, &factory, &params, &callback, &callback_info_clicked](
          MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            callback_info_clicked = true;

            DisplayObject *base = factory.create(params, true);
            MenuItem2 *new_item =
                new MenuItem2(base, params.text->Clone(), callback);

            std::cout << item->FullName() << ": ";
            if (selector != nullptr) {
              selector->submenu_->Add(new_item);
              std::cout << "created local " << new_item->FullName()
                        << " in scope of " << selector->FullName() << ".\n";
            } else {
              menu.Add(new_item);
              std::cout << "created global " << new_item->FullName() << ".\n";
            }
          }
        } break;
        }
      });
  debug_menu.Add(&add_btn);
  dbg_p1_y += dbg_item_h + padding;
  // DBG::ADD END

  // DBG::REMOVE START
  MenuItem2 remove_btn(
      new Rectangle(game_field.x_ap_, game_field.y_ap_, dbg_p1_x, dbg_p1_y,
                    dbg_item_w, dbg_item_h, 2, 131, 240, 253),
      new Text("Remove", font_path, dbg_font_size),
      [&menu, &selector, &callback_info_clicked](
          MenuItem2 *item, sf::RenderWindow &w, sf::Event &e) {
        switch (e.type) {
        case sf::Event::MouseButtonReleased: {
          auto [x, y] = sf::Mouse::getPosition(w);
          if (item->base_->Contains(x, y)) {
            callback_info_clicked = true;
            std::cout << item->FullName() << ": ";
            if (selector != nullptr) {
              std::cout << "removing selected " << selector->FullName()
                        << "and its children.\n";

              auto parent = menu.Parent(selector);

              bool removed = menu.Remove(selector);
              if (!removed) {
                std::cout << "BUG OCCURED: couldn't remove existing selected "
                             "object.\n";
                std::cout << "\tPossible cause: active&&focused mechanism "
                             "working incorrect.\n";
              }
              selector = parent;
              if (selector != nullptr) {
                selector->focused_ = true;
                selector->active_ = true;
              }
            } else {
              std::cout << "couldn't perform removal (nothing is selected).\n";
            }
          }
        } break;
        }
      });
  debug_menu.Add(&remove_btn);
  dbg_p1_y += dbg_item_h + padding;
  // DBG::REMOVE END

  sf::Event event;
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed: {
        window.close();
      } break;

      case sf::Event::Resized: {
        sf::FloatRect visible_area(0, 0, event.size.width, event.size.height);
        w_border.setSize({static_cast<float>(event.size.width),
                          static_cast<float>(event.size.height)});
        window.setView(sf::View(visible_area));
      } break;

      case sf::Event::KeyPressed: {
        auto ctrl_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
        auto d_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        if (ctrl_pressed && d_pressed) {
          debug_is_on ^= true;
          if (dbg_selector != nullptr) {
            debug_menu.ApplyToPath(
                dbg_selector, [](MenuItem2 *item) { item->active_ = false; });
            dbg_selector->focused_ = false;
            dbg_selector = nullptr;
          }
        }
      } break;

      case sf::Event::MouseButtonReleased: {
        callback_info_clicked = false;
      } break;
      }

      if (debug_is_on) {
        debug_menu.Update(window, event);
      }

      menu.Update(window, event);
      if (event.type == sf::Event::MouseButtonReleased &&
          !callback_info_clicked) {

        if (!edit_is_on && selector != nullptr) {
          std::cout << "<Menu>: unfocusing the selector "
                    << selector->FullName() << ".\n";
          menu.ApplyToPath(selector, [](MenuItem2 *i) { i->active_ = false; });
          selector->focused_ = false;
          selector = nullptr;
        } else if (edit_is_on && selector != nullptr) {
          std::cout
              << "<Menu>: couldn't deselect because <user> is in edit mode.\n";
        }
      }
    }

    window.clear();

    window.draw(w_border);
    game_field.Draw(window);

    menu.Draw(window);

    if (debug_is_on) {
      debug_menu.Draw(window);

      if (edit_is_on) {
        if (!ui_positioned) {
          label_d_x.setPosition(edit_d->base_->x1_client_ + inline_padding,
                                edit_d->base_->y1_client_ + inline_padding);

          tf_d_x.setPosition(edit_d->base_->x1_client_ + label_d_x.getSize().x +
                                 inline_padding,
                             label_d_x.getPosition().y);

          label_d_y.setPosition(edit_d->base_->x1_client_ + inline_padding,
                                tf_d_x.getPosition().y + tf_d_x.getSize().y);

          tf_d_y.setPosition(edit_d->base_->x1_client_ + label_d_y.getSize().x +
                                 inline_padding,
                             label_d_y.getPosition().y);

          label_x1.setPosition(edit_x1_y1->base_->x1_client_ + inline_padding,
                               edit_x1_y1->base_->y1_client_ + inline_padding);

          tf_x1.setPosition(edit_x1_y1->base_->x1_client_ +
                                label_x1.getSize().x + inline_padding,
                            label_x1.getPosition().y);

          label_y1.setPosition(edit_x1_y1->base_->x1_client_ + inline_padding,
                               tf_x1.getPosition().y + tf_x1.getSize().y);

          tf_y1.setPosition(edit_x1_y1->base_->x1_client_ +
                                label_y1.getSize().x + inline_padding,
                            label_y1.getPosition().y);

          label_w.setPosition(edit_w_h->base_->x1_client_ + inline_padding,
                              edit_w_h->base_->y1_client_ + inline_padding);
          tf_w.setPosition(edit_w_h->base_->x1_client_ + label_w.getSize().x +
                               inline_padding,
                           label_w.getPosition().y);

          label_h.setPosition(edit_w_h->base_->x1_client_ + inline_padding,
                              tf_w.getPosition().y + tf_w.getSize().y);

          tf_h.setPosition(edit_w_h->base_->x1_client_ + label_h.getSize().x +
                               inline_padding,
                           label_h.getPosition().y);

          label_bt.setPosition(edit_bt->base_->x1_client_ + inline_padding,
                               edit_bt->base_->y1_client_ + inline_padding);
          tf_bt.setPosition(edit_bt->base_->x1_client_ + label_bt.getSize().x +
                                inline_padding,
                            label_bt.getPosition().y);

          label_text.setPosition(edit_text->base_->x1_client_ + inline_padding,
                                 edit_text->base_->y1_client_ + inline_padding);
          tf_text.setPosition(edit_text->base_->x1_client_ +
                                  label_text.getSize().x + inline_padding,
                              label_text.getPosition().y);

          label_font_size.setPosition(
              edit_font_size->base_->x1_client_ + inline_padding,
              edit_font_size->base_->y1_client_ + inline_padding);
          tf_font_size.setPosition(
              edit_font_size->base_->x1_client_ + inline_padding,
              label_font_size.getPosition().y + label_font_size.getSize().y +
                  inline_padding);

          ui_positioned = true;
        }
        window.draw(label_d_x);
        window.draw(tf_d_x);
        window.draw(label_d_y);
        window.draw(tf_d_y);
        window.draw(label_x1);
        window.draw(tf_x1);
        window.draw(label_y1);
        window.draw(tf_y1);
        window.draw(label_w);
        window.draw(tf_w);
        window.draw(label_h);
        window.draw(tf_h);
        window.draw(label_bt);
        window.draw(tf_bt);
        window.draw(label_text);
        window.draw(tf_text);
        window.draw(label_font_size);
        window.draw(tf_font_size);
      }
    }

    window.display();
  }
}