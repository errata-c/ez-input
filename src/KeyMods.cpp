#include <ez/input/KeyMods.hpp>
#include <ostream>
#include <sstream>

namespace ez {
	void KeyMods::press(KeyMods mod) noexcept {
		*this |= mod;
	}
	void KeyMods::release(KeyMods mod) noexcept {
		*this &= ~mod;
	}

	bool KeyMods::isPressed(KeyMods mod) const noexcept {
		return allOf(mod);
	}
	bool KeyMods::isReleased(KeyMods mod) const noexcept {
		return noneOf(mod);
	}

	// Check if ANY of the input modifiers are held.
	bool KeyMods::anyPressed(KeyMods mod) const noexcept {
		return anyOf(mod);
	}
	bool KeyMods::anyReleased(KeyMods mod) const noexcept {
		return (*this & mod) != All;
	}

	// Check if ALL of the input modifiers are held.
	bool KeyMods::allPressed(KeyMods mod) const noexcept {
		return isPressed(mod);
	}
	bool KeyMods::allReleased(KeyMods mod) const noexcept {
		return isReleased(mod);
	}

	// Check if NONE of the input modifiers are held.
	bool KeyMods::nonePressed(KeyMods mod) const noexcept {
		return !anyPressed(mod);
	}
	bool KeyMods::noneReleased(KeyMods mod) const noexcept {
		return !anyReleased(mod);
	}

	template<std::size_t N>
	std::string_view makeView(const char(&arr)[N]) {
		return std::string_view{ arr, N - 1 };
	}

	std::string to_string(ez::KeyMods mod) {
		std::stringstream ss;

		::operator <<(ss, static_cast<ez::KeyModsBase>(mod));

		return ss.str();
	}
}