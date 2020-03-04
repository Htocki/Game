#include "View.h"

Game::View::View(Engine* engine)
	: m_engine(engine)
	, m_window(engine->WindowRef())
{
	m_engine->AddObserver(this);
	m_window.create(sf::VideoMode(600, 600), "Name");
	m_window.setFramerateLimit(60);
}

void Game::View::OnNotify() {
	m_window.clear();

	m_player.Render(m_engine->GetPlayer(), m_window);

	m_window.display();
}