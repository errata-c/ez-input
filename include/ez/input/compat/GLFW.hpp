#pragma once
#include <ez/input/Key.hpp>
#include <GLFW/glfw3.h>

namespace ez {
	inline Key remapGLFWKeycode(int32_t code) {
		switch (code) {
		case GLFW_KEY_UNKNOWN:
			return Key::Unknown;

		case GLFW_KEY_0:
		case GLFW_KEY_1:
		case GLFW_KEY_2:
		case GLFW_KEY_3:
		case GLFW_KEY_4:
		case GLFW_KEY_5:
		case GLFW_KEY_6:
		case GLFW_KEY_7:
		case GLFW_KEY_8:
		case GLFW_KEY_9:
			return (Key)((code - GLFW_KEY_0) + (int)Key::N0);

		case GLFW_KEY_A:
		case GLFW_KEY_B:
		case GLFW_KEY_C:
		case GLFW_KEY_D:
		case GLFW_KEY_E:
		case GLFW_KEY_F:
		case GLFW_KEY_G:
		case GLFW_KEY_H:
		case GLFW_KEY_I:
		case GLFW_KEY_J:
		case GLFW_KEY_K:
		case GLFW_KEY_L:
		case GLFW_KEY_M:
		case GLFW_KEY_N:
		case GLFW_KEY_O:
		case GLFW_KEY_P:
		case GLFW_KEY_Q:
		case GLFW_KEY_R:
		case GLFW_KEY_S:
		case GLFW_KEY_T:
		case GLFW_KEY_U:
		case GLFW_KEY_V:
		case GLFW_KEY_W:
		case GLFW_KEY_X:
		case GLFW_KEY_Y:
		case GLFW_KEY_Z:
			return (Key)((code - GLFW_KEY_A) + (int)Key::A);

		case GLFW_KEY_F1:
		case GLFW_KEY_F2:
		case GLFW_KEY_F3:
		case GLFW_KEY_F4:
		case GLFW_KEY_F5:
		case GLFW_KEY_F6:
		case GLFW_KEY_F7:
		case GLFW_KEY_F8:
		case GLFW_KEY_F9:
		case GLFW_KEY_F10:
		case GLFW_KEY_F11:
		case GLFW_KEY_F12:
		case GLFW_KEY_F13:
		case GLFW_KEY_F14:
		case GLFW_KEY_F15:
		case GLFW_KEY_F16:
		case GLFW_KEY_F17:
		case GLFW_KEY_F18:
		case GLFW_KEY_F19:
		case GLFW_KEY_F20:
		case GLFW_KEY_F21:
		case GLFW_KEY_F22:
		case GLFW_KEY_F23:
		case GLFW_KEY_F24:
		case GLFW_KEY_F25:
			return (Key)((code - GLFW_KEY_F1) + (int)Key::F1);

		case GLFW_KEY_KP_0:
		case GLFW_KEY_KP_1:
		case GLFW_KEY_KP_2:
		case GLFW_KEY_KP_3:
		case GLFW_KEY_KP_4:
		case GLFW_KEY_KP_5:
		case GLFW_KEY_KP_6:
		case GLFW_KEY_KP_7:
		case GLFW_KEY_KP_8:
		case GLFW_KEY_KP_9:
			return (Key)((code - GLFW_KEY_KP_0) + (int)Key::KP0);
		
		case GLFW_KEY_SPACE:
			return Key::Space;
		case GLFW_KEY_APOSTROPHE:
			return Key::Quote;
		case GLFW_KEY_COMMA:
			return Key::Comma;
		case GLFW_KEY_MINUS:
			return Key::Minus;
		case GLFW_KEY_PERIOD:
			return Key::Period;
		case GLFW_KEY_SLASH:
			return Key::FSlash;
		case GLFW_KEY_SEMICOLON:
			return Key::Semicolon;
		case GLFW_KEY_EQUAL:
			return Key::Equal;
		case GLFW_KEY_LEFT_BRACKET:
			return Key::LBracket;
		case GLFW_KEY_RIGHT_BRACKET:
			return Key::RBracket;
		case GLFW_KEY_BACKSLASH:
			return Key::BSlash;
		case GLFW_KEY_GRAVE_ACCENT:
			return Key::Tilde;
		case GLFW_KEY_ESCAPE:
			return Key::Escape;
		case GLFW_KEY_ENTER:
			return Key::Enter;
		case GLFW_KEY_TAB:
			return Key::Tab;
		case GLFW_KEY_BACKSPACE:
			return Key::Backspace;
		case GLFW_KEY_INSERT:
			return Key::Insert;
		case GLFW_KEY_DELETE:
			return Key::Delete;
		case GLFW_KEY_RIGHT:
			return Key::Right;
		case GLFW_KEY_LEFT:
			return Key::Left;
		case GLFW_KEY_UP:
			return Key::Up;
		case GLFW_KEY_DOWN:
			return Key::Down;
		case GLFW_KEY_PAGE_UP:
			return Key::PageUp;
		case GLFW_KEY_PAGE_DOWN:
			return Key::PageDown;
		case GLFW_KEY_HOME:
			return Key::Home;
		case GLFW_KEY_END:
			return Key::End;
		case GLFW_KEY_CAPS_LOCK:
			return Key::CapsLock;
		case GLFW_KEY_SCROLL_LOCK:
			return Key::ScrollLock;
		case GLFW_KEY_NUM_LOCK:
			return Key::NumLock;
		case GLFW_KEY_PRINT_SCREEN:
			return Key::PrintScreen;
		case GLFW_KEY_PAUSE:
			return Key::Pause;

		case GLFW_KEY_KP_DECIMAL:
			return Key::KPDecimal;
		case GLFW_KEY_KP_DIVIDE:
			return Key::KPDivide;
		case GLFW_KEY_KP_MULTIPLY:
			return Key::KPMultiply;
		case GLFW_KEY_KP_SUBTRACT:
			return Key::KPSubtract;
		case GLFW_KEY_KP_ADD:
			return Key::KPAdd;
		case GLFW_KEY_KP_ENTER:
			return Key::KPEnter;

		case GLFW_KEY_LEFT_SHIFT:
			return Key::LShift;
		case GLFW_KEY_RIGHT_SHIFT:
			return Key::RShift;
		case GLFW_KEY_LEFT_ALT:
			return Key::LAlt;
		case GLFW_KEY_RIGHT_ALT:
			return Key::RAlt;
		case GLFW_KEY_LEFT_CONTROL:
			return Key::LCtrl;
		case GLFW_KEY_RIGHT_CONTROL:
			return Key::RCtrl;
		case GLFW_KEY_LEFT_SUPER:
			return Key::LSystem;
		case GLFW_KEY_RIGHT_SUPER:
			return Key::RSystem;

		default:
			return Key::Unknown;
		}
	}

