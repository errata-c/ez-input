#include <GL/glew.h>
#include <fmt/core.h>
#include <SDL.h>

#include <ez/input/InputEngine.hpp>
#include <ez/input/KeyMap.hpp>

#include <ez/input/compat/SDL2.hpp>

int main(int argc, char ** argv) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fmt::print(stderr, "Failed to initialize SDL!\n");
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("SDL2 Test", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		fmt::print(stderr, "Failed to create a window in SDL!\n");
		return 1;
	}

	bool running = true;
	while (running) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			
		}
	}

	return 0;
}