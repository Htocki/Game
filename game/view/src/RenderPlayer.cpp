#include "RenderPlayer.h"

Game::RenderPlayer::RenderPlayer() {
	spaceship.setTexture(Assets::Instance().spaceship);
}

void Game::RenderPlayer::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	states.transform *= getTransform();
	target.draw(spaceship, states);
}