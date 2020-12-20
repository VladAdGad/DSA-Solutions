#include <catch2/catch.hpp>

class doubly_list_node {
public:
    int value;
    doubly_list_node *next, *prev;

    explicit doubly_list_node(int value) {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class doubly_linked_list {
public:
    doubly_list_node *head;
    doubly_list_node *tail;
    int size;

    doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    [[nodiscard]] int get(int index) const {
        if (index >= size) {
            return -1;
        }

        doubly_list_node *current;
        if (index < size / 2) {
            current = head;
            for (; index > 0; --index) {
                current = current->next;
            }
        } else {
            current = tail;
            for (index = size - 1 - index; index > 0; --index) {
                current = current->prev;
            }
        }

        return current->value;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    bool add_at_head(int val) {
        auto *new_head = new doubly_list_node(val);

        if (size == 0) {
            head = new_head;
            tail = new_head;
        } else {
            head->prev = new_head;
            new_head->next = head;
            head = new_head;
        }

        size++;
        return true;
    }

    /** Append a node of value val to the last element of the linked list. */
    bool add_at_tail(int val) {
        auto *new_tail = new doubly_list_node(val);

        if (size == 0) {
            tail = new_tail;
            head = new_tail;
        } else {
            tail->next = new_tail;
            new_tail->prev = tail;
            tail = new_tail;
        }

        size++;
        return true;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    bool add_at_index(int index, int val) {
        if (index > size) {
            return false;
        }

        if (index == size) {
            return add_at_tail(val);
        }

        if (size == 0 || index == 0) {
            return add_at_head(val);
        }

        doubly_list_node *current;
        if (index < size / 2) {
            current = head;
            for (; index > 0; --index) {
                current = current->next;
            }
        } else {
            current = tail;
            for (index = size - 1 - index; index > 0; --index) {
                current = current->prev;
            }
        }

        auto *new_node = new doubly_list_node(val);
        new_node->next = current;
        new_node->prev = current->prev;
        current->prev->next = new_node;
        current->prev = new_node;
        size++;
        return true;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    bool delete_at_index(int index) {
        if (size == 0 || index >= size) {
            return false;
        }

        if (index == 0) {
            head->prev = nullptr;
            head = head->next;
            size--;
            return true;
        }

        if (index == size - 1) {
            tail = tail->prev;
            tail->next->prev = nullptr;
            tail->next = nullptr;
            size--;
            return true;
        }

        doubly_list_node *current;
        if (index < size / 2) {
            current = head;
            for (; index > 0; --index) {
                current = current->next;
            }
        } else {
            current = tail;
            for (index = size - 1 - index; index > 0; --index) {
                current = current->prev;
            }
        }

        current->prev->next = current->next;
        current->prev->next->prev = current->prev;
        current->next = nullptr;
        current->prev = nullptr;
        size--;
        return true;
    }

};


TEST_CASE("Doubly Linked List", "[Data Structures]") {
    doubly_linked_list *linked_ist;

    SECTION("get using empty linked list") {
        linked_ist = new doubly_linked_list();
        REQUIRE(linked_ist->size == 0);
        REQUIRE(linked_ist->get(0) == -1);
    }

    SECTION("get using index which is higher than size of linked list") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        REQUIRE(linked_ist->size == 1);
        REQUIRE(linked_ist->get(1) == -1);
    }

    SECTION("get last element") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_head(1);
        linked_ist->add_at_head(2);
        REQUIRE(linked_ist->size == 3);
        REQUIRE(linked_ist->get(2) == 0);
    }

    SECTION("get first element") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_head(1);
        linked_ist->add_at_head(2);
        REQUIRE(linked_ist->size == 3);
        REQUIRE(linked_ist->get(0) == 2);
    }

    SECTION("get middle element") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_head(1);
        linked_ist->add_at_head(2);
        REQUIRE(linked_ist->size == 3);
        REQUIRE(linked_ist->get(1) == 1);
    }

    SECTION("add_at_head with empty linked list") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(7);
        REQUIRE(linked_ist->size == 1);
        REQUIRE(linked_ist->get(0) == 7);
        REQUIRE(linked_ist->head == linked_ist->tail);
    }

