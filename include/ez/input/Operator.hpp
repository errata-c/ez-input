#pragma once
#include <string_view>
#include <string>
#include <ez/input/InputState.hpp>

namespace ez {
	//! Result of operator execution
	enum class OpResult {
		//! All computation finished.
		Finished,

		//! Enter into modal, or continue running modal.
		Modal,

		//! Cancelled operation, either execution failed, or it was cancelled externally.
		Cancelled,

		//! Pass invoked event through. Does nothing for normal execution, only invocation.
		PassThrough,
	};

	//! Generic operator class, inspired by Blender's operator system.
	template<typename context_t>
	class Operator {
	public:
		using Result = OpResult;

		Operator(std::string_view n)
			: nameStr(n)
		{}

		virtual ~Operator() = default;

		// Determine if the operator can be called.
		virtual bool poll(const context_t& context) const {
			return false;
		};

		//! Run the operator WITHOUT an input event
		/*! To make the execution more generic, you can have attributes set that the execute function
		* then uses to guide behaviour. Then just have invoke/modal fill those attributes
		* with data from the event, and call execute().
		*/
		virtual Result execute(context_t& context) {
			return Result::Finished;
		};

		//! Run the operator WITH an input event
		virtual Result invoke(const InputState& state, context_t& context) {
			return Result::PassThrough;
		};

		//! Operator modal function, used for continuous input operators.
		virtual Result modal(const InputState& state, context_t& context) {
			return Result::Cancelled;
		};

		//! Cancel the operator. Only modal operators can be cancelled. Returns true if successfully cancelled.
		virtual bool cancel(context_t &) {
			return true;
		};

		std::string_view name() const noexcept {
			return nameStr;
		}
	protected:
		std::string nameStr;
	};
};