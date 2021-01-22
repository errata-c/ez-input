#pragma once
#include "intern/enumerations.hpp"
#include <glm/vec2.hpp>
#include <string>
#include <string_view>

namespace ez {
	class MouseButtons;
};

ez::MouseButtons(operator|)(ez::MouseButtons lh, ez::MouseButtons rh) noexcept;
ez::MouseButtons(operator&)(ez::MouseButtons lh, ez::MouseButtons rh) noexcept;
ez::MouseButtons(operator^)(ez::MouseButtons lh, ez::MouseButtons rh) noexcept;
ez::MouseButtons(operator~)(ez::MouseButtons lh) noexcept;

ez::MouseButtons(operator|)(ez::Mouse lh, ez::Mouse rh) noexcept;
ez::MouseButtons(operator&)(ez::Mouse lh, ez::Mouse rh) noexcept;
ez::MouseButtons(operator^)(ez::Mouse lh, ez::Mouse rh) noexcept;
ez::MouseButtons(operator~)(ez::Mouse lh) noexcept;

namespace ez {

	class MouseButtons {
	public:
		MouseButtons(const MouseButtons&) noexcept = default;
		MouseButtons& operator=(const MouseButtons&) noexcept = default;

		MouseButtons() noexcept;
		MouseButtons(Mouse button) noexcept;

		bool isPressed(Mouse button) const noexcept;
		bool isReleased(Mouse button) const noexcept;

		void clear() noexcept;

		void press(Mouse button) noexcept;
		void release(Mouse button) noexcept;
		
		template<typename ... Ts>
		void press(Mouse button, Ts ... args) noexcept {
			press(button);
			press(args...);
		}
		template<typename ... Ts>
		void release(Mouse button, Ts ... args) noexcept {
			release(button);
			release(args...);
		}

		int numPressed() const noexcept;
		int numReleased() const noexcept;

		bool operator==(MouseButtons other) const noexcept;
		bool operator!=(MouseButtons other) const noexcept;

		Mouse lowestPressed() const noexcept;
		Mouse highestPressed() const noexcept;

		template<typename ... Ts>
		bool anyPressed(Mouse button, Ts... args) const noexcept {
			return isPressed(button) || anyPressed(args...);
		}
		bool anyPressed(Mouse button) const noexcept {
			return isPressed(button);
		}

		template<typename ... Ts>
		bool allPressed(Mouse button, Ts... args) const noexcept {
			return isPressed(button) && anyPressed(args...);
		}
		bool allPressed(Mouse button) const noexcept {
			return isPressed(button);
		}

		template<typename ... Ts>
		bool nonePressed(Mouse button, Ts... args) const noexcept {
			return !isPressed(button) && nonePressed(args...);
		}
		bool nonePressed(Mouse button) const noexcept {
			return !isPressed(button);
		}

		ez::MouseButtons& operator|=(ez::MouseButtons lh) noexcept;
		ez::MouseButtons& operator&=(ez::MouseButtons lh) noexcept;
		ez::MouseButtons& operator^=(ez::MouseButtons lh) noexcept;

		friend ez::MouseButtons(::operator|)(ez::MouseButtons lh, ez::MouseButtons rh) noexcept;
		friend ez::MouseButtons(::operator&)(ez::MouseButtons lh, ez::MouseButtons rh) noexcept;
		friend ez::MouseButtons(::operator^)(ez::MouseButtons lh, ez::MouseButtons rh) noexcept;
		friend ez::MouseButtons(::operator~)(ez::MouseButtons lh) noexcept;

		friend ez::MouseButtons(::operator|)(ez::Mouse lh, ez::Mouse rh) noexcept;
		friend ez::MouseButtons(::operator&)(ez::Mouse lh, ez::Mouse rh) noexcept;
		friend ez::MouseButtons(::operator^)(ez::Mouse lh, ez::Mouse rh) noexcept;
		friend ez::MouseButtons(::operator~)(ez::Mouse lh) noexcept;
	private:
		int buttons;
	};

	// Stores mouse buttons data and the most recent mouse position, used by InputEvent and InputState classes.
	struct MouseEvent {
		MouseEvent() noexcept
			: button(Mouse::None)
			, position(0.0)
		{}

		MouseEvent(Mouse _button) noexcept
			: button(_button)
			, position(0.0)
		{}

		Mouse button;
		glm::dvec2 position;
	};

	struct MouseState {
		MouseState()
			: justPressed(Mouse::None)
			, justReleased(Mouse::None)
			, position(0.0)
		{}

		void reset() {
			justPressed = Mouse::None;
			justReleased = Mouse::None;
			position = glm::dvec2(0.0);
			buttons.clear();
		}

		MouseButtons buttons;
		Mouse justPressed, justReleased;
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