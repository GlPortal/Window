#ifndef RADIX_WINDOW_HPP
#define RADIX_WINDOW_HPP

#include <memory>
#include <string>
#include <vector>

#include <SDL2/SDL_video.h>
namespace radix {

class Window {
public:
  Window(std::string title);
  void create(int minimumOpenGlVersion);
  void setEnableGamePad(bool enabled);
  void setAntialiasLevel(int antialiasLevel);
  ~Window();
private:
  std::string title;
  unsigned int  width;
  unsigned int  height;
  SDL_Window   *window;
  SDL_GLContext context;
  bool gamePadEnabled;
  bool ignoreGlVersion;
  unsigned int antialiasLevel;
  bool created;
  static const char*        DEFAULT_TITLE;
  static const unsigned int DEFAULT_WIDTH;
  static const unsigned int DEFAULT_HEIGHT;
};

} /* namespace radix */

#endif /* RADIX_WINDOW_HPP */
