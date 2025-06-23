#include <stdio.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_init.h>

int main() {
  const int window_w = 640;
  const int window_h = 480;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    return 1;
  }

  // Window declaration
  SDL_Window *window = SDL_CreateWindow("foo-sdl3", window_w, window_h, 0);
  if (!window) {
    fprintf(stderr, "Cannot create window");
    return 1;
  }

  // Rendererer declaration
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer) {
    fprintf(stderr, "Cannot create renderer");
    return 1;
  }

  // Drawing
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderPresent(renderer);

  SDL_Event event;

  // Main loop
  while (true) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT)
        return 0;
    }
  }

  // Destroying
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  return 0;
}
