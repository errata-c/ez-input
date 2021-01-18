#include <ez/input/Mouse.hpp>
#include <ostream>
#include <array>
#include <cstdio>
#include <algorithm>

constexpr int buttonMask = 0xFF;

ez::MouseButtons(operator|)(ez::MouseButtons lh, ez::MouseButtons rh) noexcept {
	lh.buttons = lh.buttons | rh.buttons;
	return lh;
}
ez::MouseButtons(operator&)(ez::MouseButtons lh, ez::MouseButtons rh) noexcept {
	lh.buttons = lh.buttons & rh.buttons;
	return lh;
}
ez::MouseButtons(operator^)(ez::MouseButtons lh, ez::MouseButtons rh) noexcept {
	lh.buttons = lh.buttons ^ rh.buttons;
	lh.buttons &= buttonMask;
	return lh;
}
ez::MouseButtons(operator~)(ez::MouseButtons lh) noexcept {
	lh.buttons = (~lh.buttons) & buttonMask;
	return lh;
}

ez::MouseButtons(operator|)(ez::Mouse lh, ez::Mouse rh) noexcept {
	return ez::MouseButtons(lh) | ez::MouseButtons(rh);
}
ez::MouseButtons(operator&)(ez::Mouse lh, ez::Mouse rh) noexcept {
	return ez::MouseButtons(lh) & ez::MouseButtons(rh);
}
ez::MouseButtons(operator^)(ez::Mouse lh, ez::Mouse rh) noexcept {
	return ez::MouseButtons(lh) ^ ez::MouseButtons(rh);
}
ez::MouseButtons(operator~)(ez::Mouse lh) noexcept {
	return ez::MouseButtons(lh);
}

namespace ez {
	MouseButtons::MouseButtons() noexcept
		: buttons(0)
	{}

	MouseButtons::MouseButtons(Mouse button) noexcept
		: buttons(1 << static_cast<int>(button))
	{}

	bool MouseButtons::isPressed(Mouse button) const noexcept {
		return (buttons & (1 << static_cast<int>(button))) != 0;
	}
	bool MouseButtons::isReleased(Mouse button) const noexcept {
		return (buttons & (1 << static_cast<int>(button))) == 0;
	}

	void MouseButtons::clear() noexcept {
		buttons = 0;
	}

	void MouseButtons::press(Mouse button) noexcept {
		buttons |= 1 << static_cast<int>(button);
	}
	void MouseButtons::release(Mouse button) noexcept {
		buttons &= ~(1 << static_cast<int>(button));
	}

	int MouseButtons::numPressed() const noexcept {
		int tmp = buttons;
		tmp = ((tmp & 0xAAAA) >> 1) + (tmp & 0x5555);
		tmp = ((tmp & 0xCCCC) >> 2) + (tmp & 0x3333);
		tmp = ((tmp & 0xF0F0) >> 4) + (tmp & 0x0F0F);
		tmp = ((tmp & 0xFF00) >> 8) + (tmp & 0x00FF);

		return tmp;
	}
	int MouseButtons::numReleased() const noexcept {
		return 16 - numPressed();
	}

	bool MouseButtons::operator==(MouseButtons other) const noexcept {
		return buttons == other.buttons;
	}
	bool MouseButtons::operator!=(MouseButtons other) const noexcept {
		return buttons != other.buttons;
	}

	Mouse MouseButtons::lowestPressed() const noexcept {
		for (int i = 0; i < 16; ++i) {
			if (buttons & (1 << i)) {
				return static_cast<Mouse>(i);
			}
		}
		return Mouse::None;
	}
	Mouse MouseButtons::highestPressed() const noexcept {
		for (int i = 15; i > -1; --i) {
			if (buttons & (1 << i)) {
				return static_cast<Mouse>(i);
			}
		}
		return Mouse::None;
	}

