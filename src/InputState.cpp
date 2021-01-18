#include <ez/input/InputState.hpp>
#include <cassert>
#include <algorithm>

namespace ez {
	InputState::InputState()
		: type(InEv::None)
		, codepoint(0)
		, scroll{ 0.0 }
		, focused(false)
		, size(0)
	{}

	void InputState::reset() {
		resetKey();
		resetScroll();
		resetMouse();

		type = InEv::None;

		codepoint = 0;

		focused = false;
	}
	void InputState::resetKey() {
		key.reset();
	}
	void InputState::resetMouse() {
		mouse.reset();
	}
	void InputState::resetScroll() {
		scroll = glm::dvec2{ 0.0,0.0 };
	}

	void InputState::merge(const InputEvent& event) {
		switch (event.type) {
		case InEv::Char:
			codepoint = event.codepoint;
			break;
		case InEv::KeyPress:
			if (key.held == Key::None && !event.key.isModifier()) {
				key.held = event.key.code;
			}
			key.mods = event.key.mods;
			key.justPressed = event.key.code;
			break;
		case InEv::KeyRelease:
			if (key.held == event.key.code) {
				key.held = Key::None;
			}
			key.mods = event.key.mods;
			key.justReleased = event.key.code;
			break;
		case InEv::MouseMove:
			mouse.position = event.mouse.position;
			break;
		case InEv::MousePress:
			mouse.position = event.mouse.position;
			mouse.buttons.press(event.mouse.button);
			mouse.justPressed = event.mouse.button;
			break;
		case InEv::MouseRelease:
			mouse.position = event.mouse.position;
			mouse.buttons.release(event.mouse.button);
			mouse.justReleased = event.mouse.button;
			break;
		case InEv::Resized:
			size = event.size;
			break;
		case InEv::Scroll:
			scroll = event.scroll;
			break;
		case InEv::FocusGained:
			focused = true;
			break;
		case InEv::FocusLost:
			focused = false;
			break;
		}
		type = event.type;
	}

	void InputState::clear() {
		reset();
	}
};