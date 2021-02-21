#pragma once
#include <cinttypes>
#include <ez/input/Key.hpp>
#include <ez/input/InputEvent.hpp>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>

namespace ez::input {
	inline Key remapGtkKey(uint32_t val){
		switch (val) {
		case GDK_KEY_VoidSymbol:
			return Key::Unknown;

		case GDK_KEY_0:
		case GDK_KEY_1:
		case GDK_KEY_2:
		case GDK_KEY_3:
		case GDK_KEY_4:
		case GDK_KEY_5:
		case GDK_KEY_6:
		case GDK_KEY_7:
		case GDK_KEY_8:
		case GDK_KEY_9:
			return static_cast<Key>((val - GDK_KEY_0) + static_cast<int>(Key::N0));

		case GDK_KEY_exclam:
			return Key::N1;
		case GDK_KEY_at:
			return Key::N2;
		case GDK_KEY_numbersign:
			return Key::N3;
		case GDK_KEY_dollar:
			return Key::N4;
		case GDK_KEY_percent:
			return Key::N5;
		case GDK_KEY_asciicircum:
			return Key::N6;
		case GDK_KEY_ampersand:
			return Key::N7;
		case GDK_KEY_asterisk:
			return Key::N8;
		case GDK_KEY_parenleft:
			return Key::N9;
		case GDK_KEY_parenright:
			return Key::N0;

		case GDK_KEY_A:
		case GDK_KEY_B:
		case GDK_KEY_C:
		case GDK_KEY_D:
		case GDK_KEY_E:
		case GDK_KEY_F:
		case GDK_KEY_G:
		case GDK_KEY_H:
		case GDK_KEY_I:
		case GDK_KEY_J:
		case GDK_KEY_K:
		case GDK_KEY_L:
		case GDK_KEY_M:
		case GDK_KEY_N:
		case GDK_KEY_O:
		case GDK_KEY_P:
		case GDK_KEY_Q:
		case GDK_KEY_R:
		case GDK_KEY_S:
		case GDK_KEY_T:
		case GDK_KEY_U:
		case GDK_KEY_V:
		case GDK_KEY_W:
		case GDK_KEY_X:
		case GDK_KEY_Y:
		case GDK_KEY_Z:
			return static_cast<Key>((val - GDK_KEY_A) + static_cast<int>(Key::A));

		case GDK_KEY_a:
		case GDK_KEY_b:
		case GDK_KEY_c:
		case GDK_KEY_d:
		case GDK_KEY_e:
		case GDK_KEY_f:
		case GDK_KEY_g:
		case GDK_KEY_h:
		case GDK_KEY_i:
		case GDK_KEY_j:
		case GDK_KEY_k:
		case GDK_KEY_l:
		case GDK_KEY_m:
		case GDK_KEY_n:
		case GDK_KEY_o:
		case GDK_KEY_p:
		case GDK_KEY_q:
		case GDK_KEY_r:
		case GDK_KEY_s:
		case GDK_KEY_t:
		case GDK_KEY_u:
		case GDK_KEY_v:
		case GDK_KEY_w:
		case GDK_KEY_x:
		case GDK_KEY_y:
		case GDK_KEY_z:
			return static_cast<Key>((val - GDK_KEY_a) + static_cast<int>(Key::A));

		case GDK_KEY_F1:
		case GDK_KEY_F2:
		case GDK_KEY_F3:
		case GDK_KEY_F4:
		case GDK_KEY_F5:
		case GDK_KEY_F6:
		case GDK_KEY_F7:
		case GDK_KEY_F8:
		case GDK_KEY_F9:
		case GDK_KEY_F10:
		case GDK_KEY_F11:
		case GDK_KEY_F12:
		case GDK_KEY_F13:
		case GDK_KEY_F14:
		case GDK_KEY_F15:
		case GDK_KEY_F16:
		case GDK_KEY_F17:
		case GDK_KEY_F18:
		case GDK_KEY_F19:
		case GDK_KEY_F20:
		case GDK_KEY_F21:
		case GDK_KEY_F22:
		case GDK_KEY_F23:
		case GDK_KEY_F24:
		case GDK_KEY_F25:
			return static_cast<Key>((val - GDK_KEY_F1) + static_cast<int>(Key::F1));

		case GDK_KEY_KP_0:
		case GDK_KEY_KP_1:
		case GDK_KEY_KP_2:
		case GDK_KEY_KP_3:
		case GDK_KEY_KP_4:
		case GDK_KEY_KP_5:
		case GDK_KEY_KP_6:
		case GDK_KEY_KP_7:
		case GDK_KEY_KP_8:
		case GDK_KEY_KP_9:
			return static_cast<Key>((val - GDK_KEY_KP_0) + static_cast<int>(Key::KP0));

		case GDK_KEY_space:
			return Key::Space;

		case GDK_KEY_apostrophe:
			return Key::Quote;

		case GDK_KEY_comma:
		case GDK_KEY_less:
			return Key::Comma;

		case GDK_KEY_minus:
		case GDK_KEY_underscore:
			return Key::Minus;

		case GDK_KEY_period:
		case GDK_KEY_greater:
			return Key::Period;

		case GDK_KEY_slash:
		case GDK_KEY_question:
			return Key::FSlash;

		case GDK_KEY_colon:
		case GDK_KEY_semicolon:
			return Key::Semicolon;

		case GDK_KEY_equal:
		case GDK_KEY_plus:
			return Key::Equal;

		case GDK_KEY_bracketleft:
		case GDK_KEY_braceleft:
			return Key::LBracket;

		case GDK_KEY_bracketright:
		case GDK_KEY_braceright:
			return Key::RBracket;

		case GDK_KEY_backslash:
		case GDK_KEY_bar:
			return Key::BSlash;

		case GDK_KEY_grave:
		case GDK_KEY_asciitilde:
			return Key::Tilde;

		case GDK_KEY_Escape:
			return Key::Escape;

		case GDK_KEY_Return:
			return Key::Enter;

		case GDK_KEY_Tab:
			return Key::Tab;

		case GDK_KEY_BackSpace:
			return Key::Backspace;

		case GDK_KEY_KP_Insert:
		case GDK_KEY_Insert:
			return Key::Insert;

		case GDK_KEY_Delete:
		case GDK_KEY_KP_Delete:
			return Key::Delete;

		case GDK_KEY_KP_Right:
		case GDK_KEY_Right:
			return Key::Right;

		case GDK_KEY_KP_Left:
		case GDK_KEY_Left:
			return Key::Left;

		case GDK_KEY_KP_Up:
		case GDK_KEY_Up:
			return Key::Up;

		case GDK_KEY_KP_Down:
		case GDK_KEY_Down:
			return Key::Down;

		case GDK_KEY_Page_Up:
		case GDK_KEY_KP_Page_Up:
			return Key::PageUp;

		case GDK_KEY_Page_Down:
		case GDK_KEY_KP_Page_Down:
			return Key::PageDown;

		case GDK_KEY_Home:
		case GDK_KEY_KP_Home:
			return Key::Home;

		case GDK_KEY_End:
		case GDK_KEY_KP_End:
			return Key::End;

		case GDK_KEY_Pause:
			return Key::Pause;

		case GDK_KEY_KP_Decimal:
			return Key::KPDecimal;

		case GDK_KEY_KP_Divide:
			return Key::KPDivide;

		case GDK_KEY_KP_Multiply:
			return Key::KPMultiply;

		case GDK_KEY_KP_Subtract:
			return Key::KPSubtract;

		case GDK_KEY_KP_Add:
			return Key::KPAdd;

		case GDK_KEY_KP_Enter:
			return Key::KPEnter;

		case GDK_KEY_Shift_L:
			return Key::LShift;

		case GDK_KEY_Shift_R:
			return Key::RShift;

		case GDK_KEY_Alt_L:
			return Key::LAlt;

		case GDK_KEY_Alt_R:
			return Key::RAlt;

		case GDK_KEY_Control_L:
			return Key::LCtrl;

		case GDK_KEY_Control_R:
			return Key::RCtrl;

		case GDK_KEY_Super_L:
			return Key::LSystem;

		case GDK_KEY_Super_R:
			return Key::RSystem;

		case GDK_KEY_Num_Lock:
			return Key::NumLock;

		case GDK_KEY_Caps_Lock:
			return Key::CapsLock;

		case GDK_KEY_Scroll_Lock:
			return Key::ScrollLock;

		case GDK_KEY_KP_Equal:
			return Key::KPEqual;

		default:
			return Key::Unknown;

		}
	}

