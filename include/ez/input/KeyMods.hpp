#pragma once
#include "intern/enumerations.hpp"
#include <ez/BitFlags.hpp>
#include <string>
#include <string_view>

namespace ez {
	using KeyModsBase = ez::BitFlags<KeyMod>;

	class KeyMods: public KeyModsBase {
	public:
		static constexpr KeyMod Ctrl = KeyMod::Ctrl;
		static constexpr KeyMod Alt = KeyMod::Alt;
		static constexpr KeyMod Shift = KeyMod::Shift;
		static constexpr KeyMod System = KeyMod::System;

		using KeyModsBase::KeyModsBase;

		KeyMods(KeyModsBase val)
			: KeyModsBase(val)
		{};

		KeyMods(const KeyMods&) noexcept = default;
		KeyMods& operator=(const KeyMods&) noexcept = default;

		void press(KeyMods mod) noexcept;
		void release(KeyMods mod) noexcept;

		bool isPressed(KeyMods mod) const noexcept;
		bool isReleased(KeyMods mod) const noexcept;

		// Check if ANY of the input modifiers are held.
		bool anyPressed(KeyMods mods) const noexcept;
		bool anyReleased(KeyMods mods) const noexcept;

		// Check if ALL of the input modifiers are held.
		bool allPressed(KeyMods mods) const noexcept;
		bool allReleased(KeyMods mods) const noexcept;

		// Check if NONE of the input modifiers are held.
		bool nonePressed(KeyMods mods) const noexcept;
		bool noneReleased(KeyMods mods) const noexcept;
	};

	std::string to_string(KeyMods mod);

	// Fix namespace look up, allows operator to be used inside the namespace, also fixes lookup in libfmt
	inline std::ostream& operator<<(std::ostream& os, KeyMods mods) {
		return ::operator<<(os, mods);
	}
};