	ez::MouseButtons& ez::MouseButtons::operator|=(ez::MouseButtons lh) noexcept {
		*this = *this | lh;
		return *this;
	}
	ez::MouseButtons& ez::MouseButtons::operator&=(ez::MouseButtons lh) noexcept {
		*this = *this & lh;
		return *this;
	}
	ez::MouseButtons& ez::MouseButtons::operator^=(ez::MouseButtons lh) noexcept {
		*this = *this ^ lh;
		return *this;
	}
};

template<std::size_t N>
std::string_view makeView(const char(&arr)[N]) {
	return std::string_view{ arr, N - 1 };
}

template<typename Iterator>
Iterator writeButtons(Iterator it, ez::MouseButtons buttons) {
	int pos = 0;
	for (int j = 0; j < 4; ++j) {
		if (buttons.isPressed(static_cast<ez::Mouse>(pos))) {
			*it = '1';
		}
		else {
			*it = '0';
		}
		++pos;
		++it;
	}

	//Formats into groups of 4 bits, like so: 0000'0000'0000'0000
	for (int i = 1; i < 4; ++i) {
		*it = '\'';
		++it;

		for (int j = 0; j < 4; ++j) {
			if (buttons.isPressed(static_cast<ez::Mouse>(pos))) {
				*it = '1';
			}
			else {
				*it = '0';
			}
			++pos;
			++it;
		}
	}
	return it;
}

std::string ez::to_string(ez::MouseButtons buttons) {
	std::string result(19, '\0');
	std::string::iterator it = result.begin();
	it = writeButtons(it, buttons);

	return result;
}

std::string ez::to_string(const ez::MouseEvent& val) {
	char xpos[16], ypos[16];
	xpos[15] = '\0';
	ypos[15] = '\0';

	std::array<std::string_view, 7> text{
		makeView("{ button: "),
		ez::to_string_view(val.button),
		makeView(", position: [ "),
		std::string_view(xpos, std::min(15, snprintf(xpos, 16, "%.6g", val.position.x))),
		makeView(", "),
		std::string_view(ypos, std::min(15, snprintf(ypos, 16, "%.6g", val.position.y))),
		makeView(" ] }")
	};

	std::size_t len = 0;
	for (std::string_view view : text) {
		len += view.length();
	}

	std::string result(len, '\0');
	std::string::iterator it = result.begin();
	for (const std::string_view & view: text) {
		it = std::copy(view.begin(), view.end(), it);
	}

	return result;
}

std::string ez::to_string(const ez::MouseState& val) {
	char xpos[16], ypos[16];
	xpos[15] = '\0';
	ypos[15] = '\0';

	std::string buttons = ez::to_string(val.buttons);

	std::array<std::string_view, 12> text{
		makeView("{ buttons: "),
		std::string_view(buttons),
		makeView(", justPressed: "),
		ez::to_string_view(val.justPressed),
		makeView(", justReleased: "),
		ez::to_string_view(val.justReleased),
		makeView(", position: [ "),
		std::string_view(xpos, std::min(15, snprintf(xpos, 16, "%.6g", val.position.x))),
		makeView(", "),
		std::string_view(ypos, std::min(15, snprintf(ypos, 16, "%.6g", val.position.y))),
		makeView(" ] }")
	};

	std::size_t len = 0;
	for (std::string_view view : text) {
		len += view.length();
	}

	std::string result(len, '\0');
	std::string::iterator it = result.begin();
	for (const std::string_view& view : text) {
		it = std::copy(view.begin(), view.end(), it);
	}

	return result;
}

std::ostream& ez::operator<<(std::ostream& os, ez::MouseButtons val) {
	char text[19];
	writeButtons(text, val);
	os.write(text, 19);

	return os;
}

std::ostream& ez::operator<<(std::ostream& os, const ez::MouseEvent& val) {
	os << ez::to_string(val);
	return os;
}

std::ostream& ez::operator<<(std::ostream& os, const ez::MouseState& val) {
	os << ez::to_string(val);
	return os;
}
