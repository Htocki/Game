#include "Application.h"

namespace Game 
{
    Game::Application::Application()
        : m_view{ &m_model }
        , m_controller{ &m_model }
        , m_delay{ sf::seconds(1.f / 60.f) }
    {}

    void Game::Application::Run() {
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;

        while (m_model.WindowRef().isOpen())
        {
            sf::Time elapsedTime = clock.restart();
            timeSinceLastUpdate += elapsedTime;

            m_controller.HandleInput();

            while (timeSinceLastUpdate > m_delay) {
                timeSinceLastUpdate -= m_delay;
                m_model.Update(m_delay);
            }
        }
    }
}