	static InputEvent remapGLFWCursor(double xpos, double ypos) {
		InputEvent event;
		event.type = InputEventType::MouseMove;
		event.mouse = MouseData{};
		event.mouse.position = glm::dvec2{ xpos, ypos };
		return event;
	}

	static InputEvent remapGLFWKey(int key, int scancode, int action, int mods) {
		InputEvent event;
		switch (action) {
		case GLFW_PRESS:
		case GLFW_REPEAT:
			event.type = InputEventType::KeyPress;
			break;
		default:
			event.type = InputEventType::KeyRelease;
			break;
		}
		
		event.key = KeyEvent{};
		event.key.setKey(remapGLFWKeycode(key));
		event.key.setShift((mods & GLFW_MOD_SHIFT) > 0);
		event.key.setCtrl((mods & GLFW_MOD_CONTROL) > 0);
		event.key.setAlt((mods & GLFW_MOD_ALT) > 0);
		event.key.setSystem((mods & GLFW_MOD_SUPER) > 0);

		return event;
	}

	static InputEvent remapGLFWResize(int w, int h) {
		InputEvent event;
		event.type = InputEventType::Resized;
		event.size = glm::ivec2{ w, h };
		return event;
	}

	static InputEvent remapGLFWFocus(int focus) {
		InputEvent event;
		if (focus == GLFW_TRUE) {
			event.type = InputEventType::GainedFocus;
		}
		else {
			event.type = InputEventType::LostFocus;
		}
		return event;
	}

	static InputEvent remapGLFWEnterLeave(int entered) {
		InputEvent event;
		if (entered) {
			event.type = InputEventType::MouseEnter;
		}
		else {
			event.type = InputEventType::MouseLeave;
		}
		event.mouse = Mouse{};
		return event;
	}
	
	static InputEvent remapGLFWMouseButton(GLFWwindow* window, int button, int action, int mods) {
		InputEvent event;
		if (action == GLFW_PRESS) {
			event.type = InputEventType::MousePress;
		}
		else {
			event.type = InputEventType::MouseRelease;
		}
		event.mouse = MouseData{};
		glfwGetCursorPos(window, &event.mouse.position.x, &event.mouse.position.y);
		switch (button) {
		case GLFW_MOUSE_BUTTON_LEFT:
			event.mouse.setButtons(Mouse::Left);
			break;
		case GLFW_MOUSE_BUTTON_RIGHT:
			event.mouse.setButtons(Mouse::Right);
			break;
		case GLFW_MOUSE_BUTTON_MIDDLE:
			event.mouse.setButtons(Mouse::Middle);
			break;
		case GLFW_MOUSE_BUTTON_4:
			event.mouse.setButtons(Mouse::Button4);
			break;
		case GLFW_MOUSE_BUTTON_5:
			event.mouse.setButtons(Mouse::Button5);
			break;
		case GLFW_MOUSE_BUTTON_6:
			event.mouse.setButtons(Mouse::Button6);
			break;
		case GLFW_MOUSE_BUTTON_7:
			event.mouse.setButtons(Mouse::Button7);
			break;
		case GLFW_MOUSE_BUTTON_8:
			event.mouse.setButtons(Mouse::Button8);
			break;
		}
		
		return event;
	}

	static InputEvent remapGLFWScroll(double xoffset, double yoffset) {
		InputEvent event;
		event.type = InputEventType::Scroll;
		event.scroll = glm::dvec2{ xoffset, yoffset };
		return event;
	}

	static InputEvent remapGLFWChar(unsigned int codepoint) {
		InputEvent event;
		event.type = InputEventType::Char;
		event.codepoint = codepoint;
		return event;
	}
};