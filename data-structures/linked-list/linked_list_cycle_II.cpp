#include <catch2/catch.hpp>
#include "singly_list_node.hpp"


singly_list_node *detectCycle(singly_list_node *head) {
    singly_list_node *walker = head, *runner = head;

    while (runner != nullptr && runner->next != nullptr) {
        runner = runner->next->next;
        walker = walker->next;

        if (runner == walker) {
            singly_list_node *seeker = head;

            while (seeker != walker) {
                walker = walker->next;
                seeker = seeker->next;
            }

            return walker;
        }
    }

    return nullptr;
}

TEST_CASE("Linked List Cycle II", "[Data Structures]") {

    SECTION("linked list cycle") {
        auto *list_node_0 = new singly_list_node(3);
        auto *list_node_1 = new singly_list_node(2);
        auto *list_node_2 = new singly_list_node(0);
        auto *list_node_3 = new singly_list_node(-4);

        list_node_0->next = list_node_1;
        list_node_1->next = list_node_2;
        list_node_2->next = list_node_3;
        list_node_3->next = list_node_1;
        REQUIRE(detectCycle(list_node_0) == list_node_1);
    }

    SECTION("linked list non-cycle") {
        auto *list_node_0 = new singly_list_node(1);
        auto *list_node_1 = new singly_list_node(2);

        list_node_0->next = list_node_1;
        REQUIRE(detectCycle(list_node_0) == nullptr);
    }

    SECTION("linked list non-cycle with one element") {
        auto *list_node_0 = new singly_list_node(1);

        REQUIRE(detectCycle(list_node_0) == nullptr);
    }

    SECTION("pass nullptr") {
        REQUIRE(detectCycle(nullptr) == nullptr);
    }

}
