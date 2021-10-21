#include <ez/input/InputEvent.hpp>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

#include <utf8cpp/utf8.h>

template<std::size_t N>
std::string_view makeView(const char(&arr)[N]) {
	return std::string_view(arr, N-1);
}

namespace ez {
	InputEvent::InputEvent() noexcept
		: type(InEv::None)
	{
		std::memset(data, 0, sizeof(data));
	}

	InputEvent::InputEvent(InEv t, Key k) noexcept
		: InputEvent()
	{
		type = t;
		key = k;
	}

	InputEvent::InputEvent(InEv t, Mouse m) noexcept
		: type(t)
		, mouse(m)
	{}

	InputEvent::InputEvent(InEv t, uint32_t unicode) noexcept
		: InputEvent()
	{
		type = t;
		codepoint = unicode;
	}

	InputEvent::InputEvent(InEv t, glm::dvec2 delta) noexcept
		: InputEvent()
	{
		type = t;
		scroll = delta;
	}

	InputEvent::InputEvent(const InputEvent& other) noexcept
	{
		type = other.type;
		std::memcpy(data, other.data, sizeof(data));
	}

	InputEvent::~InputEvent() {
		// Have to declare the destructor because of the union.
	}

	InputEvent& InputEvent::operator=(const InputEvent& other) noexcept {
		type = other.type;
		std::memcpy(data, other.data, sizeof(data));
		return *this;
	}

	bool InputEvent::setCodepointFromUTF8(std::string_view str8) {
		const char * first = str8.data();
		const char * last = first + str8.size();

		if (utf8::is_valid(first, last)) {
			uint32_t result;
			utf8::utf8to32(first, last, &result);

			codepoint = result;
			return true;
		}
		else {
			return false;
		}
	}

	std::string InputEvent::to_string() const {
		return ez::to_string(*this);
	}

	template<std::size_t N>
	std::ostream& staticWrite(std::ostream& os, const char(&arr)[N]) {
		os.write(arr, N - 1);
		return os;
	}

	std::string to_string(const InputEvent & val) {
		std::stringstream ss;
		staticWrite(ss, "{ type: ");
		ss << val.type;
		switch (val.type) {
		case InEv::Char:
			staticWrite(ss, ", codepoint: ");
			if (val.codepoint <= 127) {
				ss << static_cast<char>(val.codepoint);
			}
			else {
				ss << std::hex << val.codepoint << std::dec;
			}
			
			break;
		
		case InEv::KeyPress:
		case InEv::KeyRelease:
		case InEv::KeyRepeat:
			staticWrite(ss, ", key: ");
			ss << val.key;
			break;

		case InEv::MouseClick:
		case InEv::MouseClick2:
		case InEv::MousePress:
		case InEv::MouseRelease:
		case InEv::MouseMove:
			staticWrite(ss, ", mouse: ");
			ss << val.mouse;
			break;

		case InEv::Resized: {
			char xpos[16], ypos[16];
			staticWrite(ss, ", size: [");
			ss.write(xpos, std::min(15, snprintf(xpos, 16, "%d", val.size.x)));
			staticWrite(ss, ", ");
			ss.write(xpos, std::min(15, snprintf(ypos, 16, "%d", val.size.y)));
			staticWrite(ss, "]");
			break;
		}
		case InEv::Scroll: {
			char xpos[16], ypos[16];
			staticWrite(ss, ", scroll: [");
			ss.write(xpos, std::min(15, snprintf(xpos, 16, "%.6g", val.scroll.x)));
			staticWrite(ss, ", ");
			ss.write(xpos, std::min(15, snprintf(ypos, 16, "%.6g", val.scroll.y)));
			staticWrite(ss, "]");
			break;
		}
		case InEv::TouchMove:
			break;
		case InEv::TouchPress:
			break;
		case InEv::TouchRelease:
			break;

		case InEv::MouseEnter:
		case InEv::MouseLeave:
		case InEv::Maximized:
		case InEv::Minimized:
		case InEv::Shown:
		case InEv::Closed:
		case InEv::ControllerConnect:
		case InEv::ControllerDisconnect:
			break;
		case InEv::ControllerMove:
			break;
		case InEv::ControllerPress:
			break;
		case InEv::ControllerRelease:
			break;
		case InEv::FocusGained:
			break;
		case InEv::FocusLost:
			break;
		case InEv::Hidden:
			break;

		default:
			break;
		}

		staticWrite(ss, " }");
		return ss.str();
	}

	std::ostream& operator<<(std::ostream& os, const InputEvent& val) {
		os << ez::to_string(val);
		return os;
	}
};

