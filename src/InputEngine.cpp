#include <ez/input/InputEngine.hpp>

#include <algorithm>
#include <iostream>
#include <cassert>

namespace ez {
	InputEngine::InputEngine() 
		: _inModal(false)
		, hotkeys(nullptr)
		, pressCount(0)
		, buttonPressed{}
	{}

	bool InputEngine::inModal() const {
		return _inModal;
	}

	void InputEngine::setKeyMap(KeyMap& keys) {
		hotkeys = &keys;
	}

	bool InputEngine::hasKeyMap() const {
		return hotkeys != nullptr;
	}
	KeyMap& InputEngine::getKeyMap() {
		assert(hasKeyMap());
		return *hotkeys;
	}
	const KeyMap& InputEngine::getKeyMap() const {
		assert(hasKeyMap());
		return *hotkeys;
	}

	bool InputEngine::updateEventState(const InputEvent& ev) {
		bool repeat = false;
		if (ev.type == InEv::KeyPress && ev.key.code == eventState.key.held) {
			repeat = true;
		}

		eventState.merge(ev);
		switch (ev.type) {
		case InEv::Char:
		case InEv::Scroll:
		case InEv::TouchPress:
		case InEv::TouchRelease:
			return true;
		case InEv::TouchMove:
		case InEv::MouseMove:
			return inModal();
		
		case InEv::KeyPress:
			if (ev.key.isModifier()) {
				return false;
			}
			if (repeat) {
				eventState.type = InputEventType::KeyRepeat;
			}
			return true;
		case InEv::KeyRelease:
			return !ev.key.isModifier();
		default:
			return false;
		}
	}

	std::string_view InputEngine::modalOperator() const noexcept {
		return modalName;
	}

	/*
	bool InputEngine::handleEvent(InputEvent event) {
		bool result = false;
		if (hotkeys == nullptr) {
			return result;
		}

		using ev_t = ez::InputEventType;

		switch (event.type) {
		case ev_t::Char:
			eventState.merge(event);
			result = dispatchEvent();
			break;
		case ev_t::KeyPress: {
			if (event.key.isModifier()) {
				eventState.merge(event);
				return result;
			}
			if (eventState.key.held == event.key.code) {
				event.type = InputEventType::KeyRepeat;
			}
			eventState.merge(event);
			result = dispatchEvent();
			break;
		}
		case ev_t::KeyRelease:
			eventState.merge(event);
			if (event.key.isModifier()) {
				return result;
			}
			result = dispatchEvent();
			break;
		case ev_t::MousePress:
			eventState.merge(event);
			result = dispatchEvent();
			break;
		case ev_t::MouseRelease: {
			InputEventType priorType = eventState.type;

			eventState.merge(event);
			result = dispatchEvent();

			if (eventState.mouse.justPressed == eventState.mouse.justReleased) {
				if (priorType == InputEventType::MouseClick) {
					event.type = InputEventType::MouseClick2;
					eventState.merge(event);
					result = dispatchEvent() || result;
				}
				else if(priorType != InputEventType::MouseClick2) {
					event.type = InputEventType::MouseClick;
					eventState.merge(event);
					result = dispatchEvent() || result;
				}
			}
			break;
		}
		case ev_t::MouseMove:
			eventState.merge(event);
			if (inModal()) {
				result = dispatchEvent();
			}
			break;
		case ev_t::Scroll:
			eventState.merge(event);
			result = dispatchEvent();
			break;
		case ev_t::TouchPress:
			eventState.merge(event);
			result = dispatchEvent();
			break;
		case ev_t::TouchRelease:
			eventState.merge(event);
			result = dispatchEvent();
			break;
		case ev_t::TouchMove:
			eventState.merge(event);
			if (inModal()) {
				result = dispatchEvent();
			}
			break;
		default:
			eventState.merge(event);
			break;
		}

		return result;
	}

	bool InputEngine::dispatchEvent() {
		if (_inModal) {
			OpResult result = modalOp->modal(eventState);
			switch (result) {
			case OpResult::Cancelled:
			case OpResult::Finished:
				_inModal = false;
				modalOp = nullptr;
				break;
			case OpResult::PassThrough:
			case OpResult::Modal:
				break;
			}
			return true;
		}
		else {
			KeyMap::iterator iter = hotkeys->find(eventState.key.mods, eventState.key.held);
			if (iter == hotkeys->end()) {
				return false;
			}
			
			KeyGroup& found = iter->second;

			for (Operator * op : found) {
				assert(op != nullptr);

				if (op->poll()) {
					OpResult result = op->invoke(eventState);
					switch (result) {
					case OpResult::PassThrough:
						continue;
					case OpResult::Cancelled:
					case OpResult::Finished:
						return true;
					case OpResult::Modal:
						modalOp = op;
						_inModal = true;
						return true;
					}
				}
			}

			return false;
		}
	}
	*/

	void InputEngine::syncState(const InputEngine& other) {
		if (!inModal()) {
			pressCount = other.pressCount;
			buttonPressed = other.buttonPressed;
			eventState = other.eventState;
		}
	}
}