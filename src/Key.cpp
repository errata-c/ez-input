#include <ez/input/Key.hpp>
#include <ostream>
#include <algorithm>
#include <array>

namespace ez {

	KeyEvent::KeyEvent() noexcept
		: code(Key::None)
		, mods(KeyMods::None)
	{}
	KeyEvent::KeyEvent(Key _code) noexcept
		: code(_code)
		, mods(KeyMods::None)
	{}
	KeyEvent::KeyEvent(KeyMods _mods, Key _code) noexcept
		: code(_code)
		, mods(_mods)
	{}

	bool KeyEvent::isModifier() const noexcept {
		Key val = code;
		return (int)val >= (int)Key::LShift && (int)val <= (int)Key::RSystem;
	}

	std::uint32_t KeyEvent::getRawValue() const noexcept {
		return (mods.rawValue() << 28) | static_cast<std::uint32_t>(code);
	}

	KeyState::KeyState() noexcept
		: justPressed(Key::None)
		, justReleased(Key::None)
		, held(Key::None)
		, mods(KeyMods::None)
	{}

	void KeyState::reset() noexcept {
		justPressed = Key::None;
		justReleased = Key::None;
		held = Key::None;
		mods = KeyMods::None;
	}
};

template<std::size_t N>
std::string_view makeView(const char (&arr)[N]) {
	return std::string_view{arr, N-1};
}


std::string ez::to_string(ez::KeyEvent ev) {
	std::string modStr = ez::to_string(ev.mods);

	std::array<std::string_view, 5> text{
		makeView("{ mods: "),
		modStr,
		makeView(", code: "),
		ez::to_string_view(ev.code),
		makeView(" }")
	};

	std::size_t total = 0;
	for (std::string_view view : text) {
		total += view.length();
	}

	std::string ret(total, '\0');

	std::string::iterator write = ret.begin();

	for (std::string_view view : text) {
		write = std::copy(view.begin(), view.end(), write);
	}

	return ret;
}

std::string ez::to_string(ez::KeyState state) {
	std::string modStr = ez::to_string(state.mods);

	std::array<std::string_view, 9> text{
		makeView("{ held: "),
		ez::to_string_view(state.held),
		makeView(", justPressed: "),
		ez::to_string_view(state.justPressed),
		makeView(", justReleased: "),
		ez::to_string_view(state.justReleased),
		makeView(", mods: "),
		modStr,
		makeView(" }")
	};
	std::size_t total = 0;
	for (std::string_view view : text) {
		total += view.length();
	}

	std::string ret(total, '\0');

	std::string::iterator write = ret.begin();

	for (std::string_view view : text) {
		write = std::copy(view.begin(), view.end(), write);
	}

	return ret;
}

std::ostream& ez::operator<<(std::ostream& os, const ez::KeyEvent & val) {
	os << ez::to_string(val);
	return os;
}
std::ostream& ez::operator<<(std::ostream& os, const ez::KeyState & val) {
	os << ez::to_string(val);
	return os;
}