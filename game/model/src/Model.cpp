#include "Model.h"

Game::Model::Model()
    : m_state(State::Run)
{
    Assets::Instance().Load();
}