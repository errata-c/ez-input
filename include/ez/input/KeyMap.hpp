#pragma once
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <ez/input/Key.hpp>
#include <ez/input/Operator.hpp>

namespace ez {
	namespace intern {
		std::uint32_t getRawValue(ez::KeyMods mods, ez::Key key) noexcept;
	}
	
	class KeyGroup: public std::vector<std::string_view> {
	public:
		KeyGroup()
			: value(0)
		{}
		KeyGroup(std::uint32_t _value)
			: value(0)
		{}

		ez::Key getKey() const noexcept;
		ez::KeyMods getMods() const noexcept;
		std::uint32_t getRawValue() const noexcept;

		bool operator==(const KeyGroup& other) const noexcept;
		bool operator!=(const KeyGroup& other) const noexcept;
		bool operator<(const KeyGroup& other) const noexcept;
		bool operator>(const KeyGroup& other) const noexcept;
		bool operator<=(const KeyGroup& other) const noexcept;
		bool operator>=(const KeyGroup& other) const noexcept;
	private:
		std::uint32_t value;

		friend class KeyMap;
	};

	/*! Maps the key mods and current key value to an operator grouping.
	*/
	class KeyMap: public std::unordered_map<std::uint32_t, KeyGroup> {
	public:
		using super_t = std::unordered_map<std::uint32_t, KeyGroup>;

		KeyMap() = default;
		~KeyMap() = default;

		void add(KeyMods mods, Key key, std::string_view name);
		bool remove(KeyMods mods, Key key, std::string_view name);
		bool remove(std::string_view name);
		bool remove(KeyMods mods, Key key);

		iterator find(KeyMods mods, Key key);
		const_iterator find(KeyMods mods, Key key) const;
	};
};
