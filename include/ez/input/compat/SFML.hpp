#pragma once
#include <ez/input/Key.hpp>
#include <ez/input/InputEvent.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

// Declare all (non-template) functions in the namespace as static, to prevent linking errors!
namespace ez::input {
	static Key remapSFMLKey(int32_t code) {
		switch (code) {
		case sf::Keyboard::Num0:
		case sf::Keyboard::Num1:
		case sf::Keyboard::Num2:
		case sf::Keyboard::Num3:
		case sf::Keyboard::Num4:
		case sf::Keyboard::Num5:
		case sf::Keyboard::Num6:
		case sf::Keyboard::Num7:
		case sf::Keyboard::Num8:
		case sf::Keyboard::Num9:
			return static_cast<Key>((code - sf::Keyboard::Num0) + static_cast<uint32_t>(Key::N0));

		case sf::Keyboard::Numpad0:
		case sf::Keyboard::Numpad1:
		case sf::Keyboard::Numpad2:
		case sf::Keyboard::Numpad3:
		case sf::Keyboard::Numpad4:
		case sf::Keyboard::Numpad5:
		case sf::Keyboard::Numpad6:
		case sf::Keyboard::Numpad7:
		case sf::Keyboard::Numpad8:
		case sf::Keyboard::Numpad9:
			return static_cast<Key>((code - sf::Keyboard::Numpad0) + static_cast<uint32_t>(Key::KP0));

		case sf::Keyboard::A:
		case sf::Keyboard::B:
		case sf::Keyboard::C:
		case sf::Keyboard::D:
		case sf::Keyboard::E:
		case sf::Keyboard::F:
		case sf::Keyboard::G:
		case sf::Keyboard::H:
		case sf::Keyboard::I:
		case sf::Keyboard::J:
		case sf::Keyboard::K:
		case sf::Keyboard::L:
		case sf::Keyboard::M:
		case sf::Keyboard::N:
		case sf::Keyboard::O:
		case sf::Keyboard::P:
		case sf::Keyboard::Q:
		case sf::Keyboard::R:
		case sf::Keyboard::S:
		case sf::Keyboard::T:
		case sf::Keyboard::U:
		case sf::Keyboard::V:
		case sf::Keyboard::W:
		case sf::Keyboard::X:
		case sf::Keyboard::Y:
		case sf::Keyboard::Z:
			return static_cast<Key>((code - sf::Keyboard::A) + static_cast<uint32_t>(Key::A));

		case sf::Keyboard::Escape:
			return Key::Escape;
		case sf::Keyboard::LControl:
			return Key::LCtrl;
		case sf::Keyboard::RControl:
			return Key::RCtrl;
		case sf::Keyboard::LShift:
			return Key::LShift;
		case sf::Keyboard::RShift:
			return Key::RShift;
		case sf::Keyboard::LAlt:
			return Key::LAlt;
		case sf::Keyboard::RAlt:
			return Key::RAlt;
		case sf::Keyboard::LBracket:
			return Key::LBracket;
		case sf::Keyboard::RBracket:
			return Key::RBracket;
		case sf::Keyboard::LSystem:
			return Key::LSystem;
		case sf::Keyboard::RSystem:
			return Key::RSystem;
		case sf::Keyboard::Semicolon:
			return Key::Semicolon;
		case sf::Keyboard::Comma:
			return Key::Comma;
		case sf::Keyboard::Period:
			return Key::Period;
		case sf::Keyboard::Quote:
			return Key::Quote;
		case sf::Keyboard::Slash:
			return Key::FSlash;
		case sf::Keyboard::Backslash:
			return Key::BSlash;
		case sf::Keyboard::Tilde:
			return Key::Tilde;
		case sf::Keyboard::Equal:
			return Key::Equal;
		case sf::Keyboard::Hyphen:
			return Key::Hyphen;
		case sf::Keyboard::Space:
			return Key::Space;
		case sf::Keyboard::Enter:
			return Key::Enter;
		case sf::Keyboard::Backspace:
			return Key::Backspace;
		case sf::Keyboard::Tab:
			return Key::Tab;
		case sf::Keyboard::PageUp:
			return Key::PageUp;
		case sf::Keyboard::PageDown:
			return Key::PageDown;
		case sf::Keyboard::End:
			return Key::End;
		case sf::Keyboard::Home:
			return Key::Home;
		case sf::Keyboard::Insert:
			return Key::Insert;
		case sf::Keyboard::Delete:
#ifdef ANDROID
			return Key::Backspace;
#else
			return Key::Delete;
#endif
		case sf::Keyboard::Add:
			return Key::KPAdd;
		case sf::Keyboard::Subtract:
			return Key::KPSubtract;
		case sf::Keyboard::Multiply:
			return Key::KPMultiply;
		case sf::Keyboard::Divide:
			return Key::KPDivide;
		case sf::Keyboard::Left:
			return Key::Left;
		case sf::Keyboard::Right:
			return Key::Right;
		case sf::Keyboard::Up:
			return Key::Up;
		case sf::Keyboard::Down:
			return Key::Down;
		case sf::Keyboard::Pause:
			return Key::Pause;
		default:
			return Key::Unknown;
		}
	}
	
