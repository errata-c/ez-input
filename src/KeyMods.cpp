#include <ez/input/KeyMods.hpp>
#include <ostream>

namespace ez {
	static constexpr std::uint8_t modMask = 0xF;

	void ModState::press(ModState mod) noexcept {
		state |= mod.state;
	}
	void ModState::release(ModState mod) noexcept {
		state &= ~mod.state;
	}

	bool ModState::isPressed(ModState mod) const noexcept {
		return (mod.state & state) == mod.state;
	}
	bool ModState::isReleased(ModState mod) const noexcept {
		return (mod.state & state) == 0;
	}

	// Check if ANY of the input modifiers are held.
	bool ModState::anyPressed(ModState mod) const noexcept {
		return (mod.state & state) != 0;
	}
	bool ModState::anyReleased(ModState mod) const noexcept {
		return (mod.state & state) != mod.state;
	}

	// Check if ALL of the input modifiers are held.
	bool ModState::allPressed(ModState mod) const noexcept {
		return isPressed(mod);
	}
	bool ModState::allReleased(ModState mod) const noexcept {
		return isReleased(mod);
	}

	// Check if NONE of the input modifiers are held.
	bool ModState::nonePressed(ModState mod) const noexcept {
		return !anyPressed(mod);
	}
	bool ModState::noneReleased(ModState mod) const noexcept {
		return !anyReleased(mod);
	}

	ModState& ModState::operator|=(ModState rh) noexcept {
		state |= rh.state;
		return *this;
	}
	ModState& ModState::operator&=(ModState rh) noexcept {
		state &= rh.state;
		return *this;
	}
	ModState& ModState::operator^=(ModState rh) noexcept {
		state ^= rh.state;
		state &= modMask;
		return *this;
	}

	bool ModState::operator==(ModState rh) const noexcept {
		return state == rh.state;
	}
	bool ModState::operator!=(ModState rh) const noexcept {
		return state != rh.state;
	}

	template<std::size_t N>
	std::string_view makeView(const char(&arr)[N]) {
		return std::string_view{ arr, N - 1 };
	}

	std::string_view to_string_view(ModState val) noexcept {
		switch (val.getRawValue()) {
		case 0:
			return makeView("None");
		case 1:
			return makeView("Ctrl");
		case 2:
			return makeView("Alt");
		case 3:
			return makeView("Ctrl, Alt");
		case 4:
			return makeView("Shift");
		case 5:
			return makeView("Ctrl, Shift");
		case 6:
			return makeView("Alt, Shift");
		case 7:
			return makeView("Ctrl, Alt, Shift");
		case 8:
			return makeView("System");
		case 9:
			return makeView("Ctrl, System");
		case 10:
			return makeView("Alt, System");
		case 11:
			return makeView("Ctrl, Alt, System");
		case 12:
			return makeView("Shift, System");
		case 13:
			return makeView("Ctrl, Shift, System");
		case 14:
			return makeView("Alt, Shift, System");
		case 15:
			return makeView("Ctrl, Alt, Shift, System");
		default:
			return makeView("None");
		}
	}

	std::string to_string(ez::ModState mod) {
		return std::string(ez::to_string_view(mod));
	}

	
}

ez::ModState operator|(ez::ModState lh, ez::ModState rh) noexcept {
	lh |= rh;
	return lh;
}
ez::ModState operator&(ez::ModState lh, ez::ModState rh) noexcept {
	lh &= rh;
	return lh;
}
ez::ModState operator^(ez::ModState lh, ez::ModState rh) noexcept {
	lh ^= rh;
	return lh;
}
ez::ModState operator~(ez::ModState lh) noexcept {
	lh.state = ~lh.state;
	lh.state &= ez::modMask;
	return lh;
}

ez::ModState(operator|)(ez::Mod lh, ez::Mod rh) noexcept {
	ez::ModState tmp(lh);
	tmp |= rh;
	return tmp;
}
ez::ModState(operator&)(ez::Mod lh, ez::Mod rh) noexcept {
	ez::ModState tmp(lh);
	tmp &= rh;
	return tmp;
}
ez::ModState(operator^)(ez::Mod lh, ez::Mod rh) noexcept {
	ez::ModState tmp(lh);
	tmp ^= rh;
	return tmp;
}
ez::ModState(operator~)(ez::Mod lh) noexcept {
	ez::ModState tmp(lh);
	tmp = ~tmp;
	return tmp;
}

std::ostream& ez::operator<<(std::ostream& os, ez::ModState mods) noexcept {
	os << ez::to_string_view(mods);
	return os;
}