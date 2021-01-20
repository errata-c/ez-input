#include <ez/input/intern/enumerations.hpp>
#include <ostream>

template<std::size_t N>
std::string_view makeView(const char(&arr)[N]) {
	return std::string_view{ arr, N - 1 };
}

namespace ez {
	std::string_view to_string_view(ez::Key code) noexcept {
		using Key = ez::Key;
		switch (code) {
		case Key::A:
			return makeView("A");;

		case Key::B:
			return makeView("B");

		case Key::C:
			return makeView("C");

		case Key::D:
			return makeView("D");

		case Key::E:
			return makeView("E");

		case Key::F:
			return makeView("F");

		case Key::G:
			return makeView("G");

		case Key::H:
			return makeView("H");

		case Key::I:
			return makeView("I");

		case Key::J:
			return makeView("J");

		case Key::K:
			return makeView("K");

		case Key::L:
			return makeView("L");

		case Key::M:
			return makeView("M");

		case Key::N:
			return makeView("N");

		case Key::O:
			return makeView("O");

		case Key::P:
			return makeView("P");

		case Key::Q:
			return makeView("Q");

		case Key::R:
			return makeView("R");

		case Key::S:
			return makeView("S");

		case Key::T:
			return makeView("T");

		case Key::U:
			return makeView("U");

		case Key::V:
			return makeView("V");

		case Key::W:
			return makeView("W");

		case Key::X:
			return makeView("X");

		case Key::Y:
			return makeView("Y");

		case Key::Z:
			return makeView("Z");


		case Key::N0:
			return makeView("N0");

		case Key::N1:
			return makeView("N1");

		case Key::N2:
			return makeView("N2");

		case Key::N3:
			return makeView("N3");

		case Key::N4:
			return makeView("N4");

		case Key::N5:
			return makeView("N5");

		case Key::N6:
			return makeView("N6");

		case Key::N7:
			return makeView("N7");

		case Key::N8:
			return makeView("N8");

		case Key::N9:
			return makeView("N9");


		case Key::KP0:
			return makeView("KP0");

		case Key::KP1:
			return makeView("KP1");

		case Key::KP2:
			return makeView("KP2");

		case Key::KP3:
			return makeView("KP3");

		case Key::KP4:
			return makeView("KP4");

		case Key::KP5:
			return makeView("KP5");

		case Key::KP6:
			return makeView("KP6");

		case Key::KP7:
			return makeView("KP7");

		case Key::KP8:
			return makeView("KP8");

		case Key::KP9:
			return makeView("KP9");


		case Key::Hyphen:
			return makeView("Hyphen");

		case Key::Tilde:
			return makeView("Tilde");

		case Key::Enter:
			return makeView("Enter");

		case Key::Tab:
			return makeView("Tab");

		case Key::Equal:
			return makeView("Equal");

		case Key::Space:
			return makeView("Space");

		case Key::Comma:
			return makeView("Comma");

		case Key::Period:
			return makeView("Period");

		case Key::Quote:
			return makeView("Quote");

		case Key::FSlash:
			return makeView("FSlash");

		case Key::BSlash:
			return makeView("BSlash");

		case Key::Semicolon:
			return makeView("Semicolon");

		case Key::LBracket:
			return makeView("LBracket");

		case Key::RBracket:
			return makeView("RBracket");


		case Key::Insert:
			return makeView("Insert");

		case Key::Backspace:
			return makeView("Backspace");


		case Key::LShift:
			return makeView("LShift");

		case Key::RShift:
			return makeView("RShift");

		case Key::RCtrl:
			return makeView("RCtrl");

		case Key::LCtrl:
			return makeView("LCtrl");

		case Key::LAlt:
			return makeView("LAlt");

		case Key::RAlt:
			return makeView("RAlt");

		case Key::LSystem:
			return makeView("LSystem");

		case Key::RSystem:
			return makeView("RSystem");


		case Key::Pause:
			return makeView("Pause");

		case Key::PageUp:
			return makeView("PageUp");

		case Key::PageDown:
			return makeView("PageDown");

		case Key::PrintScreen:
			return makeView("PrintScreen");

		case Key::SysReq:
			return makeView("SysReq");


		case Key::NumLock:
			return makeView("NumLock");

		case Key::CapsLock:
			return makeView("CapsLock");

		case Key::ScrollLock:
			return makeView("ScrollLock");


		case Key::End:
			return makeView("End");

		case Key::Home:
			return makeView("Home");

		case Key::Escape:
			return makeView("Escape");

		case Key::Delete:
			return makeView("Delete");


		case Key::Up:
			return makeView("Up");

		case Key::Left:
			return makeView("Left");

		case Key::Right:
			return makeView("Right");

		case Key::Down:
			return makeView("Down");


		case Key::KPDivide:
			return makeView("KPDivide");

		case Key::KPMultiply:
			return makeView("KPMultiply");

		case Key::KPAdd:
			return makeView("KPAdd");

		case Key::KPSubtract:
			return makeView("KPSubtract");

		case Key::KPEnter:
			return makeView("KPEnter");

		case Key::KPDecimal:
			return makeView("KPDecimal");

		case Key::KPEqual:
			return makeView("KPEqual");


		case Key::F1:
			return makeView("F1");

		case Key::F2:
			return makeView("F2");

		case Key::F3:
			return makeView("F3");

		case Key::F4:
			return makeView("F4");

		case Key::F5:
			return makeView("F5");

		case Key::F6:
			return makeView("F6");

		case Key::F7:
			return makeView("F7");

		case Key::F8:
			return makeView("F8");

		case Key::F9:
			return makeView("F9");

		case Key::F10:
			return makeView("F10");

		case Key::F11:
			return makeView("F11");

		case Key::F12:
			return makeView("F12");

		case Key::F13:
			return makeView("F13");

		case Key::F14:
			return makeView("F14");

		case Key::F15:
			return makeView("F15");

		case Key::F17:
			return makeView("F17");

		case Key::F18:
			return makeView("F18");

		case Key::F19:
			return makeView("F19");

		case Key::F20:
			return makeView("F20");

		case Key::F21:
			return makeView("F21");

		case Key::F22:
			return makeView("F22");

		case Key::F23:
			return makeView("F23");

		case Key::F24:
			return makeView("F24");

		case Key::F25:
			return makeView("F25");

		default:
			return makeView("Unknown");

		};
	}
	
