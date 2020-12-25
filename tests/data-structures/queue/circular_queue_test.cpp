#include "circular_queue.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Circular Queue", "[Data Structures]") {
	SECTION("1") {
		auto my_circular_queue = std::make_unique<CircularQueue>(3);
		REQUIRE(my_circular_queue->enqueue(1));
		REQUIRE(my_circular_queue->enqueue(2));
		REQUIRE(my_circular_queue->enqueue(3));
		REQUIRE_FALSE(my_circular_queue->enqueue(4));
		REQUIRE(my_circular_queue->rear() == 3);
		REQUIRE(my_circular_queue->isFull());
		REQUIRE(my_circular_queue->dequeue());
		REQUIRE(my_circular_queue->enqueue(4));
		REQUIRE(my_circular_queue->rear() == 4);
	}

	SECTION("2") {
		auto my_circular_queue = std::make_unique<CircularQueue>(10);
		REQUIRE(my_circular_queue->enqueue(5));
		REQUIRE(my_circular_queue->dequeue());
		REQUIRE(my_circular_queue->front() == -1);
		REQUIRE(my_circular_queue->rear() == -1);
		REQUIRE_FALSE(my_circular_queue->isFull());
		REQUIRE(my_circular_queue->isEmpty());
	}

	SECTION("3") {
		auto my_circular_queue = std::make_unique<CircularQueue>(6);
		REQUIRE(my_circular_queue->enqueue(6));
		REQUIRE(my_circular_queue->rear() == 6);
		REQUIRE(my_circular_queue->rear() == 6);
		REQUIRE(my_circular_queue->dequeue());
		REQUIRE(my_circular_queue->rear() == -1);
		REQUIRE_FALSE(my_circular_queue->dequeue());
		REQUIRE(my_circular_queue->front() == -1);
		REQUIRE_FALSE(my_circular_queue->dequeue());
		REQUIRE_FALSE(my_circular_queue->dequeue());
		REQUIRE_FALSE(my_circular_queue->dequeue());
	}

	SECTION("4") {
		auto my_circular_queue = std::make_unique<CircularQueue>(8);
		REQUIRE(my_circular_queue->enqueue(3));
		REQUIRE(my_circular_queue->enqueue(9));
		REQUIRE(my_circular_queue->enqueue(5));
		REQUIRE(my_circular_queue->enqueue(0));
		REQUIRE(my_circular_queue->dequeue());
		REQUIRE(my_circular_queue->dequeue());
		REQUIRE_FALSE(my_circular_queue->isEmpty());
		REQUIRE_FALSE(my_circular_queue->isEmpty());
		REQUIRE(my_circular_queue->rear() == 0);
		REQUIRE(my_circular_queue->rear() == 0);
		REQUIRE(my_circular_queue->dequeue());
	}

	SECTION("5") {
		auto my_circular_queue = std::make_unique<CircularQueue>(4);
		REQUIRE(my_circular_queue->enqueue(2));
		REQUIRE(my_circular_queue->enqueue(3));
		REQUIRE(my_circular_queue->enqueue(4));
		REQUIRE(my_circular_queue->dequeue());
		REQUIRE(my_circular_queue->dequeue());
		REQUIRE(my_circular_queue->enqueue(5));
		REQUIRE(my_circular_queue->enqueue(3));
		REQUIRE(my_circular_queue->front() == 4);
		REQUIRE(my_circular_queue->enqueue(5));
		REQUIRE(my_circular_queue->rear() == 5);
		REQUIRE_FALSE(my_circular_queue->enqueue(6));
		REQUIRE_FALSE(my_circular_queue->enqueue(3));
		REQUIRE(my_circular_queue->rear() == 5);
		REQUIRE(my_circular_queue->dequeue());
		REQUIRE(my_circular_queue->front() == 5);
		REQUIRE(my_circular_queue->dequeue());
		REQUIRE(my_circular_queue->front() == 3);
	}
}
