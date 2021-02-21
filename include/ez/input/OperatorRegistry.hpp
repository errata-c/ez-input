#pragma once
#include <unordered_map>
#include <memory>
#include <iterator>
#include <functional>
#include <string_view>

#include <ez/input/Operator.hpp>

namespace ez {
	template<typename context_t>
	class OperatorRegistry {
	public:
		using operator_t = Operator<context_t>;

		struct Element {
			std::string_view name;
			std::size_t hash;
			std::unique_ptr<operator_t> op;
		};

		using container_t = std::unordered_map<std::size_t, Element>;
		using iterator = typename container_t::iterator;
		using const_iterator = typename container_t::const_iterator;

		OperatorRegistry() = default;
		OperatorRegistry(const OperatorRegistry&) = default;
		OperatorRegistry(OperatorRegistry&&) noexcept = default;
		~OperatorRegistry() = default;

		OperatorRegistry& operator=(OperatorRegistry&&) noexcept = default;
		OperatorRegistry& operator=(const OperatorRegistry&) = default;

		std::size_t size() const noexcept {
			return elements.size();
		};
		bool empty() const noexcept {
			return elements.size();
		};

		bool add(operator_t* op) {
			return add(std::unique_ptr<operator_t>(op));
		};
		bool add(std::unique_ptr<operator_t>&& op) {
			std::string_view name = op->name();

			std::size_t hash = std::hash<std::string_view>{}(name);
			if (elements.find(hash) != elements.end()) {
				return false;
			}
			else {
				elements[hash] = Element{
					name,
					hash,
					std::move(op)
				};
				return true;
			}
		};
		bool remove(std::string_view name) {
			iterator it = find(name);
			if (it != end()) {
				erase(it);
				return true;
			}
			else {
				return false;
			}
		};
		void clear() {
			elements.clear();
		};

		operator_t& getOperator(const_iterator location) {
			assert(location != end());
			return const_cast<operator_t&>(*location->second.op);
		};
		const operator_t& getOperator(const_iterator location) const {
			assert(location != end());
			return *(location->second.op);
		};

		const_iterator find(std::string_view name) const noexcept {
			std::size_t hash = std::hash<std::string_view>{}(name);
			return elements.find(hash);
		};
		bool contains(std::string_view name) const noexcept {
			return find(name) != end();
		};

		const_iterator erase(const_iterator iter) {
			return elements.erase(iter);
		};
		const_iterator erase(const_iterator first, const_iterator last) {
			return elements.erase(first, last);
		};

		const_iterator begin() const noexcept {
			return elements.begin();
		};
		const_iterator end() const noexcept {
			return elements.end();
		};
	private:

		container_t elements;
	};
}