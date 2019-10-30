#include "Player.hpp"
#include "Enums.hpp"



Player::Player(ResourceHolder <sf::Texture, Textures::ID>& textures)
    : score_()
    , spaceship_({200, 700})
    , name_("Miha default player")
{
    spaceship_.setTexture(textures.get(Textures::Spaceship));
}

void Player::processEvents(sf::Event& event)
{
    spaceship_.processEvents(event);
}

void Player::update(sf::Time time)
{
    spaceship_.update(time);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    spaceship_.draw(target, states);
}

sf::Int64 Player::getScore()
{
    return score_.getScore();
}

std::string Player::getName() const
{
    return name_;
}
