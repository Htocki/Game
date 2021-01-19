#include "Application.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "Assets.h"

namespace Game {
Application::Application() 
    : m_window { sf::Vector2u { 400, 800 }, sf::String { "SPACE WANDERER" } }
    , m_player {}
    , m_text_title { &m_window }
    , m_button_play { &m_window }
    , m_button_records { &m_window }
    , m_button_settings { &m_window }
    , m_button_exit { &m_window }
    , m_spaceship_view { &m_window, m_player.GetSpaceship() }
{
  m_text_title.SetPosition(sf::Vector2f { 45, 160 });
  m_text_title.SetFont(Assets::Instance().GetFont());
  m_text_title.SetString(sf::String { "SPACE WANDERER" });
  m_text_title.SetCharacterSize(33);
  m_text_title.SetFillColor(sf::Color::White);
  m_text_title.SetStyle(sf::Text::Bold);
  
  m_button_play.SetSize(sf::Vector2f { 288, 34 });
  m_button_play.SetFillColor(sf::Color::Black);
  m_button_play.SetOutlineColor(sf::Color::White);
  m_button_play.SetOutlineThickness(3);
  m_button_play.SetTextFont(Assets::Instance().GetFont());
  m_button_play.SetTextString(sf::String { "PLAY" });
  m_button_play.SetTextCharacterSize(26);
  m_button_play.SetTextFillColor(sf::Color::White);
  m_button_play.SetTextStyle(sf::Text::Bold);
  m_button_play.SetPosition(sf::Vector2f { 55, 375 });
  
  m_button_records.SetSize(sf::Vector2f { 288, 34 });
  m_button_records.SetFillColor(sf::Color::Black);
  m_button_records.SetOutlineColor(sf::Color::White);
  m_button_records.SetOutlineThickness(3);
  m_button_records.SetTextFont(Assets::Instance().GetFont());
  m_button_records.SetTextCharacterSize(26);
  m_button_records.SetTextFillColor(sf::Color::White);
  m_button_records.SetTextStyle(sf::Text::Bold);
  m_button_records.SetTextString(sf::String { "RECORDS" });
  m_button_records.SetPosition(sf::Vector2f { 55, 425 });

  m_button_settings.SetSize(sf::Vector2f { 288, 34 });
  m_button_settings.SetFillColor(sf::Color::Black);
  m_button_settings.SetOutlineColor(sf::Color::White);
  m_button_settings.SetOutlineThickness(3);
  m_button_settings.SetTextFont(Assets::Instance().GetFont());
  m_button_settings.SetTextCharacterSize(26);
  m_button_settings.SetTextFillColor(sf::Color::White);
  m_button_settings.SetTextStyle(sf::Text::Bold);
  m_button_settings.SetTextString(sf::String { "SETTINGS" });
  m_button_settings.SetPosition(sf::Vector2f { 55, 475 });

  m_button_exit.SetSize(sf::Vector2f { 288, 34 });
  m_button_exit.SetFillColor(sf::Color::Black);
  m_button_exit.SetOutlineColor(sf::Color::White);
  m_button_exit.SetOutlineThickness(3);
  m_button_exit.SetTextFont(Assets::Instance().GetFont());
  m_button_exit.SetTextCharacterSize(26);
  m_button_exit.SetTextFillColor(sf::Color::White);
  m_button_exit.SetTextStyle(sf::Text::Bold);
  m_button_exit.SetTextString(sf::String { "EXIT" });
  m_button_exit.SetPosition(sf::Vector2f { 55, 525 });
}

void Application::Run() {
  while (m_window.IsOpen()) {
    sf::Event event;
    while (m_window.PollEvent(&event)) {
      HandleEvent(event);
      Draw();
    }
  }
}

void Application::HandleEvent(const sf::Event& event) {
  m_window.HandleEvent(event);
  m_player.HandleEvent(event);
  m_button_play.HandleEvent(event);
  m_button_records.HandleEvent(event);
  m_button_settings.HandleEvent(event);
  m_button_exit.HandleEvent(event);
}

void Application::Draw() {
  m_window.Clear();
  m_spaceship_view.Draw();
  m_text_title.Draw();
  m_button_play.Draw();
  m_button_records.Draw();
  m_button_settings.Draw();
  m_button_exit.Draw();
  m_window.Display();
}
}  // namespace Game
