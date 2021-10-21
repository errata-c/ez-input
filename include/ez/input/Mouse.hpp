#pragma once
#include "intern/enumerations.hpp"
#include <ez/BitFlags.hpp>
#include <glm/vec2.hpp>
#include <string>
#include <string_view>

namespace ez {
	using MouseButtonsBase = ez::BitFlags<ez::Mouse>;

	class MouseButtons: public MouseButtonsBase {
	public:
		MouseButtons(const MouseButtons&) noexcept = default;
		MouseButtons& operator=(const MouseButtons&) noexcept = default;

		using MouseButtonsBase::MouseButtonsBase;

		MouseButtons(MouseButtonsBase val) noexcept
			: MouseButtonsBase(val)
		{};

		bool isPressed(MouseButtons button) const noexcept;
		bool isReleased(MouseButtons button) const noexcept;

		void press(MouseButtons button) noexcept;
		void release(MouseButtons button) noexcept;

		int numPressed() const noexcept;
		int numReleased() const noexcept;

		MouseButtons lowestPressed() const noexcept;
		MouseButtons highestPressed() const noexcept;

		bool anyPressed(MouseButtons button) const noexcept;
		bool allPressed(MouseButtons button) const noexcept;
		bool nonePressed(MouseButtons button) const noexcept;
	};

	// Stores mouse buttons data and the most recent mouse position, used by InputEvent and InputState classes.
	struct MouseEvent {
		MouseEvent() noexcept
			: buttons()
			, position(0.0)
		{}
		MouseEvent(Mouse _button) noexcept
			: buttons(_button)
			, position(0.0)
		{}
		MouseEvent(MouseButtons _button) noexcept
			: buttons(_button)
			, position(0.0)
		{}

		MouseButtons buttons;
		glm::dvec2 position;
	};

	struct MouseState {
		MouseState()
			: justPressed(MouseButtons::None)
			, justReleased(MouseButtons::None)
			, position(0.0)
		{}

		void reset() {
			justPressed = MouseButtons::None;
			justReleased = MouseButtons::None;
			position = glm::dvec2(0.0);
			buttons.clear();
		}

		MouseButtons buttons;
		MouseButtons justPressed, justReleased;
		glm::dvec2 position;
	};

	/// <summary>
	/// Creates a string representing the button state. Dynamic, no string_view available.
	/// </summary>
	/// <param name="buttons">The button bitfield to process.</param>
	/// <returns>String describing the button state.</returns>
	std::string to_string(ez::MouseButtons val);

	std::string to_string(const ez::MouseEvent& val);

	std::string to_string(const ez::MouseState& val);

	std::ostream& operator<<(std::ostream & os, ez::MouseButtons val);

	std::ostream& operator<<(std::ostream& os, const ez::MouseEvent& val);

	std::ostream& operator<<(std::ostream& os, const ez::MouseState& val);
};

