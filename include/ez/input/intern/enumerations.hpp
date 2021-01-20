#pragma once
#include <iosfwd>
#include <cinttypes>
#include <string>
#include <string_view>

namespace ez {
	/*
	Enum discriminator for input events, used to determine the type of the event recieved.
	Note that it is undefined behaviour to access the data of an event whose type it not active.

	The naming scheme here is deliberate as well, CamelCase is used to prevent conflicts with macros. I recommend all enumerations be written in a
	different style then the traditional all caps form for that exact reason. I've encountered issues with macros before, and trust me you don't want to deal with that
	cryptic bullshit.
	*/
	enum class InputEventType : std::uint32_t {
		// The mouse moved, event will contain new position.
		MouseMove,

		// A mouse button was pressed, the event will contain the position of the cursor and the button that was just pressed.
		MousePress,

		// A mouse button was released, the event will contain the position of the cursor and the button that was just pressed.
		MouseRelease,

		// A mouse button went from released to pressed, this is emited after the press event.
		MouseClick,

		// A mouse button went from released to pressed for the second time, without any other button state changing.
		MouseClick2,

		// A key has been pressed, on many systems this event will be repeated if the key is held down.
		KeyPress,

		// A key has been repeated by the os. Depending on the system you may or may not get these.
		KeyRepeat,

		// A key has been released.
		KeyRelease,

		// The mouse wheel was scrolled, the event will contain either vertical or horizontal scroll deltas. Backend dependent.
		Scroll,

		// A unicode character has been generated, the event will contain a unsigned 32 bit integer for the codepoint.
		Char,

		// Touch input has begun. Highly backend dependent.
		TouchPress,

		// Touch input has ended. Highly backend dependent.
		TouchRelease,

		// Touch has changed position. Highly backend dependent.
		TouchMove,


		ControllerPress,


		ControllerRelease,


		ControllerMove,


		ControllerConnect,


		ControllerDisconnect,

		/// Window events
		// The cursor has entered the input area. Backend dependent.
		MouseEnter,

		// The cursor has left the input area. Backend dependent.
		MouseLeave,

		// The input area was resized. Backend dependent.
		Resized,

		// The input area has gained keyboard focus. Backend dependent.
		FocusGained,

		// The input area has lost keyboard focus. Backend dependent.
		FocusLost,

		// Window was shown
		Shown,

		// Window was hidden
		Hidden,

		Minimized,

		Maximized,

		Closed,

		// This is the type of a default constructed input event. On some backends an event will be generated with this type when the source event is unsupported.
		None,
	};
	using InEv = InputEventType;

	enum class Key : std::uint32_t {
		Unknown = 0xFFFF,
		None = 0,

		N0,
		N1,
		N2,
		N3,
		N4,
		N5,
		N6,
		N7,
		N8,
		N9,

		KP0,
		KP1,
		KP2,
		KP3,
		KP4,
		KP5,
		KP6,
		KP7,
		KP8,
		KP9,

		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,

		Hyphen,
		Dash = Hyphen,
		Minus = Hyphen,

		Tilde,
		Grave = Tilde,
		Enter,
		Tab,
		Equal,
		Space,
		Comma,
		Period,
		Quote,
		Apostrophe = Quote,
		FSlash,
		BSlash,
		Semicolon,
		LBracket,
		RBracket,

		Insert,
		Backspace,

		LShift,
		RShift,
		RCtrl,
		LCtrl,
		LAlt,
		RAlt,
		LSystem,
		RSystem,

		Pause,
		PageUp,
		PageDown,
		PrintScreen,
		SysReq,

		NumLock,
		CapsLock,
		ScrollLock,

		End,
		Home,
		Escape,
		Delete,

		Up,
		Left,
		Right,
		Down,

		KPDivide,
		KPMultiply,
		KPAdd,
		KPSubtract,
		KPEnter,
		KPDecimal,
		KPEqual,

		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		F13,
		F14,
		F15,
		F16,
		F17,
		F18,
		F19,
		F20,
		F21,
		F22,
		F23,
		F24,
		F25,

		NumKeys,
	};

	enum class Mouse {
		None = -1,
		// The left mouse button.
		Button1 = 0,
		// The middle mouse button.
		Button2 = 1,
		// The right mouse button.
		Button3 = 2,

		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button4 = 3,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button5 = 4,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button6 = 5,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button7 = 6,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button8 = 7,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button9 = 8,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button10 = 9,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button11 = 10,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button12 = 11,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button13 = 12,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button14 = 13,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button15 = 14,
		// All buttons greater than button3 are extra buttons, with no predefined name. Hardware dependent.
		Button16 = 15,

		// Left mouse button
		Left = Button1,
		// Middle mouse button
		Middle = Button2,
		// Right mouse button
		Right = Button3,
	};

	enum class KeyMod : std::uint8_t {
		None = 0,
		Ctrl = 1,
		Alt = 2,
		Shift = 3,
		System = 4
	};

	std::string_view to_string_view(ez::KeyMod val) noexcept;
	std::string_view to_string_view(ez::Key val) noexcept;
	std::string_view to_string_view(ez::Mouse val) noexcept;
	std::string_view to_string_view(ez::InputEventType val) noexcept;

	std::string to_string(ez::KeyMod val);
	std::string to_string(ez::Key val);
	std::string to_string(ez::Mouse val);
	std::string to_string(ez::InputEventType val);

	std::ostream& (operator<<)(std::ostream& os, ez::KeyMod val) noexcept;
	std::ostream& (operator<<)(std::ostream& os, ez::Key mod) noexcept;
	std::ostream& (operator<<)(std::ostream& os, ez::Mouse val) noexcept;
	std::ostream& (operator<<)(std::ostream& os, ez::InputEventType val) noexcept;
};
using ez::operator<<;