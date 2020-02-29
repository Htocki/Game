#include "GraphicsComponent.h"

Game::GraphicsComponent::GraphicsComponent() {
	spaceship.setTexture(Assets::Instance().spaceship);
}

void Game::GraphicsComponent::Update(sf::RenderWindow& window) {
	window.draw(*this);
}

void Game::GraphicsComponent::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	states.transform *= getTransform();
	target.draw(spaceship, states);
}