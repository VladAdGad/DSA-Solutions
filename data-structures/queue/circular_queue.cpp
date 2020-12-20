#include <catch2/catch.hpp>


class circular_queue {
private:
    std::vector<int> data;
    int head;
    int tail;

public:
    explicit circular_queue(int size) {
        data = std::vector<int>(size);
        head = -1;
        tail = -1;
    }

    bool enqueue(int value) {
        if (is_full()) {
            return false;
        }
        if (is_empty()) {
            head = 0;
        }
        tail = (tail + 1) % data.capacity();
        data[tail] = value;
        return true;
    }

    bool dequeue() {
        if (is_empty()) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % data.size();
        return true;
    }

    [[nodiscard]] int front() const {
        return is_empty() == false ? data[head] : -1;
    }

    [[nodiscard]] int rear() const {
        return is_empty() == false ? data[tail] : -1;
    }

    [[nodiscard]] bool is_empty() const {
        return head == -1;
    }

    [[nodiscard]] bool is_full() const {
        return ((tail + 1) % data.capacity()) == head;
    }
    
};

TEST_CASE("Circular Queue", "[Data Structures]") {
    circular_queue *my_circular_queue;

    my_circular_queue = new circular_queue(3);
    REQUIRE(my_circular_queue->enqueue(1));
    REQUIRE(my_circular_queue->enqueue(2));
    REQUIRE(my_circular_queue->enqueue(3));
    REQUIRE_FALSE(my_circular_queue->enqueue(4));
    REQUIRE(my_circular_queue->rear() == 3);
    REQUIRE(my_circular_queue->is_full());
    REQUIRE(my_circular_queue->dequeue());
    REQUIRE(my_circular_queue->enqueue(4));
    REQUIRE(my_circular_queue->rear() == 4);

    my_circular_queue = new circular_queue(10);
    REQUIRE(my_circular_queue->enqueue(5));
    REQUIRE(my_circular_queue->dequeue());
    REQUIRE(my_circular_queue->front() == -1);
    REQUIRE(my_circular_queue->rear() == -1);
    REQUIRE_FALSE(my_circular_queue->is_full());
    REQUIRE(my_circular_queue->is_empty());

    my_circular_queue = new circular_queue(6);
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

    my_circular_queue = new circular_queue(8);
    REQUIRE(my_circular_queue->enqueue(3));
    REQUIRE(my_circular_queue->enqueue(9));
    REQUIRE(my_circular_queue->enqueue(5));
    REQUIRE(my_circular_queue->enqueue(0));
    REQUIRE(my_circular_queue->dequeue());
    REQUIRE(my_circular_queue->dequeue());
    REQUIRE_FALSE(my_circular_queue->is_empty());
    REQUIRE_FALSE(my_circular_queue->is_empty());
    REQUIRE(my_circular_queue->rear() == 0);
    REQUIRE(my_circular_queue->rear() == 0);
    REQUIRE(my_circular_queue->dequeue());

    my_circular_queue = new circular_queue(4);
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