	inline InputEvent remapEvent(GdkEventButton * in) {
		InputEvent ev;
		switch (in->type) {
		case GDK_BUTTON_PRESS:
			ev.type = InputEventType::MousePress;
			ev.mouse = MouseData();
			ev.mouse.position.x = in->x;
			ev.mouse.position.y = in->y;
			ev.mouse.setButtons(static_cast<Mouse>(1 << (in->button-1)));
			break;
		//case GDK_2BUTTON_PRESS:
		//	ev.type = InputEventType::MousePress;

		//	break;
		//case GDK_3BUTTON_PRESS:
		//	ev.type = InputEventType::MousePress;

		//	break;
		case GDK_BUTTON_RELEASE:
			ev.type = InputEventType::MouseRelease;
			ev.mouse = MouseData();
			ev.mouse.position.x = in->x;
			ev.mouse.position.y = in->y;
			ev.mouse.setButtons(static_cast<Mouse>(1 << (in->button-1)));
			break;
		}

		return ev;
	}
	inline InputEvent remapGtkEvent(GdkEventKey* in) {
		InputEvent ev;
		if (in->type == GDK_KEY_PRESS) {
			ev.type = InputEventType::KeyPress;
		}
		else {
			ev.type = InputEventType::KeyRelease;
		}

		ev.key = KeyEvent(
			bool(in->state & GDK_CONTROL_MASK), 
			bool(in->state & GDK_MOD1_MASK), 
			bool(in->state & GDK_SHIFT_MASK), 
			bool(in->state & GDK_SUPER_MASK), 
			remapGtkKey(in->keyval));
		return ev;
	}
	inline InputEvent remapGtkEventChar(GdkEventKey* in) {
		InputEvent ev;
		ev.type = InputEventType::Char;
		ev.codepoint = gdk_keyval_to_unicode(in->keyval);
		return ev;
	}
	inline InputEvent remapGtkEvent(GdkEventMotion* in) {
		InputEvent ev;
		ev.type = InputEventType::MouseMove;
		ev.mouse = MouseData();
		ev.mouse.position.x = in->x;
		ev.mouse.position.y = in->y;

		//ev.mouse.setButtons(static_cast<Mouse>((in->state >> 8) & 0b11111));

		return ev;
	}
	inline InputEvent remapGtkEvent(GdkEventFocus* in) {
		InputEvent ev;
		if (in->in) {
			ev.type = InputEventType::GainedFocus;
		}
		else {
			ev.type = InputEventType::LostFocus;
		}
		return ev;
	}
	inline InputEvent remapGtkEvent(GdkEventCrossing* in) {
		InputEvent ev;
		if (in->type == GDK_ENTER_NOTIFY) {
			ev.type = InputEventType::MouseEnter;
		}
		else {
			ev.type = InputEventType::MouseLeave;
		}
		ev.codepoint = 0;
		return ev;
	}
	inline InputEvent remapGtkEvent(GdkEventScroll* in) {
		InputEvent ev;
		ev.type = InputEventType::Scroll;
		ev.scroll.x = in->delta_x;
		ev.scroll.y = in->delta_y;
		return ev;
	}
};