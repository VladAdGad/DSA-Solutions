#include <catch2/catch.hpp>
#include "singly_list_node.hpp"

class singly_linked_list {
public:
    singly_list_node *head;
    singly_list_node *tail;
    int size;

    singly_linked_list() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    [[nodiscard]] int get(int index) const {
        if (index >= size) {
            return -1;
        }

        int count = 0;
        for (singly_list_node *cur = head; count != index + 1; cur = cur->next, ++count) {
            if (count == index) {
                return cur->value;
            }
        }

        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    bool add_at_head(int val) {
        auto *new_node = new singly_list_node(val);

        new_node->next = head;
        head = new_node;

        if (size == 0) {
            tail = head;
        }
        size++;
        return true;
    }

    /** Append a node of value val to the last element of the linked list. */
    bool add_at_tail(int val) {
        auto *new_node = new singly_list_node(val);

        if (size == 0) {
            tail = new_node;
            head = tail;
        } else {
            tail->next = new_node;
            tail = new_node;
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

        int count = 0;
        for (singly_list_node *cur = head; count != index + 1; cur = cur->next, ++count) {
            if (count == index - 1) {
                auto *newNode = new singly_list_node(val);
                newNode->next = cur->next;
                cur->next = newNode;
                size++;
                return true;
            }
        }

        return false;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    bool delete_at_index(int index) {
        if (index >= size) {
            return false;
        }

        if (index == 0) {
            head = head->next;
            size--;
            return true;
        }

        int count = 0;
        for (singly_list_node *cur = head; count != index + 1; cur = cur->next, ++count) {
            if (count == index - 1) {
                cur->next = cur->next->next;
                if (index == size - 1) {
                    tail = cur;
                }
                size--;
                return true;
            }
        }

        return false;
    }
};


TEST_CASE("Singly Linked List", "[Data Structures]") {

    singly_linked_list *linked_list;

    SECTION("get using empty linked list") {
        linked_list = new singly_linked_list();
        REQUIRE(linked_list->get(0) == -1);
    }

    SECTION("get using index which is higher than size of linked list") {
        linked_list = new singly_linked_list();
        linked_list->add_at_head(0);
        REQUIRE(linked_list->get(1) == -1);
    }

    SECTION("get") {
        linked_list = new singly_linked_list();
        linked_list->add_at_head(7);
        REQUIRE(linked_list->get(0) == 7);
    }

    SECTION("add_at_head with empty linked list") {
        linked_list = new singly_linked_list();
        linked_list->add_at_head(7);
        REQUIRE(linked_list->get(0) == 7);
        REQUIRE(linked_list->head == linked_list->tail);
    }

    SECTION("add_at_head multiple times") {
        linked_list = new singly_linked_list();
        linked_list->add_at_head(0);
        linked_list->add_at_head(1);
        REQUIRE(linked_list->head != linked_list->tail);
        REQUIRE(linked_list->get(0) == 1);
        REQUIRE(linked_list->get(1) == 0);
        REQUIRE(linked_list->head->value == 1);
        REQUIRE(linked_list->tail->value == 0);
    }

    SECTION("add_at_tail multiple times") {
        linked_list = new singly_linked_list();
        linked_list->add_at_tail(0);
        linked_list->add_at_tail(1);
        REQUIRE(linked_list->head != linked_list->tail);
        REQUIRE(linked_list->get(0) == 0);
        REQUIRE(linked_list->get(1) == 1);
        REQUIRE(linked_list->head->value == 0);
        REQUIRE(linked_list->tail->value == 1);
    }

    SECTION("add_at_tail with empty linked list") {
        linked_list = new singly_linked_list();
        linked_list->add_at_tail(0);
        REQUIRE(linked_list->get(0) == 0);
        REQUIRE(linked_list->tail == linked_list->head);
    }

    SECTION("add_at_index using index which is higher than size of linked list") {
        linked_list = new singly_linked_list();
        linked_list->add_at_head(0);
        REQUIRE_FALSE(linked_list->add_at_index(2, 1));
    }

    SECTION("add_at_index using index as same as size of linked list") {
        linked_list = new singly_linked_list();
        linked_list->add_at_head(0);
        REQUIRE(linked_list->add_at_index(1, 1));
        REQUIRE(linked_list->tail->value == 1);
    }

    SECTION("add_at_index using index zero (first element) with empty linked list") {
        linked_list = new singly_linked_list();
        REQUIRE(linked_list->add_at_index(0, 0));
        REQUIRE(linked_list->head == linked_list->tail);
    }

    SECTION("add_at_index using index zero (first element)") {
        linked_list = new singly_linked_list();
        REQUIRE(linked_list->add_at_index(0, 0));
        REQUIRE(linked_list->add_at_index(0, 1));
        REQUIRE(linked_list->head->value == 1);
        REQUIRE(linked_list->tail->value == 0);
    }

    SECTION("delete_at_index using index which is higher than size of linked list") {
        linked_list = new singly_linked_list();
        linked_list->add_at_head(0);
        REQUIRE_FALSE(linked_list->delete_at_index(1));
    }

    SECTION("delete_at_index using index which points to the head (zero)") {
        linked_list = new singly_linked_list();
        linked_list->add_at_head(0);
        REQUIRE(linked_list->delete_at_index(0));
        REQUIRE(linked_list->head == nullptr);
    }

    SECTION("delete_at_index using index which points to the tail") {
        linked_list = new singly_linked_list();
        linked_list->add_at_head(0);
        linked_list->add_at_tail(1);
        REQUIRE(linked_list->delete_at_index(1));
        REQUIRE(linked_list->tail->value == 0);
    }

}