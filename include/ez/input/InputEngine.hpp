#pragma once
#include <string_view>
#include <ez/input/InputEvent.hpp>
#include <ez/input/KeyMap.hpp>
#include <ez/input/OperatorRegistry.hpp>

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

		template<typename context_t>
		bool handleEvent(InputEvent ev, context_t& context, OperatorRegistry<context_t>& ops) {
			bool dispatch = updateEventState(ev);
			if (dispatch) {
				if (inModal()) {
					auto found = ops.find(modalName);
					assert(found != ops.end());

					Operator<context_t>& modalOp = ops.getOperator(found);

					OpResult result = modalOp.modal(eventState, context);
					switch (result) {
					case OpResult::Cancelled:
					case OpResult::Finished:
						_inModal = false;
						modalName = std::string_view{};
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

					for (std::string_view name : found) {
						auto location = ops.find(name);
						assert(location != ops.end());

						Operator<context_t>& currentOp = ops.getOperator(location);

						if (currentOp.poll()) {
							OpResult result = currentOp.invoke(eventState, context);
							switch (result) {
							case OpResult::PassThrough:
								continue;
							case OpResult::Cancelled:
							case OpResult::Finished:
								return true;
							case OpResult::Modal:
								modalName = name;
								_inModal = true;
								return true;
							}
						}
					}

					return false;
				}
			}
			else {
				return false;
			}
		};

		std::string_view modalOperator() const noexcept;
		bool inModal() const;

		void syncState(const InputEngine & other);
	private:
		bool _inModal;
		std::string_view modalName;

		int pressCount;
		Mouse buttonPressed;
		
		InputState eventState;

		KeyMap * hotkeys;
		bool updateEventState(const InputEvent & ev);
	};
}