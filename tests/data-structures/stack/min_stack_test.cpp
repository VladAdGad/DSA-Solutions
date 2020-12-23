#include "min_stack.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Min Stack", "[Data Structures]") {
	MinStack* my_min_stack = nullptr;

	my_min_stack = new MinStack();
	my_min_stack->push(-2);
	my_min_stack->push(0);
	my_min_stack->push(-3);
	REQUIRE(my_min_stack->getMin() == -3);
	my_min_stack->pop();
	REQUIRE(my_min_stack->top() == 0);
	REQUIRE(my_min_stack->getMin() == -2);

	my_min_stack = new MinStack();
	my_min_stack->push(-2);
	my_min_stack->push(0);
	my_min_stack->push(-1);
	REQUIRE(my_min_stack->getMin() == -2);
	REQUIRE(my_min_stack->top() == -1);
	my_min_stack->pop();
	REQUIRE(my_min_stack->getMin() == -2);
}