	static InputEvent remapEvent(const sf::Event & in) {
		InputEvent event;
		switch (in.type) {
		case sf::Event::Resized:
			event.type = InputEventType::Resized;
			event.size = glm::ivec2{ in.size.width, in.size.height };
			return event;

		case sf::Event::LostFocus:
			event.type = InputEventType::FocusLost;
			return event;

		case sf::Event::GainedFocus:
			event.type = InputEventType::FocusGained;
			return event;

		case sf::Event::Closed:
			event.type = InputEventType::Closed;
			return event;

		case sf::Event::TextEntered:
			event.type = InputEventType::Char;
			event.codepoint = in.text.unicode;
			return event;

		case sf::Event::KeyPressed:
			event.type = InputEventType::KeyPress;
			event.key = KeyEvent{};
			event.key.code = (remapSFMLKey(in.key.code));
			if (in.key.control) {
				event.key.mods |= ez::KeyMod::Ctrl;
			}
			if (in.key.alt) {
				event.key.mods |= ez::KeyMod::Alt;
			}
			if (in.key.shift) {
				event.key.mods |= ez::KeyMod::Shift;
			}
			if (in.key.system) {
				event.key.mods |= ez::KeyMod::System;
			}

			return event;

		case sf::Event::KeyReleased:
			event.type = InputEventType::KeyRelease;
			event.key = KeyEvent{};
			event.key.code = (static_cast<Key>(remapSFMLKey(in.key.code)));
			if (in.key.control) {
				event.key.mods |= ez::KeyMod::Ctrl;
			}
			if (in.key.alt) {
				event.key.mods |= ez::KeyMod::Alt;
			}
			if (in.key.shift) {
				event.key.mods |= ez::KeyMod::Shift;
			}
			if (in.key.system) {
				event.key.mods |= ez::KeyMod::System;
			}
			return event;

		case sf::Event::MouseWheelScrolled:
			event.type = InputEventType::Scroll;
			if (in.mouseWheelScroll.wheel == sf::Mouse::Wheel::VerticalWheel) {
				event.scroll = glm::dvec2{ 0.0, in.mouseWheelScroll.delta };
			}
			else {
				event.scroll = glm::dvec2{ in.mouseWheelScroll.delta, 0.0 };
			}
			return event;

		case sf::Event::MouseMoved:
			event.type = InputEventType::MouseMove;
			event.mouse = MouseEvent{};
			event.mouse.position = glm::dvec2{ in.mouseMove.x, in.mouseMove.y };
			return event;

		case sf::Event::MouseButtonPressed:
			event.type = InputEventType::MousePress;
			event.mouse = MouseEvent{};
			event.mouse.position = glm::dvec2{in.mouseButton.x, in.mouseButton.y};
			switch (in.mouseButton.button) {
			case sf::Mouse::Button::Left:
				event.mouse.button = Mouse::Left;
				break;
			case sf::Mouse::Button::Right:
				event.mouse.button = Mouse::Right;
				break;
			case sf::Mouse::Button::Middle:
				event.mouse.button = Mouse::Middle;
				break;
			case sf::Mouse::Button::XButton1:
				event.mouse.button = Mouse::Button4;
				break;
			case sf::Mouse::Button::XButton2:
				event.mouse.button = Mouse::Button5;
				break;
			}
			return event;

		case sf::Event::MouseButtonReleased:
			event.type = InputEventType::MouseRelease;
			event.mouse = MouseEvent{};
			event.mouse.position = glm::dvec2{ in.mouseButton.x, in.mouseButton.y };
			switch (in.mouseButton.button) {
			case sf::Mouse::Button::Left:
				event.mouse.button = Mouse::Left;
				break;
			case sf::Mouse::Button::Right:
				event.mouse.button = Mouse::Right;
				break;
			case sf::Mouse::Button::Middle:
				event.mouse.button = Mouse::Middle;
				break;
			case sf::Mouse::Button::XButton1:
				event.mouse.button = Mouse::Button4;
				break;
			case sf::Mouse::Button::XButton2:
				event.mouse.button = Mouse::Button5;
				break;
			}
			return event;

		case sf::Event::MouseEntered:
			event.type = InputEventType::MouseEnter;
			event.mouse = MouseEvent{};
			return event;

		case sf::Event::MouseLeft:
			event.type = InputEventType::MouseLeave;
			event.mouse = MouseEvent{};
			return event;

		case sf::Event::JoystickButtonPressed:
			event.type = InputEventType::ControllerPress;
			event.codepoint = 0;
			return event;

		case sf::Event::JoystickButtonReleased:
			event.type = InputEventType::ControllerRelease;
			event.codepoint = 0;
			return event;

		case sf::Event::JoystickMoved:
			event.type = InputEventType::ControllerMove;
			event.codepoint = 0;
			return event;

		case sf::Event::JoystickConnected:
			event.type = InputEventType::ControllerConnect;
			event.codepoint = 0;
			return event;

		case sf::Event::JoystickDisconnected:
			event.type = InputEventType::ControllerDisconnect;
			event.codepoint = 0;
			return event;

		case sf::Event::TouchBegan:
			event.type = InputEventType::TouchPress;
			return event;

		case sf::Event::TouchMoved:
			event.type = InputEventType::TouchMove;
			return event;

		case sf::Event::TouchEnded:
			event.type = InputEventType::TouchRelease;
			return event;
			
		default:

			return event;
		}
	}
};