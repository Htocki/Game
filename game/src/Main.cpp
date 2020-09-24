#include <exception>
#include <iostream>

#include "Application.h"

int main() {
  try {
    Game::Application application;
    application.Run();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception..." << std::endl;
  }
}
