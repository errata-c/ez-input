#include <fmt/format.h>
#include <GL/glew.h>
#include <SFML/window.hpp>

#include <ez/input/compat/SFML.hpp>

int main() {
	fmt::print("Initializing sfml_test\n");

	sf::Window window(sf::VideoMode(800, 600), "sfml_test");
	
	{
		int result = glewInit();
		if (result != GLEW_OK) {
			throw std::exception("Failed to initialize GLEW!");
		}
	}

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event sfmlEvent;
		while (window.pollEvent(sfmlEvent))
		{
			ez::InputEvent event = ez::remapSFMLEvent(sfmlEvent);

			// "close requested" event: we close the window
			if (event.type == ez::InEv::Closed) {
				window.close();
			}
			else {
				fmt::print("{}\n", event.to_string());
			}
		}
	}


	return 0;
}