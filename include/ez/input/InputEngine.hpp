#pragma once
#include <ez/input/InputEvent.hpp>
#include <ez/input/KeyMap.hpp>

namespace ez {

	class InputEngine
	{
	public:
		~InputEngine() = default;

		InputEngine();
		
		void setKeyMap(KeyMap& hotkeys);

		bool hasKeyMap() const;
		KeyMap& getKeyMap();
		const KeyMap& getKeyMap() const;

		bool handleEvent(InputEvent ev);

		bool inModal() const;

		void syncState(const InputEngine & other);
	private:
		bool _inModal;
		Operator* modalOp;

		int pressCount;
		Mouse buttonPressed;
		
		InputState eventState;

		KeyMap * hotkeys;

		bool dispatchEvent();
	};
}