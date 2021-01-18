#pragma once
#include "intern/enumerations.hpp"
#include <string>
#include <string_view>

namespace ez {
	class ModState;
	
	std::ostream& (operator<<)(std::ostream& os, ez::ModState mods) noexcept;
};
using ez::operator<<;

ez::ModState (operator|)(ez::ModState lh, ez::ModState rh) noexcept;
ez::ModState (operator&)(ez::ModState lh, ez::ModState rh) noexcept;
ez::ModState (operator^)(ez::ModState lh, ez::ModState rh) noexcept;
ez::ModState (operator~)(ez::ModState lh) noexcept;

ez::ModState (operator|)(ez::Mod lh, ez::Mod rh) noexcept;
ez::ModState (operator&)(ez::Mod lh, ez::Mod rh) noexcept;
ez::ModState (operator^)(ez::Mod lh, ez::Mod rh) noexcept;
ez::ModState (operator~)(ez::Mod lh) noexcept;

namespace ez {
	class ModState {
	public:
		constexpr ModState() noexcept
			: state(0)
		{}
		constexpr ModState(Mod mod) noexcept
			: state(1 << static_cast<int>(mod))
		{}

		ModState(const ModState &) noexcept = default;
		ModState& operator=(const ModState&) noexcept = default;

		void press(ModState mod) noexcept;
		void release(ModState mod) noexcept;

		bool isPressed(ModState mod) const noexcept;
		bool isReleased(ModState mod) const noexcept;

		// Check if ANY of the input modifiers are held.
		bool anyPressed(ModState mods) const noexcept;
		bool anyReleased(ModState mods) const noexcept;

		// Check if ALL of the input modifiers are held.
		bool allPressed(ModState mods) const noexcept;
		bool allReleased(ModState mods) const noexcept;

		// Check if NONE of the input modifiers are held.
		bool nonePressed(ModState mods) const noexcept;
		bool noneReleased(ModState mods) const noexcept;

		ModState& operator|=(ModState rh) noexcept;
		ModState& operator&=(ModState rh) noexcept;
		ModState& operator^=(ModState rh) noexcept;

		bool operator==(ModState rh) const noexcept;
		bool operator!=(ModState rh) const noexcept;

		std::uint32_t getRawValue() const noexcept {
			return state;
		}

		friend ez::ModState (::operator|)(ez::ModState lh, ez::ModState rh) noexcept;
		friend ez::ModState (::operator&)(ez::ModState lh, ez::ModState rh) noexcept;
		friend ez::ModState (::operator^)(ez::ModState lh, ez::ModState rh) noexcept;
		friend ez::ModState (::operator~)(ez::ModState lh) noexcept;

	private:
		std::uint8_t state;
	};

	std::string_view to_string_view(ModState mod) noexcept;
	std::string to_string(ModState mod);
};