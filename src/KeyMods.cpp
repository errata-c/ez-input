#include <ez/input/KeyMods.hpp>
#include <ostream>

namespace ez {
	static constexpr std::uint8_t modMask = 0xF;

	void KeyMods::press(KeyMods mod) noexcept {
		state |= mod.state;
	}
	void KeyMods::release(KeyMods mod) noexcept {
		state &= ~mod.state;
	}

	bool KeyMods::isPressed(KeyMods mod) const noexcept {
		return (mod.state & state) == mod.state;
	}
	bool KeyMods::isReleased(KeyMods mod) const noexcept {
		return (mod.state & state) == 0;
	}

	// Check if ANY of the input modifiers are held.
	bool KeyMods::anyPressed(KeyMods mod) const noexcept {
		return (mod.state & state) != 0;
	}
	bool KeyMods::anyReleased(KeyMods mod) const noexcept {
		return (mod.state & state) != mod.state;
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

	KeyMods& KeyMods::operator|=(KeyMods rh) noexcept {
		state |= rh.state;
		return *this;
	}
	KeyMods& KeyMods::operator&=(KeyMods rh) noexcept {
		state &= rh.state;
		return *this;
	}
	KeyMods& KeyMods::operator^=(KeyMods rh) noexcept {
		state ^= rh.state;
		state &= modMask;
		return *this;
	}

	bool KeyMods::operator==(KeyMods rh) const noexcept {
		return state == rh.state;
	}
	bool KeyMods::operator!=(KeyMods rh) const noexcept {
		return state != rh.state;
	}

	template<std::size_t N>
	std::string_view makeView(const char(&arr)[N]) {
		return std::string_view{ arr, N - 1 };
	}

	std::string_view to_string_view(KeyMods val) noexcept {
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

	std::string to_string(ez::KeyMods mod) {
		return std::string(ez::to_string_view(mod));
	}

	
}

ez::KeyMods operator|(ez::KeyMods lh, ez::KeyMods rh) noexcept {
	lh |= rh;
	return lh;
}
ez::KeyMods operator&(ez::KeyMods lh, ez::KeyMods rh) noexcept {
	lh &= rh;
	return lh;
}
ez::KeyMods operator^(ez::KeyMods lh, ez::KeyMods rh) noexcept {
	lh ^= rh;
	return lh;
}
ez::KeyMods operator~(ez::KeyMods lh) noexcept {
	lh.state = ~lh.state;
	lh.state &= ez::modMask;
	return lh;
}

ez::KeyMods(operator|)(ez::KeyMod lh, ez::KeyMod rh) noexcept {
	ez::KeyMods tmp(lh);
	tmp |= rh;
	return tmp;
}
ez::KeyMods(operator&)(ez::KeyMod lh, ez::KeyMod rh) noexcept {
	ez::KeyMods tmp(lh);
	tmp &= rh;
	return tmp;
}
ez::KeyMods(operator^)(ez::KeyMod lh, ez::KeyMod rh) noexcept {
	ez::KeyMods tmp(lh);
	tmp ^= rh;
	return tmp;
}
ez::KeyMods(operator~)(ez::KeyMod lh) noexcept {
	ez::KeyMods tmp(lh);
	tmp = ~tmp;
	return tmp;
}

std::ostream& ez::operator<<(std::ostream& os, ez::KeyMods mods) noexcept {
	os << ez::to_string_view(mods);
	return os;
}