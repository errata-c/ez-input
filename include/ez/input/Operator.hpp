#pragma once
#include <string>
#include <ez/input/InputEvent.hpp>
#include <ez/input/InputState.hpp>

namespace ez {
	class KeyMap;

	class Operator {
	public:
		enum class Result {
			// All computation finished.
			Finished,

			// Enter or continue running modal.
			Modal,

			// Cancelled operation, either execution failed, or it was cancelled externally.
			Cancelled,

			// Pass invoked event through. Does nothing for normal execution, only invokation.
			PassThrough,
		};

		Operator(const std::string& n) : name(n)
		{};
		virtual ~Operator() = default;

		// Determine if the operator can be called.
		virtual bool poll() const {
			return false;
		};

		// Run the operator without an event.
		virtual Result execute() {
			return Result::Finished;
		};

		// Run the operator from an event.
		virtual Result invoke(const InputState& ev) {
			return Result::PassThrough;
		};

		// Operator modal function, used for continuous ops.
		virtual Result modal(const InputState& ev) {
			return Result::Cancelled;
		};

		// Cancel the operator. Only called on modal ops.
		virtual bool cancel() {
			return true;
		};

		const std::string& getName() const {
			return name;
		};
	protected:
		std::string name;
	};

	using OpResult = Operator::Result;
};