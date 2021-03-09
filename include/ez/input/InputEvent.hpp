#pragma once
#include "intern/enumerations.hpp"
#include <string>
#include <string_view>
#include "Key.hpp"
#include "Mouse.hpp"
#include <glm/vec2.hpp>

namespace ez {
	struct InputEvent
	{
		InputEvent() noexcept;

		InputEvent(InEv t, Key k) noexcept;

		InputEvent(InEv t, Mouse m) noexcept;

		InputEvent(InEv t, uint32_t unicode) noexcept;

		InputEvent(InEv t, glm::dvec2 delta) noexcept;

		InputEvent(const InputEvent& other) noexcept;

		~InputEvent();

		InputEvent& operator=(const InputEvent& other) noexcept;

		bool setCodepointFromUTF8(std::string_view str8);

		std::string to_string() const;
		
		InputEventType type;

		union {
			KeyEvent key;
			MouseEvent mouse;
			uint32_t codepoint;
			glm::dvec2 scroll;
			glm::ivec2 size;

			char data[24];
		};
	};

	std::string to_string(const InputEvent & ev);
	std::ostream& operator<<(std::ostream & os, const InputEvent& ev);
};
