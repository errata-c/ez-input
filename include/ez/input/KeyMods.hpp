#pragma once
#include "intern/enumerations.hpp"
#include <string>
#include <string_view>

namespace ez {
	class KeyMods;
	
	std::ostream& (operator<<)(std::ostream& os, ez::KeyMods mods) noexcept;
};
using ez::operator<<;

ez::KeyMods(operator|)(ez::KeyMods lh, ez::KeyMods rh) noexcept;
ez::KeyMods(operator&)(ez::KeyMods lh, ez::KeyMods rh) noexcept;
ez::KeyMods(operator^)(ez::KeyMods lh, ez::KeyMods rh) noexcept;
ez::KeyMods(operator~)(ez::KeyMods lh) noexcept;

ez::KeyMods(operator|)(ez::KeyMod lh, ez::KeyMod rh) noexcept;
ez::KeyMods(operator&)(ez::KeyMod lh, ez::KeyMod rh) noexcept;
ez::KeyMods(operator^)(ez::KeyMod lh, ez::KeyMod rh) noexcept;
ez::KeyMods(operator~)(ez::KeyMod lh) noexcept;

namespace ez {
	class KeyMods {
	public:
		static constexpr KeyMod Ctrl = KeyMod::Ctrl;
		static constexpr KeyMod Alt = KeyMod::Alt;
		static constexpr KeyMod Shift = KeyMod::Shift;
		static constexpr KeyMod System = KeyMod::System;

		constexpr KeyMods() noexcept
			: state(0)
		{}
		constexpr KeyMods(KeyMod mod) noexcept
			: state(1 << static_cast<int>(mod))
		{}

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

		KeyMods& operator|=(KeyMods rh) noexcept;
		KeyMods& operator&=(KeyMods rh) noexcept;
		KeyMods& operator^=(KeyMods rh) noexcept;

		bool operator==(KeyMods rh) const noexcept;
		bool operator!=(KeyMods rh) const noexcept;

		std::uint32_t getRawValue() const noexcept {
			return state;
		}

		friend ez::KeyMods(::operator|)(ez::KeyMods lh, ez::KeyMods rh) noexcept;
		friend ez::KeyMods(::operator&)(ez::KeyMods lh, ez::KeyMods rh) noexcept;
		friend ez::KeyMods(::operator^)(ez::KeyMods lh, ez::KeyMods rh) noexcept;
		friend ez::KeyMods(::operator~)(ez::KeyMods lh) noexcept;

	private:
		std::uint8_t state;
	};

	std::string_view to_string_view(KeyMods mod) noexcept;
	std::string to_string(KeyMods mod);
};