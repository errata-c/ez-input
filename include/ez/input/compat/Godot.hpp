#pragma once
#include <ez/input/Key.hpp>
#include <ez/input/InputEvent.hpp>

#include <Godot.hpp>
#include <Object.hpp>
#include <InputEvent.hpp>
#include <InputEventMouseButton.hpp>
#include <InputEventMouseMotion.hpp>
#include <InputEventKey.hpp>

// Godot does not seem to store its enumerations in the native script api.
// We have to put them in manually.
namespace ez {
	// Namespace for implementation details. So as to not confuse users with name lookup.
	namespace impl {
		static constexpr int KeycodeMask = 33554431; // Key Code Mask
		static constexpr int KeymodMask = -16777216; // Modifier Key Mask
		static constexpr int KeyMaskShift = 33554432;// � Shift Key Mask
		static constexpr int KeyMaskAlt = 67108864;// � Alt Key Mask
		static constexpr int KeyMaskMeta = 134217728;// � Meta Key Mask
		static constexpr int KeyMaskCtrl = 268435456;// � CTRL Key Mask
		static constexpr int KeyMaskCommand = 268435456;// � CMD Key Mask
		static constexpr int KeyMaskKeypad = 536870912;// � Keypad Key Mask
		static constexpr int KeyMaskGroupSwitch = 1073741824;// � Group Switch Key Mask

		// For the sake of preventing this from having another dependency, make this function instead of including it from ez-math:
		static uint32_t bjb2Hash32(const uint8_t* str, int len) {
			uint32_t hash = 5381;
			int32_t c;

			for (const uint8_t* end = str + len; str < end; ++str) {
				c = *str;
				//hash = ((hash << 5) + hash) + c;
				//hash = hash * 33 + c;
				hash = hash * 33 ^ c;
			}

			return hash;
		}
	}

