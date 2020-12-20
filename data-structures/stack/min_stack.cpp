#include <catch2/catch.hpp>


class min_stack {
private:
    std::vector<int> values;
    std::vector<int> min_values;
public:
    min_stack() = default;

    void push(int value) {
        if(values.empty()) {
            min_values.push_back(value);
        } else {
            min_values.push_back(std::min(min_values.back(), value));
        }
        values.push_back(value);
    }

    void pop() {
        values.pop_back();
        min_values.pop_back();
    }

    int top() {
        return values.back();
    }

    int get_min() {
        return min_values.back();
    }
};

TEST_CASE("Min Stack", "[Data Structures]") {
    min_stack *my_min_stack;

    my_min_stack = new min_stack();
    my_min_stack->push(-2);
    my_min_stack->push(0);
    my_min_stack->push(-3);
    REQUIRE(my_min_stack->get_min() == -3);
    my_min_stack->pop();
    REQUIRE(my_min_stack->top() == 0);
    REQUIRE(my_min_stack->get_min() == -2);

    my_min_stack = new min_stack();
    my_min_stack->push(-2);
    my_min_stack->push(0);
    my_min_stack->push(-1);
    REQUIRE(my_min_stack->get_min() == -2);
    REQUIRE(my_min_stack->top() == -1);
    my_min_stack->pop();
    REQUIRE(my_min_stack->get_min() == -2);

}
