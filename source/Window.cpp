#include <radix/Window.hpp>
#include <stdexcept>
#include <SDL2/SDL.h>

namespace radix {

const unsigned int Window::DEFAULT_WIDTH = 800;
const unsigned int Window::DEFAULT_HEIGHT = 600;
const char* Window::DEFAULT_TITLE = "Radix Engine";

Window::Window(std::string title) :
  title(title),
  width(0),
  height(0),
  window(nullptr),
  gamePadEnabled(true),
  ignoreGlVersion(false),
  antialiasLevel(0),
  created(false){}

void Window::create(int minimumOpenGlVersion){
  if (not created) {
    Uint32 initFlags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    if (gamePadEnabled) {
      initFlags |= SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER;;
    }

    if (SDL_Init(initFlags) != 0) {
      throw std::runtime_error(std::string("Error on SDL init ") + SDL_GetError());
    }
  } else {
    throw std::runtime_error("Can't create two windows from the same window class instance." );
  }
}

void Window::setAntialiasLevel(int level){
  if (level >= 0 && level <= 4){
  antialiasLevel = level;
} else {
  throw std::runtime_error("Antialiasing level out of range" );
 }
}

Window::~Window() = default;
} /* namespace radix */

