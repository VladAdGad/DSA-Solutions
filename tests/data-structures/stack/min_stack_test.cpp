#include "min_stack.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Min Stack", "[Data Structures]") {
	SECTION("1") {
    auto min_stack = std::make_unique<MinStack>();
		min_stack->push(-2);
		min_stack->push(0);
		min_stack->push(-3);
		REQUIRE(min_stack->getMin() == -3);
		min_stack->pop();
		REQUIRE(min_stack->top() == 0);
		REQUIRE(min_stack->getMin() == -2);
	}

	SECTION("2") {
		auto min_stack = std::make_unique<MinStack>();
		min_stack->push(-2);
		min_stack->push(0);
		min_stack->push(-1);
		REQUIRE(min_stack->getMin() == -2);
		REQUIRE(min_stack->top() == -1);
		min_stack->pop();
		REQUIRE(min_stack->getMin() == -2);
	}
}