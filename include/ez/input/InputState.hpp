#pragma once
#include "InputEvent.hpp"
#include <array>

namespace ez {
	struct InputState {
		InputState();

		~InputState() = default;
		InputState(const InputState&) = default;
		InputState(InputState&&) = default;
		InputState& operator=(const InputState&) = default;
		InputState& operator=(InputState&&) = default;

		void reset();
		void resetKey();
		void resetMouse();
		void resetScroll();

		void merge(const InputEvent& event);

		void clear();

		InEv type;
		MouseState mouse;
		KeyState key;
		std::uint32_t codepoint;
		glm::dvec2 scroll;
		glm::ivec2 size;
		bool focused;
	};
};