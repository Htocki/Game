#include <exception>
#include <iostream>

#include "Controller.h"
#include "Model.h"
#include "View.h"

int main() 
{
    Game::Model model;
    Game::View view(&model);
    Game::Controller controller(&model);
}
