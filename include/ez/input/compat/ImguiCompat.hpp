#pragma once
#include <array>
#include <ez/InputEvent.hpp>
#include <imgui.h>

namespace ez {
	// It's recommended to have an input state struct for every window receiving input. They are not very large structures.
	class ImguiInputState {
	public:
		ImGuiInputState()
			: mousePressed{ false, false, false, false, false, false, false, false }
			, touchPressed{ false, false, false, false, false, false, false, false }
			, mouseMoved(false)
		{}

		void initKeymap() {
			ImGuiIO& io = ImGui::GetIO();

			io.KeyMap[ImGuiKey_Tab] = static_cast<uint32_t>(Key::Tab);
			io.KeyMap[ImGuiKey_LeftArrow] = static_cast<uint32_t>(Key::Left);
			io.KeyMap[ImGuiKey_RightArrow] = static_cast<uint32_t>(Key::Right);
			io.KeyMap[ImGuiKey_UpArrow] = static_cast<uint32_t>(Key::Up);
			io.KeyMap[ImGuiKey_DownArrow] = static_cast<uint32_t>(Key::Down);
			io.KeyMap[ImGuiKey_PageUp] = static_cast<uint32_t>(Key::PageUp);
			io.KeyMap[ImGuiKey_PageDown] = static_cast<uint32_t>(Key::PageDown);
			io.KeyMap[ImGuiKey_Home] = static_cast<uint32_t>(Key::Home);
			io.KeyMap[ImGuiKey_End] = static_cast<uint32_t>(Key::Home);
			io.KeyMap[ImGuiKey_Insert] = static_cast<uint32_t>(Key::Insert);
			io.KeyMap[ImGuiKey_Delete] = static_cast<uint32_t>(Key::Delete);
			io.KeyMap[ImGuiKey_Backspace] = static_cast<uint32_t>(Key::Backspace);
			io.KeyMap[ImGuiKey_Space] = static_cast<uint32_t>(Key::Space);
			io.KeyMap[ImGuiKey_Enter] = static_cast<uint32_t>(Key::Enter);
			io.KeyMap[ImGuiKey_Escape] = static_cast<uint32_t>(Key::Escape);
			io.KeyMap[ImGuiKey_KeyPadEnter] = static_cast<uint32_t>(Key::KPEnter);
			io.KeyMap[ImGuiKey_A] = static_cast<uint32_t>(Key::A);
			io.KeyMap[ImGuiKey_C] = static_cast<uint32_t>(Key::C);
			io.KeyMap[ImGuiKey_V] = static_cast<uint32_t>(Key::V);
			io.KeyMap[ImGuiKey_X] = static_cast<uint32_t>(Key::X);
			io.KeyMap[ImGuiKey_Y] = static_cast<uint32_t>(Key::Y);
			io.KeyMap[ImGuiKey_Z] = static_cast<uint32_t>(Key::Z);
		}

		void handleEvent(const InputEvent& event) {
			ImGuiIO& io = ImGui::GetIO();

			switch (event.type) {
			case InputEventType::Char:
				if ((event.text.unicode >= ' ') && (event.text.unicode != 127)) {
					io.AddInputCharacter(event.codepoint);
				}
				break;
			case InputEventType::KeyPress:
				io.KeysDown[static_cast<uint32_t>(event.key.getKey())] = true;

				io.KeyCtrl = io.KeysDown[static_cast<uint32_t>(Key::LCtrl)] || io.KeysDown[static_cast<uint32_t>(Key::RCtrl)];
				io.KeyShift = io.KeysDown[static_cast<uint32_t>(Key::LShift)] || io.KeysDown[static_cast<uint32_t>(Key::RShift)];
				io.KeyAlt = io.KeysDown[static_cast<uint32_t>(Key::LAlt)] || io.KeysDown[static_cast<uint32_t>(Key::RAlt)];
				io.KeySuper = io.KeysDown[static_cast<uint32_t>(Key::LSystem)] || io.KeysDown[static_cast<uint32_t>(Key::RSystem)];
				break;
			case InputEventType::KeyRelease:
				io.KeysDown[static_cast<uint32_t>(event.key.getKey())] = false;

				io.KeyCtrl = io.KeysDown[static_cast<uint32_t>(Key::LCtrl)] || io.KeysDown[static_cast<uint32_t>(Key::RCtrl)];
				io.KeyShift = io.KeysDown[static_cast<uint32_t>(Key::LShift)] || io.KeysDown[static_cast<uint32_t>(Key::RShift)];
				io.KeyAlt = io.KeysDown[static_cast<uint32_t>(Key::LAlt)] || io.KeysDown[static_cast<uint32_t>(Key::RAlt)];
				io.KeySuper = io.KeysDown[static_cast<uint32_t>(Key::LSystem)] || io.KeysDown[static_cast<uint32_t>(Key::RSystem)];
				break;
			case InputEventType::MouseMove:
				io.MousePos = ImVec2(event.mouse.position.x, event.mouse.position.y);
				mouseMoved = true;
				break;
			case InputEventType::MousePress:
				io.MousePos = ImVec2(event.mouse.position.x, event.mouse.position.y);
				mousePressed[event.mouse.firstSetIndex()] = true;
				break;
			case InputEventType::MouseRelease:
				io.MousePos = ImVec2(event.mouse.position.x, event.mouse.position.y);
				break;
			case InputEventType::Scroll:
				if (io.KeyShift) {
					// Flip axes
					io.MouseWheelH += (float)event.scroll.y;
					io.MouseWheel += (float)event.scroll.x;
				}
				else {
					io.MouseWheelH += (float)event.scroll.x;
					io.MouseWheel += (float)event.scroll.y;
				}
				break;
			case InputEventType::Resized:
				break;
			default:
				break;
			}

			inputState.merge(event);
		}


	private:
		std::array<bool, 8> mousePressed;
		std::array<bool, 8> touchPressed;
		bool mouseMoved;
		InputState inputState;
	};
};