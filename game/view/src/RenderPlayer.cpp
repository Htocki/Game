#include "RenderPlayer.h"

Game::RenderPlayer::RenderPlayer() {
	m_spaceship.setTexture(Assets::Instance().spaceship);
}

void Game::RenderPlayer::Render(
	const Player& player,
	sf::RenderWindow& window
) {
	Update(player);
	window.draw(m_spaceship);
}

void Game::RenderPlayer::Update(const Player& player) {
	m_spaceship.setPosition(player.GetPosition());
}

void Game::RenderPlayer::draw(
	sf::RenderTarget& target,
	sf::RenderStates states
) const {
	states.transform *= getTransform();
	target.draw(m_spaceship, states);
}