	static Key remapGodotKey(int code) {
		switch (code) {
		case 16777217: // KEY_ESCAPE = 16777217 � Escape Key
			return Key::Escape;
		case 16777218: // KEY_TAB = 16777218 � Tab Key
			return Key::Tab;
		case 16777220: // KEY_BACKSPACE = 16777220 � Backspace Key
			return Key::Backspace;
		case 16777221:// KEY_ENTER = 16777221 � Return Key(On Main Keyboard)
			return Key::Enter;
		case 16777222: // KEY_KP_ENTER = 16777222 � Enter Key(On Numpad)
			return Key::KPEnter;
		case 16777223:	// KEY_INSERT = 16777223 � Insert Key
			return Key::Insert;
		case 16777224:	// KEY_DELETE = 16777224 � Delete Key
#ifdef ANDROID // Android does not have a backspace key, so we emulate it with the delete key.
			return Key::Backspace;
#else
			return Key::Delete;
#endif
		case 16777225:	// KEY_PAUSE = 16777225 � Pause Key
			return Key::Pause;
		case 16777226:	// KEY_PRINT = 16777226 � Printscreen Key
			return Key::PrintScreen;
		case 16777227:	// KEY_SYSREQ = 16777227 � System Request Key
			return Key::SysReq;
		//case 16777228:	// KEY_CLEAR = 16777228 � Clear Key
			
		case 16777229:	// KEY_HOME = 16777229 � Home Key
			return Key::Home;
		case 16777230:	// KEY_END = 16777230 � End Key
			return Key::End;
		case 16777231:	// KEY_LEFT = 16777231 � Left Arrow Key
			return Key::Left;
		case 16777232:	// KEY_UP = 16777232 � Up Arrow Key
			return Key::Up;
		case 16777233:	// KEY_RIGHT = 16777233 � Right Arrow Key
			return Key::Right;
		case 16777234:	// KEY_DOWN = 16777234 � Down Arrow Key
			return Key::Down;
		case 16777235:	// KEY_PAGEUP = 16777235 � Pageup Key
			return Key::PageUp;
		case 16777236:	// KEY_PAGEDOWN = 16777236 � Pagedown Key
			return Key::PageDown;
		case 16777237:	// KEY_SHIFT = 16777237 � Shift Key
			return Key::LShift; // No left or right, so default to one.
		case 16777238:	// KEY_CONTROL = 16777238 � Control Key
			return Key::LCtrl;
		//case 16777239:	// KEY_META = 16777239 � Meta Key
			//return Key::
		case 16777240:	// KEY_ALT = 16777240 � Alt Key
			return Key::LAlt;
		case 16777241:	// KEY_CAPSLOCK = 16777241 � Capslock Key
			return Key::CapsLock;
		case 16777242:	// KEY_NUMLOCK = 16777242 � Numlock Key
			return Key::NumLock;
		case 16777243:	// KEY_SCROLLLOCK = 16777243 � Scrolllock Key
			return Key::ScrollLock;
		case 16777244:	// KEY_F1 = 16777244 � F1 Key
			return Key::F1;
		case 16777245:	// KEY_F2 = 16777245 � F2 Key
			return Key::F2;
		case 16777246:	// KEY_F3 = 16777246 � F3 Key
			return Key::F3;
		case 16777247:	// KEY_F4 = 16777247 � F4 Key
			return Key::F4;
		case 16777248:	// KEY_F5 = 16777248 � F5 Key
			return Key::F5;
		case 16777249:	// KEY_F6 = 16777249 � F6 Key
			return Key::F6;
		case 16777250:	// KEY_F7 = 16777250 � F7 Key
			return Key::F7;
		case 16777251:	// KEY_F8 = 16777251 � F8 Key
			return Key::F8;
		case 16777252:	// KEY_F9 = 16777252 � F9 Key
			return Key::F9;
		case 16777253:	// KEY_F10 = 16777253 � F10 Key
			return Key::F10;
		case 16777254:	// KEY_F11 = 16777254 � F11 Key
			return Key::F11;
		case 16777255:	// KEY_F12 = 16777255 � F12 Key
			return Key::F12;
		case 16777256:	// KEY_F13 = 16777256 � F13 Key
			return Key::F13;
		case 16777257:	// KEY_F14 = 16777257 � F14 Key
			return Key::F14;
		case 16777258:	// KEY_F15 = 16777258 � F15 Key
			return Key::F15;
		case 16777259:	// KEY_F16 = 16777259 � F16 Key
			return Key::F16;
		case 16777345:	// KEY_KP_MULTIPLY = 16777345 � Multiply Key on Numpad
			return Key::KPMultiply;
		case 16777346:	// KEY_KP_DIVIDE = 16777346 � Divide Key on Numpad
			return Key::KPDivide;
		case 16777347:	// KEY_KP_SUBTRACT = 16777347 � Subtract Key on Numpad
			return Key::KPSubtract;
		case 16777348:	// KEY_KP_PERIOD = 16777348 � Period Key on Numpad
			return Key::KPDecimal;
		case 16777349:	// KEY_KP_ADD = 16777349 � Add Key on Numpad
			return Key::KPAdd;
		case 16777350:	// KEY_KP_0 = 16777350 � Number 0 on Numpad
			return Key::KP0;
		case 16777351:	// KEY_KP_1 = 16777351 � Number 1 on Numpad
			return Key::KP1;
		case 16777352:	// KEY_KP_2 = 16777352 � Number 2 on Numpad
			return Key::KP2;
		case 16777353:	// KEY_KP_3 = 16777353 � Number 3 on Numpad
			return Key::KP3;
		case 16777354:	// KEY_KP_4 = 16777354 � Number 4 on Numpad
			return Key::KP4;
		case 16777355:	// KEY_KP_5 = 16777355 � Number 5 on Numpad
			return Key::KP5;
		case 16777356:	// KEY_KP_6 = 16777356 � Number 6 on Numpad
			return Key::KP6;
		case 16777357:	// KEY_KP_7 = 16777357 � Number 7 on Numpad
			return Key::KP7;
		case 16777358:	// KEY_KP_8 = 16777358 � Number 8 on Numpad
			return Key::KP8;
		case 16777359:	// KEY_KP_9 = 16777359 � Number 9 on Numpad
			return Key::KP9;
		case 16777260:	// KEY_SUPER_L = 16777260 � Left Super Key(Windows Key)
			return Key::LSystem;
		case 16777261:	// KEY_SUPER_R = 16777261 � Right Super Key(Windows Key)
			return Key::RSystem;
					// KEY_MENU = 16777262 � Context menu key
					// KEY_HYPER_L = 16777263 � Left Hyper Key
					// KEY_HYPER_R = 16777264 � Right Hyper Key
					// KEY_HELP = 16777265 � Help key
					// KEY_DIRECTION_L = 16777266 � Left Direction Key
					// KEY_DIRECTION_R = 16777267 � Right Direction Key
					// KEY_BACK = 16777280 � Back key
					// KEY_FORWARD = 16777281 � Forward key
					// KEY_STOP = 16777282 � Stop key
					// KEY_REFRESH = 16777283 � Refresh key
					// KEY_VOLUMEDOWN = 16777284 � Volume down key
					// KEY_VOLUMEMUTE = 16777285 � Mute volume key
					// KEY_VOLUMEUP = 16777286 � Volume up key
					// KEY_BASSBOOST = 16777287 � Bass Boost Key
					// KEY_BASSUP = 16777288 � Bass Up Key
					// KEY_BASSDOWN = 16777289 � Bass Down Key
					// KEY_TREBLEUP = 16777290 � Treble Up Key
					// KEY_TREBLEDOWN = 16777291 � Treble Down Key
					// KEY_MEDIAPLAY = 16777292 � Media play key
					// KEY_MEDIASTOP = 16777293 � Media stop key
					// KEY_MEDIAPREVIOUS = 16777294 � Previous song key
					// KEY_MEDIANEXT = 16777295 � Next song key
					// KEY_MEDIARECORD = 16777296 � Media record key
					// KEY_HOMEPAGE = 16777297 � Home page key
					// KEY_FAVORITES = 16777298 � Favorites key
					// KEY_SEARCH = 16777299 � Search key
					// KEY_STANDBY = 16777300 � Standby Key
					// KEY_OPENURL = 16777301 � Open URL / Launch Browser Key
					// KEY_LAUNCHMAIL = 16777302 � Launch Mail Key
					// KEY_LAUNCHMEDIA = 16777303 � Launch Media Key
					// KEY_LAUNCH0 = 16777304 � Launch Shortcut 0 Key
					// KEY_LAUNCH1 = 16777305 � Launch Shortcut 1 Key
					// KEY_LAUNCH2 = 16777306 � Launch Shortcut 2 Key
					// KEY_LAUNCH3 = 16777307 � Launch Shortcut 3 Key
					// KEY_LAUNCH4 = 16777308 � Launch Shortcut 4 Key
					// KEY_LAUNCH5 = 16777309 � Launch Shortcut 5 Key
					// KEY_LAUNCH6 = 16777310 � Launch Shortcut 6 Key
					// KEY_LAUNCH7 = 16777311 � Launch Shortcut 7 Key
					// KEY_LAUNCH8 = 16777312 � Launch Shortcut 8 Key
					// KEY_LAUNCH9 = 16777313 � Launch Shortcut 9 Key
					// KEY_LAUNCHA = 16777314 � Launch Shortcut A Key
					// KEY_LAUNCHB = 16777315 � Launch Shortcut B Key
					// KEY_LAUNCHC = 16777316 � Launch Shortcut C Key
					// KEY_LAUNCHD = 16777317 � Launch Shortcut D Key
					// KEY_LAUNCHE = 16777318 � Launch Shortcut E Key
					// KEY_LAUNCHF = 16777319 � Launch Shortcut F Key
					// KEY_UNKNOWN = 33554431 � Unknown Key
		case 32:	// KEY_SPACE = 32 � Space Key
			return Key::Space;
					// KEY_EXCLAM = 33 � !key
					// KEY_QUOTEDBL = 34 � � key
					// KEY_NUMBERSIGN = 35 � # key
					// KEY_DOLLAR = 36 � $ key
					// KEY_PERCENT = 37 � % key
					// KEY_AMPERSAND = 38 � & key
		case 39:	// KEY_APOSTROPHE = 39 � � key
			return Key::Apostrophe;
					// KEY_PARENLEFT = 40 �(key
					// KEY_PARENRIGHT = 41 �) key
					// KEY_ASTERISK = 42 � * key
					// KEY_PLUS = 43 � + key
		case 44:	// KEY_COMMA = 44 �, key
			return Key::Comma;
		case 45:	// KEY_MINUS = 45 � - key
			return Key::Minus;
		case 46:	// KEY_PERIOD = 46 �.key
			return Key::Period;
		case 47:	// KEY_SLASH = 47 � / key
			return Key::FSlash;
		case 48:	// KEY_0 = 48 � Number 0
			return Key::N0;
		case 49:	// KEY_1 = 49 � Number 1
			return Key::N1;
		case 50:	// KEY_2 = 50 � Number 2
			return Key::N2;
		case 51:	// KEY_3 = 51 � Number 3
			return Key::N3;
		case 52:	// KEY_4 = 52 � Number 4
			return Key::N4;
		case 53:	// KEY_5 = 53 � Number 5
			return Key::N5;
		case 54:	// KEY_6 = 54 � Number 6
			return Key::N6;
		case 55:	// KEY_7 = 55 � Number 7
			return Key::N7;
		case 56:	// KEY_8 = 56 � Number 8
			return Key::N8;
		case 57:	// KEY_9 = 57 � Number 9
			return Key::N9;
					// KEY_COLON = 58 � : key
		case 59:	// KEY_SEMICOLON = 59 �; key
			return Key::Semicolon;
					// KEY_LESS = 60 � Lower than key
		case 61: 	// KEY_EQUAL = 61 � = key
			return Key::Equal;
					// KEY_GREATER = 62 � Greater than key
					// KEY_QUESTION = 63 � ? key
					// KEY_AT = 64 � @ key
		case 65:	// KEY_A = 65 � A Key
			return Key::A;
		case 66:	// KEY_B = 66 � B Key
			return Key::B;
		case 67:	// KEY_C = 67 � C Key
			return Key::C;
		case 68:	// KEY_D = 68 � D Key
			return Key::D;
		case 69:	// KEY_E = 69 � E Key
			return Key::E;
		case 70:	// KEY_F = 70 � F Key
			return Key::F;
		case 71:	// KEY_G = 71 � G Key
			return Key::G;
		case 72:	// KEY_H = 72 � H Key
			return Key::H;
		case 73:	// KEY_I = 73 � I Key
			return Key::I;
		case 74:	// KEY_J = 74 � J Key
			return Key::J;
		case 75:	// KEY_K = 75 � K Key
			return Key::K;
		case 76:	// KEY_L = 76 � L Key
			return Key::L;
		case 77:	// KEY_M = 77 � M Key
			return Key::M;
		case 78:	// KEY_N = 78 � N Key
			return Key::N;
		case 79:	// KEY_O = 79 � O Key
			return Key::O;
		case 80:	// KEY_P = 80 � P Key
			return Key::P;
		case 81:	// KEY_Q = 81 � Q Key
			return Key::Q;
		case 82:	// KEY_R = 82 � R Key
			return Key::R;
		case 83:	// KEY_S = 83 � S Key
			return Key::S;
		case 84:	// KEY_T = 84 � T Key
			return Key::T;
		case 85:	// KEY_U = 85 � U Key
			return Key::U;
		case 86:	// KEY_V = 86 � V Key
			return Key::V;
		case 87:	// KEY_W = 87 � W Key
			return Key::W;
		case 88:	// KEY_X = 88 � X Key
			return Key::X;
		case 89:	// KEY_Y = 89 � Y Key
			return Key::Y;
		case 90:	// KEY_Z = 90 � Z Key
			return Key::Z;
		case 91:	// KEY_BRACKETLEFT = 91 �[key
			return Key::LBracket;
		case 92:	// KEY_BACKSLASH = 92 � \ key
			return Key::BSlash;
		case 93:	// KEY_BRACKETRIGHT = 93 �] key
			return Key::RBracket;
					// KEY_ASCIICIRCUM = 94 � ^ key
					// KEY_UNDERSCORE = 95 � _ key
		case 96:	// KEY_QUOTELEFT = 96 � ` key.
			return Key::Tilde;
					// KEY_BRACELEFT = 123 �{ key
					// KEY_BAR = 124 � | key
					// KEY_BRACERIGHT = 125 � } key
		case 126:	// KEY_ASCIITILDE = 126 � ~key
			return Key::Tilde;
					// KEY_NOBREAKSPACE = 160
					// KEY_EXCLAMDOWN = 161
					// KEY_CENT = 162 � � key
					// KEY_STERLING = 163
					// KEY_CURRENCY = 164 � � key.
					// KEY_YEN = 165 � � key.
					// KEY_BROKENBAR = 166 � � key
					// KEY_SECTION = 167 � � key
					// KEY_DIAERESIS = 168 � � key
					// KEY_COPYRIGHT = 169 � � key
					// KEY_ORDFEMININE = 170 � � key.
					// KEY_GUILLEMOTLEFT = 171 � � key
					// KEY_NOTSIGN = 172 � � key.
					// KEY_HYPHEN = 173 � Soft hyphen key.
					// KEY_REGISTERED = 174 � � key
					// KEY_MACRON = 175 � � key.
					// KEY_DEGREE = 176 � � key
					// KEY_PLUSMINUS = 177 � � key
					// KEY_TWOSUPERIOR = 178 � � key
					// KEY_THREESUPERIOR = 179 � � key
					// KEY_ACUTE = 180 � � key
					// KEY_MU = 181 � � key
					// KEY_PARAGRAPH = 182 � � key.
					// KEY_PERIODCENTERED = 183 � � key
					// KEY_CEDILLA = 184 � � key.
					// KEY_ONESUPERIOR = 185 � � key
					// KEY_MASCULINE = 186 � � key.
					// KEY_GUILLEMOTRIGHT = 187 � � key
					// KEY_ONEQUARTER = 188 � � key
					// KEY_ONEHALF = 189 � � key
					// KEY_THREEQUARTERS = 190 � � key
					// KEY_QUESTIONDOWN = 191 � � key
					// KEY_AGRAVE = 192 � � key.
					// KEY_AACUTE = 193 � � key.
					// KEY_ACIRCUMFLEX = 194 � � key.
					// KEY_ATILDE = 195 � � key.
					// KEY_ADIAERESIS = 196 � � key.
					// KEY_ARING = 197 � � key.
					// KEY_AE = 198 � � key.
					// KEY_CCEDILLA = 199 � � key.
					// KEY_EGRAVE = 200 � � key.
					// KEY_EACUTE = 201 � � key.
					// KEY_ECIRCUMFLEX = 202 � � key.
					// KEY_EDIAERESIS = 203 � � key.
					// KEY_IGRAVE = 204 � � key.
					// KEY_IACUTE = 205 � � key.
					// KEY_ICIRCUMFLEX = 206 � � key.
					// KEY_IDIAERESIS = 207 � � key.
					// KEY_ETH = 208 � � key.
					// KEY_NTILDE = 209 � � key.
					// KEY_OGRAVE = 210 � � key.
					// KEY_OACUTE = 211 � � key.
					// KEY_OCIRCUMFLEX = 212 � � key.
					// KEY_OTILDE = 213 � � key.
					// KEY_ODIAERESIS = 214 � � key.
					// KEY_MULTIPLY = 215 � � key
					// KEY_OOBLIQUE = 216 � � key.
					// KEY_UGRAVE = 217 � � key.
					// KEY_UACUTE = 218 � � key.
					// KEY_UCIRCUMFLEX = 219 � � key.
					// KEY_UDIAERESIS = 220 � � key.
					// KEY_YACUTE = 221 � � key.
					// KEY_THORN = 222 � � key.
					// KEY_SSHARP = 223 � � key
					// KEY_DIVISION = 247 � � key
					// KEY_YDIAERESIS = 255 � � key
		default:
			return Key::Unknown;
		}
	}