	std::string to_string(ez::Key code) {
		return std::string{ ez::to_string_view(code) };
	}
	
	std::ostream& operator<<(std::ostream& os, ez::Key val) noexcept {
		os << to_string_view(val);
		return os;
	}

	std::string_view to_string_view(ez::KeyMod mod) noexcept {
		switch (mod) {
		case KeyMod::Ctrl:
			return makeView("Ctrl");
		case KeyMod::Alt:
			return makeView("Alt");
		case KeyMod::Shift:
			return makeView("Shift");
		case KeyMod::System:
			return makeView("System");
		default:
			return makeView("None");
		}
	}

	std::string to_string(ez::KeyMod mod) {
		return std::string{ ez::to_string_view(mod) };
	}

	std::ostream& operator<<(std::ostream& os, ez::KeyMod mod) noexcept {
		os << to_string_view(mod);
		return os;
	}

	std::string_view to_string_view(ez::InEv type) noexcept {
		using ez::InEv;

		switch (type) {
		case InEv::MouseMove:
			return makeView("MouseMove");

		case InEv::MousePress:
			return makeView("MousePress");

		case InEv::MouseRelease:
			return makeView("MouseRelease");

		case InEv::MouseClick:
			return makeView("MouseClick");

		case InEv::MouseClick2:
			return makeView("MouseClick2");

		case InEv::KeyPress:
			return makeView("KeyPress");

		case InEv::KeyRelease:
			return makeView("KeyRelease");

		case InEv::MouseEnter:
			return makeView("MouseEnter");

		case InEv::MouseLeave:
			return makeView("MouseLeave");

		case InEv::Scroll:
			return makeView("Scroll");

		case InEv::Char:
			return makeView("Char");

		case InEv::TouchPress:
			return makeView("TouchPress");

		case InEv::TouchRelease:
			return makeView("TouchRelease");

		case InEv::TouchMove:
			return makeView("TouchMove");

		case InEv::ControllerPress:
			return makeView("ControllerPress");

		case InEv::ControllerRelease:
			return makeView("ControllerRelease");

		case InEv::ControllerMove:
			return makeView("ControllerMove");

		case InEv::ControllerConnect:
			return makeView("ControllerConnect");

		case InEv::ControllerDisconnect:
			return makeView("ControllerDisconnect");

		case InEv::FocusGained:
			return makeView("FocusGained");

		case InEv::FocusLost:
			return makeView("FocusLost");

		case InEv::Closed:
			return makeView("Closed");

		case InEv::Hidden:
			return makeView("Hidden");

		case InEv::Shown:
			return makeView("Shown");

		case InEv::Maximized:
			return makeView("Maximized");

		case InEv::Minimized:
			return makeView("Minimized");

		default:
			return makeView("None");
		}
	}

	std::ostream& operator<<(std::ostream& os, ez::InEv ev) noexcept {
		os << to_string_view(ev);
		return os;
	}

	std::string to_string(ez::InEv event) {
		return std::string{ to_string_view(event) };
	}


	std::string_view to_string_view(Mouse button) noexcept {
		switch (button) {
		case Mouse::Left:
			return makeView("Left");
		case Mouse::Right:
			return makeView("Right");
		case Mouse::Middle:
			return makeView("Middle");
		case Mouse::Button4:
			return makeView("Button4");
		case Mouse::Button5:
			return makeView("Button5");
		case Mouse::Button6:
			return makeView("Button6");
		case Mouse::Button7:
			return makeView("Button7");
		case Mouse::Button8:
			return makeView("Button8");
		case Mouse::Button9:
			return makeView("Button9");
		case Mouse::Button10:
			return makeView("Button10");
		case Mouse::Button11:
			return makeView("Button11");
		case Mouse::Button12:
			return makeView("Button12");
		case Mouse::Button13:
			return makeView("Button13");
		case Mouse::Button14:
			return makeView("Button14");
		case Mouse::Button15:
			return makeView("Button15");
		case Mouse::Button16:
			return makeView("Button16");
		default:
			return makeView("None");
		}
	}

	std::string to_string(ez::Mouse button) {
		return std::string{ to_string_view(button) };
	}

	std::ostream& operator<<(std::ostream& os, ez::Mouse button) noexcept {
		os << to_string_view(button);
		return os;
	}

};