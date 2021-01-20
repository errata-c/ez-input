#include <ez/input/KeyMap.hpp>

namespace ez {
	namespace intern {
		std::uint32_t getRawValue(ez::KeyMods mods, ez::Key key) noexcept {
			return (mods.getRawValue() << 28) | static_cast<std::uint32_t>(key);
		}
	}

	using iterator = KeyMap::iterator;
	using const_iterator = KeyMap::const_iterator;

	bool KeyGroup::operator==(const KeyGroup& other) const noexcept {
		return value == other.value;
	}
	bool KeyGroup::operator!=(const KeyGroup& other) const noexcept {
		return value != other.value;
	}
	bool KeyGroup::operator<(const KeyGroup& other) const noexcept {
		return static_cast<std::uint32_t>(value) < static_cast<std::uint32_t>(other.value);
	}
	bool KeyGroup::operator>(const KeyGroup& other) const noexcept {
		return static_cast<std::uint32_t>(value) > static_cast<std::uint32_t>(other.value);
	}
	bool KeyGroup::operator<=(const KeyGroup& other) const noexcept {
		return static_cast<std::uint32_t>(value) <= static_cast<std::uint32_t>(other.value);
	}
	bool KeyGroup::operator>=(const KeyGroup& other) const noexcept {
		return static_cast<std::uint32_t>(value) >= static_cast<std::uint32_t>(other.value);
	}
	
	ez::Key KeyGroup::getKey() const noexcept {
		return static_cast<ez::Key>(value & 0x0FFF'FFFF);
	}
	ez::KeyMods KeyGroup::getMods() const noexcept {
		union Conv {
			std::uint8_t value;
			ez::KeyMods mods;
		};

		Conv conv{ static_cast<std::uint8_t>(getRawValue() >> 28) };
		return conv.mods;
	}
	std::uint32_t KeyGroup::getRawValue() const noexcept {
		return value;
	}

	iterator KeyMap::find(KeyMods mods, Key key) {
		return super_t::find(intern::getRawValue(mods, key));
	}
	const_iterator KeyMap::find(KeyMods mods, Key key) const {
		return super_t::find(intern::getRawValue(mods, key));
	}

	void KeyMap::add(KeyMods mods, Key key, Operator& op) {
		std::uint32_t index = intern::getRawValue(mods, key);

		KeyGroup& group = super_t::operator[](index);
		group.value = index;

		group.push_back(&op);
	}
	bool KeyMap::remove(KeyMods mods, Key key, Operator& op) {
		iterator found = find(mods, key);
		if (found == end()) {
			return false;
		}
		KeyGroup& group = found->second;

		KeyGroup::iterator iter = std::remove_if(group.begin(), group.end(), [&op, &key](Operator* item) {
			return (item == &op);
		});
		if (iter != group.end()) {
			group.erase(iter, group.end());

			if (group.size() == 0) {
				erase(found);
			}
			return true;
		}
		return false;
	}

	bool KeyMap::remove(KeyMods mods, Key key) {
		iterator it = find(mods, key);
		if (it == end()) {
			return false;
		}
		erase(it);
		return true;
	}

	bool KeyMap::remove(Operator& op) {
		bool found = false;

		iterator it = begin();
		iterator last = end();
		for (; it != last; ++it) {
			KeyGroup& group = it->second;
			KeyGroup::iterator groupIt = std::remove_if(group.begin(), group.end(), [&op](Operator* item) {
				return (item == &op);
			});

			if (groupIt != group.end()) {
				found = true;

				group.erase(groupIt, group.end());

				if (group.size() == 0) {
					it = super_t::erase(it);
					last = end();
				}
			}
		}

		return found;
	}
};