	static ez::InputEvent remapGodotEvent(godot::Variant arg) {
		if (arg.get_type() != godot::Variant::Type::OBJECT) {
			godot::Godot::print_error("Variant passed into function ez::remapGodotEvent was not an object type.",
				"static ez::InputEvent remapGodotEvent(godot::Variant obj)",
				__FILE__,
				__LINE__);
			return ez::InputEvent{};
		}

		using namespace godot;
		ez::InputEvent event;

		Object* obj{arg};
		
		godot::String clname = obj->get_class();

		// Hash the name, and compare to the hashes of the input class names:
		uint8_t* str = (uint8_t*)&clname[0];
		int hash = (int)impl::bjb2Hash32(str, clname.length() * sizeof(wchar_t));

		// Sorry for all the magic numbers, but this is an easy straight forward way to handle the classnames.
		switch (hash) {
		case 1584825856: { //InputEventMouseMotion
			auto* gdev = static_cast<InputEventMouseMotion*>(obj);

			Vector2 position = gdev->get_position();
			event.type = InputEventType::MouseMove;
			event.mouse = ez::MouseData{};
			event.mouse.position = glm::dvec2{position.x, position.y};
			return event; }
			
		case 1101487304: { // InputEventMouseButton
			auto* gdev = static_cast<InputEventMouseButton*>(obj);
			int64_t index = gdev->get_button_index();
			switch (index) {
			case 1: { // Left
				bool pressed = gdev->is_pressed();
				//bool isDouble = obj->get("doubleclick");
				Vector2 position = gdev->get_position();
				if (pressed) {
					event.type = InputEventType::MousePress;
				}
				else {
					event.type = InputEventType::MouseRelease;
				}

				event.mouse = ez::MouseData{};
				event.mouse.position = glm::dvec2{position.x, position.y};
				event.mouse.setButtons(Mouse::Left);
				return event; }

			case 2: { // Right
				bool pressed = gdev->is_pressed();
				//bool isDouble = obj->get("doubleclick");
				Vector2 position = gdev->get_position();
				if (pressed) {
					event.type = InputEventType::MousePress;
				}
				else {
					event.type = InputEventType::MouseRelease;
				}

				event.mouse = ez::MouseData{};
				event.mouse.position = glm::dvec2{ position.x, position.y };
				event.mouse.setButtons(Mouse::Right);
				return event; }

			case 3: { // Middle
				bool pressed = gdev->is_pressed();
				//bool isDouble = obj->get("doubleclick");
				Vector2 position = gdev->get_position();
				if (pressed) {
					event.type = InputEventType::MousePress;
				}
				else {
					event.type = InputEventType::MouseRelease;
				}

				event.mouse = ez::MouseData{};
				event.mouse.position = glm::dvec2{ position.x, position.y };
				event.mouse.setButtons(Mouse::Middle);
				return event; }

			case 4: { // Wheel Up
				float factor = gdev->get_factor();

				event.type = InputEventType::Scroll;
				event.scroll = glm::dvec2{ 0.0, factor };
				return event; }

			case 5: { // Wheel Down
				float factor = gdev->get_factor();

				event.type = InputEventType::Scroll;
				event.scroll = glm::dvec2{ 0.0, -factor };
				return event; }

			case 6: { // Wheel Left
				float factor = gdev->get_factor();

				event.type = InputEventType::Scroll;
				event.scroll = glm::dvec2{ -factor, 0.0 };
				return event; }

			case 7: { // Wheel Right
				float factor = gdev->get_factor();

				event.type = InputEventType::Scroll;
				event.scroll = glm::dvec2{ factor, 0.0 };
				return event; }

			case 8: { // XButton 1
				bool pressed = gdev->is_pressed();
				//bool isDouble = obj->get("doubleclick");
				Vector2 position = gdev->get_position();
				if (pressed) {
					event.type = InputEventType::MousePress;
				}
				else {
					event.type = InputEventType::MouseRelease;
				}

				event.mouse = ez::MouseData{};
				event.mouse.position = glm::dvec2{ position.x, position.y };
				event.mouse.setButtons(Mouse::Button4);
				return event; }

			case 9: { // XButton 2
				bool pressed = gdev->is_pressed();
				//bool isDouble = obj->get("doubleclick");
				Vector2 position = gdev->get_position();
				if (pressed) {
					event.type = InputEventType::MousePress;
				}
				else {
					event.type = InputEventType::MouseRelease;
				}

				event.mouse = ez::MouseData{};
				event.mouse.position = glm::dvec2{ position.x, position.y };
				event.mouse.setButtons(Mouse::Button5);
				return event; }
			}
		}
			break;
		case 66929384: {// InputEventKey
			auto* gdev = static_cast<InputEventKey*>(obj);

			bool echo = gdev->is_echo();
			if (echo) {
				// We don't need echo events.
				return event;
			}

			int fullcode = static_cast<int>(gdev->get_scancode_with_modifiers());

			int scancode = fullcode & impl::KeycodeMask;
			int mods = fullcode & impl::KeymodMask;
			bool pressed = gdev->is_pressed();
			
			if (pressed) {
				event.type = InputEventType::KeyPress;
			}
			else {
				event.type = InputEventType::KeyRelease;
			}
			
			event.key = KeyEvent{};
			event.key.setKey(remapGodotKey(scancode));
			event.key.setCtrl((mods & impl::KeyMaskCtrl) != 0);
			event.key.setAlt((mods & impl::KeyMaskAlt) != 0);
			event.key.setShift((mods & impl::KeyMaskShift) != 0);
			return event;
		}
			break;
		case -1459169962: { // InputEventScreenTouch
			
		}
			break;
		case -11787197: { // InputEventScreenDrag
			
		}
			break;
		case -1708923552: { // InputEventJoypadButton

		}
			break;
		case -1430203224: { // InputEventJoypadMotion

		}
			break;
		default:
			Godot::print_error(
				"Unexpected class name passed into ez::remapGodotEvent", 
				"static ez::InputEvent remapGodotEvent(godot::Object * obj)", 
				__FILE__, 
				__LINE__);
		}

		// Incase there is no match at all, just return empty event.
		return event;
	}
};