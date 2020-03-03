#include "View.h"

Game::View::View(Model* model)
	: m_model(model)
{
	model->AddObserver(this);
	setPosition(50.f, 50.f);
	m_model->WindowRef().create(sf::VideoMode(600, 600), "Name");
	m_model->WindowRef().setFramerateLimit(60);
}

void Game::View::OnNotify() {
	m_model->WindowRef().clear(sf::Color::Red);
	m_model->WindowRef().draw(*this);
	m_model->WindowRef().display();
}

void Game::View::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	states.transform *= getTransform();
	m_player.draw(target, states);
}