#include <fmt/format.h>
#include <GL/glew.h>
#include <SFML/window.hpp>

#include <ez/input/compat/SFML.hpp>

#include <ez/input/InputEngine.hpp>
#include <ez/input/KeyMap.hpp>
#include <ez/input/Operator.hpp>
#include <ez/input/OperatorRegistry.hpp>

struct Context {};
using Operator = ez::Operator<Context>;

struct TestOp : public Operator {

	bool poll(const Context& context) const override {

	}
	ez::OpResult execute(const ez::InputState& state, Context& context) override {

	}
	ez::OpResult invoke(const ez::InputState& state, Context& context) override {

	}
	ez::OpResult modal(const ez::InputState& state, Context& context) override {

	}
	bool cancel(Context& context) override {
		return true;
	}
};

int main() {
	fmt::print("Initializing operator_test\n");

	sf::Window window(sf::VideoMode(800, 600), "operator_test");

	{
		int result = glewInit();
		if (result != GLEW_OK) {
			throw std::exception("Failed to initialize GLEW!");
		}
	}

	ez::KeyMap mapping;
	ez::InputEngine inputEngine;
	ez::OperatorRegistry<Context> ops;

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event sfmlev;
		while (window.pollEvent(sfmlev))
		{
			ez::InputEvent event = ez::input::remapEvent(sfmlev);

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