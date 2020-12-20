#include <catch2/catch.hpp>
#include "singly_list_node.hpp"

bool has_cycle(singly_list_node *head) {
    if (head == nullptr) {
        return false;
    }

    singly_list_node *slow = head;
    singly_list_node *fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

TEST_CASE("Linked List Cycle", "[Data Structures]") {

    SECTION("linked list cycle") {
        auto *list_node_0 = new singly_list_node(0);
        auto *list_node_1 = new singly_list_node(1);

        list_node_0->next = list_node_1;
        list_node_1->next = list_node_0;
        REQUIRE(has_cycle(list_node_0) == true);
    }

    SECTION("linked list non-cycle") {
        auto *list_node_0 = new singly_list_node(1);
        auto *list_node_1 = new singly_list_node(2);

        list_node_0->next = list_node_1;
        REQUIRE(has_cycle(list_node_0) == false);
    }

    SECTION("pass nullptr") {
        REQUIRE(has_cycle(nullptr) == false);
    }

}
