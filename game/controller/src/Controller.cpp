#include "Controller.h"

Game::Controller::Controller(Model* model) 
	: m_model(model)
{}

void Game::Controller::Run() {
	sf::Event event;

	while (m_model->Window().isOpen()) 
	{
		while (m_model->Window().pollEvent(event)) 
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
				break;

			case Model::State::Settings:
				break;
			}
			
			switch (event.type) 
			{
			case sf::Event::Closed:
				m_model->Window().close();
				break;
			}
		}
	}
}