#include "View.h"

Game::View::View(Model* model)
	: m_model(model)
{
	setPosition(50.f, 50.f);
	m_model->Window().create(sf::VideoMode(600, 600), "Name");
	m_model->Window().setFramerateLimit(60);
}

void Game::View::Render() {
	m_model->Window().clear();
	m_model->Window().draw(*this);
	m_model->Window().display();
}

void Game::View::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	states.transform *= getTransform();
}