#include <iostream>

#include "Controller.h"
#include "Model.h"
#include "View.h"

int main() 
{
    try {
        Game::Model model;
        Game::View view(&model);
        Game::Controller controller(&model);
        controller.Run();
    }
    catch (Game::Assets::LoadingFail) {
        std::cerr << "Resource loading failed..." << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error..." << std::endl;
    }
}
