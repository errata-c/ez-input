#include <iostream>

#include <ez/input/Key.hpp>
#include <ez/input/Mouse.hpp>
#include <ez/input/InputEvent.hpp>

#include <fmt/core.h>
#include <fmt/ostream.h>

int main(int argc, char* argv[]) {
	fmt::print("Testing formating compatibility.\n");

	ez::Key key0 = ez::Key::A;
	fmt::print("key0 == {}\n", key0);

	ez::KeyMod mod0 = ez::KeyMod::Alt;
	fmt::print("mod0 == {}\n", mod0);

	ez::KeyMods mod1 = ez::KeyMod::Alt | ez::KeyMod::Ctrl;
	fmt::print("mod1 == {}\n", mod1);

	ez::KeyState key1{};
	key1.held = ez::Key::Comma;
	key1.justPressed = ez::Key::Apostrophe;
	key1.justReleased = ez::Key::Backspace;
	key1.mods = mod1;
	fmt::print("key1 == {}\n", key1);

	ez::KeyEvent key2{};
	key2.code = ez::Key::Delete;
	key2.mods = ez::KeyMods::Shift | ez::KeyMods::System;
	fmt::print("key2 == {}\n", key2);

	ez::Mouse mouse0 = ez::Mouse::Left;
	fmt::print("mouse0 == {}\n", mouse0);

	ez::MouseEvent mouse1{};
	mouse1.button = ez::Mouse::Middle;
	mouse1.position = glm::dvec2{20, 20};
	fmt::print("mouse1 == {}\n", mouse1);

	ez::MouseState mouse2{};
	mouse2.buttons = ez::Mouse::Left | ez::Mouse::Right;
	mouse2.justPressed = ez::Mouse::Left;
	mouse2.justReleased = ez::Mouse::Middle;
	mouse2.position = mouse1.position;
	fmt::print("mouse2 == {}\n", mouse2);

	ez::InputEvent input0;
	input0.type = ez::InEv::Char;
	input0.codepoint = 'A';
	fmt::print("input0 == {}\n", input0);

	ez::InputEvent input1;
	input1.type = ez::InEv::KeyPress;
	input1.key = key2;
	fmt::print("input1 == {}\n", input1);

	ez::InputEvent input2;
	input2.type = ez::InEv::MousePress;
	input2.mouse = mouse1;
	fmt::print("input2 == {}\n", input2);

	ez::InputEvent input3;
	input3.type = ez::InEv::Closed;
	fmt::print("input3 == {}\n", input3);

	return  0;
}