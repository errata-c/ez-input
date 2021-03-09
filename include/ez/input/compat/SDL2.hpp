#pragma once
#include <cuchar>

#include <ez/input/Key.hpp>
#include <ez/input/InputEvent.hpp>

#include <SDL_scancode.h>
#include <SDL_events.h>

namespace ez::input {

	static Key remapSDLKey(int32_t code) {
		switch (code) {
		case SDLK_0:
			return ez::Key::N0;
		case SDLK_1:
			return ez::Key::N1;
		case SDLK_2:
			return ez::Key::N2;
		case SDLK_3:
			return ez::Key::N3;
		case SDLK_4:
			return ez::Key::N4;
		case SDLK_5:
			return ez::Key::N5;
		case SDLK_6:
			return ez::Key::N6;
		case SDLK_7:
			return ez::Key::N7;
		case SDLK_8:
			return ez::Key::N8;
		case SDLK_9:
			return ez::Key::N9;


		case SDLK_a:
			return ez::Key::A;
		case SDLK_b:
			return ez::Key::B;
		case SDLK_c:
			return ez::Key::C;
		case SDLK_d:
			return ez::Key::D;
		case SDLK_e:
			return ez::Key::E;
		case SDLK_f:
			return ez::Key::F;
		case SDLK_g:
			return ez::Key::G;
		case SDLK_h:
			return ez::Key::H;
		case SDLK_i:
			return ez::Key::I;
		case SDLK_j:
			return ez::Key::J;
		case SDLK_k:
			return ez::Key::K;
		case SDLK_l:
			return ez::Key::L;
		case SDLK_m:
			return ez::Key::M;
		case SDLK_n:
			return ez::Key::N;
		case SDLK_o:
			return ez::Key::O;
		case SDLK_p:
			return ez::Key::P;
		case SDLK_q:
			return ez::Key::Q;
		case SDLK_r:
			return ez::Key::R;
		case SDLK_s:
			return ez::Key::S;
		case SDLK_t:
			return ez::Key::T;
		case SDLK_u:
			return ez::Key::U;
		case SDLK_v:
			return ez::Key::V;
		case SDLK_w:
			return ez::Key::W;
		case SDLK_x:
			return ez::Key::X;
		case SDLK_y:
			return ez::Key::Y;
		case SDLK_z:
			return ez::Key::Z;


		case SDLK_F1:
			return ez::Key::F1;
		case SDLK_F2:
			return ez::Key::F2;
		case SDLK_F3:
			return ez::Key::F3;
		case SDLK_F4:
			return ez::Key::F4;
		case SDLK_F5:
			return ez::Key::F5;
		case SDLK_F6:
			return ez::Key::F6;
		case SDLK_F7:
			return ez::Key::F7;
		case SDLK_F8:
			return ez::Key::F8;
		case SDLK_F9:
			return ez::Key::F9;
		case SDLK_F10:
			return ez::Key::F10;
		case SDLK_F11:
			return ez::Key::F11;
		case SDLK_F12:
			return ez::Key::F12;
		case SDLK_F13:
			return ez::Key::F13;
		case SDLK_F14:
			return ez::Key::F14;
		case SDLK_F15:
			return ez::Key::F15;
		case SDLK_F16:
			return ez::Key::F16;
		case SDLK_F17:
			return ez::Key::F17;
		case SDLK_F18:
			return ez::Key::F18;
		case SDLK_F19:
			return ez::Key::F19;
		case SDLK_F20:
			return ez::Key::F20;
		case SDLK_F21:
			return ez::Key::F21;
		case SDLK_F22:
			return ez::Key::F22;
		case SDLK_F23:
			return ez::Key::F23;
		case SDLK_F24:
			return ez::Key::F24;

		
		case SDLK_KP_0:
			return ez::Key::KP0;
		case SDLK_KP_1:
			return ez::Key::KP1;
		case SDLK_KP_2:
			return ez::Key::KP2;
		case SDLK_KP_3:
			return ez::Key::KP3;
		case SDLK_KP_4:
			return ez::Key::KP4;
		case SDLK_KP_5:
			return ez::Key::KP5;
		case SDLK_KP_6:
			return ez::Key::KP6;
		case SDLK_KP_7:
			return ez::Key::KP7;
		case SDLK_KP_8:
			return ez::Key::KP8;
		case SDLK_KP_9:
			return ez::Key::KP9;


		case SDLK_QUOTE:
			return ez::Key::Quote;
		case SDLK_APPLICATION: // Windows key, system key
			return ez::Key::LSystem;
		case SDLK_BACKSLASH:
			return ez::Key::BSlash;
		case SDLK_BACKSPACE:
			return ez::Key::Backspace;
		case SDLK_CAPSLOCK:
			return ez::Key::CapsLock;
		case SDLK_COMMA:
			return ez::Key::Comma;
		case SDLK_DELETE:
			return ez::Key::Delete;
		case SDLK_DOWN:
			return ez::Key::Down;
		case SDLK_END:
			return ez::Key::End;
		case SDLK_EQUALS:
			return ez::Key::Equal;
		case SDLK_ESCAPE:
			return ez::Key::Escape;
		case SDLK_BACKQUOTE:
			return ez::Key::Grave;
		case SDLK_HOME:
			return ez::Key::Home;
		case SDLK_INSERT:
			return ez::Key::Insert;
		case SDLK_KP_PERIOD:
			return ez::Key::KPDecimal;
		case SDLK_KP_DIVIDE:
			return ez::Key::KPDivide;
		case SDLK_KP_ENTER:
			return ez::Key::KPEnter;
		case SDLK_KP_EQUALS:
			return ez::Key::KPEqual;
		case SDLK_KP_MINUS:
			return ez::Key::KPSubtract;
		case SDLK_KP_MULTIPLY:
			return ez::Key::KPMultiply;
		case SDLK_KP_PLUS:
			return ez::Key::KPAdd;
		case SDLK_LALT:
			return ez::Key::LAlt;
		case SDLK_LCTRL:
			return ez::Key::LCtrl;
		case SDLK_LEFT:
			return ez::Key::Left;
		case SDLK_LEFTBRACKET:
			return ez::Key::LBracket;
		case SDLK_LSHIFT:
			return ez::Key::LShift;
		case SDLK_MINUS:
			return ez::Key::Minus;
		case SDLK_PAGEDOWN:
			return ez::Key::PageDown;
		case SDLK_PAGEUP:
			return ez::Key::PageUp;
		case SDLK_PERIOD:
			return ez::Key::Period;
		case SDLK_PRINTSCREEN:
			return ez::Key::PrintScreen;
		case SDLK_RALT:
			return ez::Key::RAlt;
		case SDLK_RCTRL:
			return ez::Key::RCtrl;
		case SDLK_RETURN:
			return ez::Key::Enter;
		case SDLK_RIGHT:
			return ez::Key::Right;
		case SDLK_RIGHTBRACKET:
			return ez::Key::RBracket;
		case SDLK_RSHIFT:
			return ez::Key::RShift;
		case SDLK_SCROLLLOCK:
			return ez::Key::ScrollLock;
		case SDLK_SEMICOLON:
			return ez::Key::Semicolon;
		case SDLK_SLASH:
			return ez::Key::FSlash;
		case SDLK_SPACE:
			return ez::Key::Space;
		case SDLK_TAB:
			return ez::Key::Tab;
		case SDLK_UP:
			return ez::Key::Up;
		
		case SDLK_AMPERSAND:
			return ez::Key::N7;
		case SDLK_ASTERISK:
			return ez::Key::N8;
		case SDLK_AT:
			return ez::Key::N2;
		case SDLK_CARET:
			return ez::Key::N6;
		case SDLK_COLON:
			return ez::Key::Semicolon;
		case SDLK_DOLLAR:
			return ez::Key::N4;
		case SDLK_EXCLAIM:
			return ez::Key::N1;
		case SDLK_GREATER:
			return ez::Key::Period;
		case SDLK_HASH:
			return ez::Key::N3;
		case SDLK_LEFTPAREN:
			return ez::Key::N9;
		case SDLK_LESS:
			return ez::Key::Comma;
		case SDLK_PERCENT:
			return ez::Key::N5;
		case SDLK_PLUS:
			return ez::Key::Equal;
		case SDLK_QUESTION:
			return ez::Key::FSlash;
		case SDLK_QUOTEDBL:
			return ez::Key::Quote;
		case SDLK_RIGHTPAREN:
			return ez::Key::N0;
		case SDLK_UNDERSCORE:
			return ez::Key::Minus;

		default:
			return ez::Key::Unknown;
		}
	}

