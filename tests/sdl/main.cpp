#include <GL/glew.h>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <SDL.h>

#include <ez/input/InputEngine.hpp>
#include <ez/input/KeyMap.hpp>

#include <ez/input/compat/SDL2.hpp>

int main(int argc, char ** argv) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fmt::print(stderr, "Failed to initialize SDL!\n");
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		fmt::print(stderr, "Failed to create a window in SDL!\n");
		return 1;
	}

	bool running = true;
	while (running) {
		SDL_Event sdlev;
		int err = SDL_WaitEvent(&sdlev);
		if (err == 0) {
			fmt::print(stderr, "SDL encountered an error doing basically nothing. A very bad sign indeed.\n");
			running = false;
		}

		ez::InputEvent ev = ez::input::remapEvent(sdlev);
		if (ev.type == ez::InEv::Closed) {
			running = false;
		}
		else {
			fmt::print("Input event: {}\n", ev);
		}
	}

	return 0;
}