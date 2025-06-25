#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <stdio.h>

SDL_FRect init_frect(float x, float y, float w, float h) {
  SDL_FRect result;
  result.x = x;
  result.y = y;
  result.w = w;
  result.h = h;

  return result;
}

int main() {
  const int window_w = 1280;
  const int window_h = 720;

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

  SDL_SetRenderLogicalPresentation(renderer, 1280, 720, SDL_LOGICAL_PRESENTATION_DISABLED);

  SDL_Event event;
  float example_rect_x = 100;
  float example_rect_y = 100;

  // Main loop
  while (true) {
    // Drawing
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
    const SDL_FRect example_rect = init_frect(example_rect_x, example_rect_y, 100.0, 100.0);
    SDL_RenderFillRect(renderer, &example_rect);
    SDL_RenderPresent(renderer);


    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT)
        return 0;

      if (event.type == SDL_EVENT_KEY_DOWN) {
        if (event.key.key == SDLK_ESCAPE)
          return 0;

        if (event.key.key == SDLK_LEFT) {
          example_rect_x = example_rect_x - 10;
	}
        if (event.key.key == SDLK_RIGHT) {
          example_rect_x = example_rect_x + 10;
	}
        if (event.key.key == SDLK_UP) {
          example_rect_y = example_rect_y - 10;
	}
        if (event.key.key == SDLK_DOWN) {
          example_rect_y = example_rect_y + 10;
	}
      }
    }
  }

  // Destroying
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  return 0;
}
