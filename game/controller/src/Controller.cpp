#include "Controller.h"

Game::Controller::Controller(Model* model) 
	: m_model(model)
{}

void Game::Controller::HandleInput() {
	sf::Event event;

	while (m_model->WindowRef().pollEvent(event))
	{
		switch (m_model->GetState())
		{
		case Model::State::GameOver:
			break;

		case Model::State::Loading:
			break;

		case Model::State::Menu:
			break;

		case Model::State::Pause:
			break;

		case Model::State::Records:
			break;

		case Model::State::Run:
			m_player.HandleInput(
				m_model->PlayerRef(),
				event
			);
			break;

		case Model::State::Settings:
			break;
		}

		switch (event.type)
		{
		case sf::Event::Closed:
			m_model->WindowRef().close();
			break;
		}
	}
}