    SECTION("add_at_head multiple times") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_head(1);
        REQUIRE(linked_ist->size == 2);
        REQUIRE(linked_ist->head != linked_ist->tail);
        REQUIRE(linked_ist->get(0) == 1);
        REQUIRE(linked_ist->get(1) == 0);
        REQUIRE(linked_ist->head->value == 1);
        REQUIRE(linked_ist->tail->value == 0);
    }

    SECTION("add_at_tail with empty linked list") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_tail(0);
        REQUIRE(linked_ist->size == 1);
        REQUIRE(linked_ist->get(0) == 0);
        REQUIRE(linked_ist->tail == linked_ist->head);
    }

    SECTION("add_at_tail multiple times") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_tail(0);
        linked_ist->add_at_tail(1);
        REQUIRE(linked_ist->size == 2);
        REQUIRE(linked_ist->head != linked_ist->tail);
        REQUIRE(linked_ist->get(0) == 0);
        REQUIRE(linked_ist->get(1) == 1);
        REQUIRE(linked_ist->head->value == 0);
        REQUIRE(linked_ist->tail->value == 1);
    }

    SECTION("add_at_index using index which is higher than size of linked list") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        REQUIRE(linked_ist->size == 1);
        REQUIRE_FALSE(linked_ist->add_at_index(2, 1));
        REQUIRE(linked_ist->size == 1);
    }

    SECTION("add_at_index using index as same as size of linked list") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        REQUIRE(linked_ist->size == 1);
        REQUIRE(linked_ist->add_at_index(1, 1));
        REQUIRE(linked_ist->size == 2);
        REQUIRE(linked_ist->tail->value == 1);
    }

    SECTION("add_at_index using index zero (first element) with empty linked list") {
        linked_ist = new doubly_linked_list();
        REQUIRE(linked_ist->size == 0);
        REQUIRE(linked_ist->add_at_index(0, 0));
        REQUIRE(linked_ist->size == 1);
        REQUIRE(linked_ist->head == linked_ist->tail);
    }

    SECTION("add_at_index using index zero (first element)") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        REQUIRE(linked_ist->size == 1);
        REQUIRE(linked_ist->add_at_index(0, 1));
        REQUIRE(linked_ist->size == 2);
        REQUIRE(linked_ist->head->value == 1);
        REQUIRE(linked_ist->tail->value == 0);
    }

    SECTION("add_at_index where index is less as twice then size") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_head(1);
        linked_ist->add_at_head(2);
        linked_ist->add_at_head(3);
        linked_ist->add_at_head(4);
        REQUIRE(linked_ist->size == 5);
        REQUIRE(linked_ist->add_at_index(1, 5));
        REQUIRE(linked_ist->size == 6);
        REQUIRE(linked_ist->get(1) == 5);
    }

    SECTION("add_at_index where index is more as size divided twice") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_head(1);
        linked_ist->add_at_head(2);
        linked_ist->add_at_head(3);
        linked_ist->add_at_head(4);
        REQUIRE(linked_ist->size == 5);
        REQUIRE(linked_ist->add_at_index(3, 5));
        REQUIRE(linked_ist->size == 6);
        REQUIRE(linked_ist->get(3) == 5);
    }

    SECTION("add_at_index where index is on the middle") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_head(1);
        linked_ist->add_at_head(2);
        linked_ist->add_at_head(3);
        linked_ist->add_at_head(4);
        REQUIRE(linked_ist->size == 5);
        REQUIRE(linked_ist->add_at_index(2, 5));
        REQUIRE(linked_ist->size == 6);
        REQUIRE(linked_ist->get(2) == 5);
    }

    SECTION("delete_at_index when list is empty") {
        linked_ist = new doubly_linked_list();
        REQUIRE(linked_ist->size == 0);
        REQUIRE_FALSE(linked_ist->delete_at_index(7));
        REQUIRE(linked_ist->size == 0);
    }

    SECTION("delete_at_index using index which is higher than size of linked list") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        REQUIRE(linked_ist->size == 1);
        REQUIRE_FALSE(linked_ist->delete_at_index(1));
        REQUIRE(linked_ist->size == 1);
    }

    SECTION("delete_at_index using index which points to the head (zero)") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        REQUIRE(linked_ist->size == 1);
        REQUIRE(linked_ist->delete_at_index(0));
        REQUIRE(linked_ist->size == 0);
        REQUIRE(linked_ist->head == nullptr);
    }

    SECTION("delete_at_index using index which points to the tail") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_tail(1);
        REQUIRE(linked_ist->size == 2);
        REQUIRE(linked_ist->delete_at_index(1));
        REQUIRE(linked_ist->size == 1);
        REQUIRE(linked_ist->tail->value == 0);
    }

    SECTION("delete_at_index where index is less as twice then size") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_head(1);
        linked_ist->add_at_head(2);
        linked_ist->add_at_head(3);
        linked_ist->add_at_head(4);
        REQUIRE(linked_ist->size == 5);
        REQUIRE(linked_ist->delete_at_index(1));
        REQUIRE(linked_ist->size == 4);
        REQUIRE(linked_ist->get(1) == 2);
    }

    SECTION("delete_at_index where index is more as size divided twice") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_head(1);
        linked_ist->add_at_head(2);
        linked_ist->add_at_head(3);
        linked_ist->add_at_head(4);
        REQUIRE(linked_ist->size == 5);
        REQUIRE(linked_ist->delete_at_index(3));
        REQUIRE(linked_ist->size == 4);
        REQUIRE(linked_ist->get(3) == 0);
    }

    SECTION("delete_at_index where index is on the middle") {
        linked_ist = new doubly_linked_list();
        linked_ist->add_at_head(0);
        linked_ist->add_at_head(1);
        linked_ist->add_at_head(2);
        linked_ist->add_at_head(3);
        linked_ist->add_at_head(4);
        REQUIRE(linked_ist->size == 5);
        REQUIRE(linked_ist->delete_at_index(2));
        REQUIRE(linked_ist->size == 4);
        REQUIRE(linked_ist->get(2) == 1);
    }

}