	static ez::InputEvent remapEvent(const SDL_Event & ev) {
		ez::InputEvent event;
		switch (ev.type) {
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			if(ev.button.type == SDL_MOUSEBUTTONDOWN) {
				event.type = ez::InEv::MousePress;
			}
			else {
				event.type = ez::InEv::MouseRelease;
			}
			
			switch (ev.button.button) {
			case SDL_BUTTON_LEFT:
				event.mouse.button = (ez::Mouse::Left);
				break;
			case SDL_BUTTON_MIDDLE:
				event.mouse.button = (ez::Mouse::Middle);
				break;
			case SDL_BUTTON_RIGHT:
				event.mouse.button = (ez::Mouse::Right);
				break;
			case SDL_BUTTON_X1:
				event.mouse.button = (ez::Mouse::Button4);
				break;
			case SDL_BUTTON_X2:
				event.mouse.button = (ez::Mouse::Button5);
				break;
			}
			event.mouse.position.x = ev.button.x;
			event.mouse.position.y = ev.button.y;
			return event;

		case SDL_MOUSEMOTION:
			event.type = ez::InEv::MouseMove;
			event.mouse.button = ez::Mouse::None;
			event.mouse.position.x = ev.motion.x;
			event.mouse.position.y = ev.motion.y;
			return event;

		case SDL_MOUSEWHEEL:
			event.type = ez::InEv::Scroll;
			event.scroll.x = ev.wheel.x;
			event.scroll.y = ev.wheel.y;
			return event;

		case SDL_CONTROLLERAXISMOTION:
			event.type = ez::InEv::ControllerMove;
			return event;
		case SDL_CONTROLLERBUTTONDOWN:
			event.type = ez::InEv::ControllerPress;
			return event;
		case SDL_CONTROLLERBUTTONUP:
			event.type = ez::InEv::ControllerRelease;
			return event;
		case SDL_CONTROLLERDEVICEADDED:
			event.type = ez::InEv::ControllerConnect;
			return event;
		case SDL_CONTROLLERDEVICEREMOVED:
			event.type = ez::InEv::ControllerDisconnect;
			return event;

		case SDL_FINGERMOTION:
			event.type = ez::InEv::TouchMove;
			return event;
		case SDL_FINGERDOWN:
			event.type = ez::InEv::TouchPress;
			return event;
		case SDL_FINGERUP:
			event.type = ez::InEv::TouchRelease;
			return event;

		case SDL_KEYDOWN:
			event.type = ez::InEv::KeyPress;
			event.key.code = (remapSDLKey(ev.key.keysym.sym));
			if (ev.key.keysym.mod & KMOD_CTRL) {
				event.key.mods |= ez::KeyMod::Ctrl;
			}
			if (ev.key.keysym.mod & KMOD_ALT) {
				event.key.mods |= ez::KeyMod::Alt;
			}
			if (ev.key.keysym.mod & KMOD_SHIFT) {
				event.key.mods |= ez::KeyMod::Shift;
			}
			if (ev.key.keysym.mod & KMOD_GUI) {
				event.key.mods |= ez::KeyMod::System;
			}
			return event;

		case SDL_KEYUP:
			event.type = ez::InEv::KeyRelease;
			event.key.code = (remapSDLKey(ev.key.keysym.sym));
			if (ev.key.keysym.mod & KMOD_CTRL) {
				event.key.mods |= ez::KeyMod::Ctrl;
			}
			if (ev.key.keysym.mod & KMOD_ALT) {
				event.key.mods |= ez::KeyMod::Alt;
			}
			if (ev.key.keysym.mod & KMOD_SHIFT) {
				event.key.mods |= ez::KeyMod::Shift;
			}
			if (ev.key.keysym.mod & KMOD_GUI) {
				event.key.mods |= ez::KeyMod::System;
			}
			return event;

		case SDL_JOYAXISMOTION:
			event.type = ez::InEv::None;
			return event;

		case SDL_JOYBALLMOTION:
			event.type = ez::InEv::None;
			return event;

		case SDL_JOYHATMOTION:
			event.type = ez::InEv::None;
			return event;

		case SDL_JOYBUTTONDOWN:
			event.type = ez::InEv::None;
			return event;

		case SDL_JOYBUTTONUP:
			event.type = ez::InEv::None;
			return event;

		case SDL_JOYDEVICEADDED:
			event.type = ez::InEv::None;
			return event;

		case SDL_JOYDEVICEREMOVED:
			event.type = ez::InEv::None;
			return event;

		case SDL_QUIT:
			event.type = InputEventType::Closed;
			return event;

		case SDL_TEXTINPUT: {
			event.type = InputEventType::Char;

			std::size_t len = 0;
			{
				const char* tmp = ev.text.text;
				while (*tmp != '\0') {
					++len;
					++tmp;
				}
			}

			event.setCodepointFromUTF8(std::string_view(ev.text.text, len));
			return event;
		}
		case SDL_WINDOWEVENT: {
			switch (ev.window.event) {
			case SDL_WINDOWEVENT_RESIZED:
				/// Ignore this event, size_changed event always comes first!
				//event.type = ez::InEv::Resized;
				//event.size = glm::ivec2{ ev.window.data1, ev.window.data2 };
				break;
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				event.type = ez::InEv::Resized;
				event.size = glm::ivec2{ ev.window.data1, ev.window.data2 };
				break;
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				event.type = ez::InEv::FocusGained;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				event.type = ez::InEv::FocusLost;
				break;
			case SDL_WINDOWEVENT_ENTER:
				event.type = ez::InEv::MouseEnter;
				break;
			case SDL_WINDOWEVENT_LEAVE:
				event.type = ez::InEv::MouseLeave;
				break;
			case SDL_WINDOWEVENT_CLOSE:
				event.type = ez::InEv::Closed;
				break;
			case SDL_WINDOWEVENT_MINIMIZED:
				event.type = ez::InEv::Minimized;
				break;
			case SDL_WINDOWEVENT_MAXIMIZED:
				event.type = ez::InEv::Maximized;
				break;
			case SDL_WINDOWEVENT_SHOWN:
				event.type = ez::InEv::Shown;
				break;
			case SDL_WINDOWEVENT_HIDDEN:
				event.type = ez::InEv::Hidden;
				break;
			case SDL_WINDOWEVENT_EXPOSED:
				event.type = ez::InEv::Exposed;
				break;
			case SDL_WINDOWEVENT_RESTORED:
			case SDL_WINDOWEVENT_TAKE_FOCUS:
			case SDL_WINDOWEVENT_HIT_TEST:
			case SDL_WINDOWEVENT_MOVED:
			default:
				break;
			}
			return event;
		}
		default:
			return event;
		}
	}
};