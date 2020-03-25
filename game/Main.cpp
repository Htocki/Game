#include <iostream>

#include "Application.h"

int main() {
  try {
    Game::Application application;
    application.Run();
  } catch (Game::Assets::LoadingFail) {
    std::cerr << "Resource loading failed..." << std::endl;
  } catch (...) {
    std::cerr << "Unknown error..." << std::endl;
  }
}
