#pragma once
#include "intern/enumerations.hpp"
#include <string>
#include <string_view>
#include "KeyMods.hpp"

namespace ez {
	// Class for storing a keycode and modifier state, as needed for the KeyMap class.
	class KeyEvent {
	public:
		~KeyEvent() = default;

		// Construct with no modifiers, and key as None
		KeyEvent() noexcept;
		// Construct with no modifers set, and keycode
		KeyEvent(Key code) noexcept;
		// Construct with specified modifers set, and keycode
		KeyEvent(KeyMods mods, Key code) noexcept;

		// Returns true if the key value itself is a modifier, not if there are any modifiers.
		bool isModifier() const noexcept;

		// Get the raw value of this class, the value will include modifier data. Internal use, you likely don't need this.
		std::uint32_t getRawValue() const noexcept;

		KeyMods mods;
		Key code;
	};

	struct KeyState {
		KeyState() noexcept;

		void reset() noexcept;

		KeyMods mods;
		Key justPressed, justReleased, held;
	};

	std::string to_string(KeyState state);
	std::string to_string(KeyEvent ev);

	std::ostream& operator<<(std::ostream& os, const ez::KeyEvent& event);
	std::ostream& operator<<(std::ostream& os, const ez::KeyState& state);
};
using ez::operator<<;
