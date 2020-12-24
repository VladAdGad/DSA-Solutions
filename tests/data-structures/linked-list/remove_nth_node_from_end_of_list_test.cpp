#include "remove_nth_node_from_end_of_list.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Singly List Node", "[Data Structures]") {
	SECTION("Solution 1") {
		SECTION("Simple Case") {
			auto list_node_1 = std::make_shared<SinglyListNode>(1);
			auto list_node_2 = std::make_shared<SinglyListNode>(2);
			auto list_node_3 = std::make_shared<SinglyListNode>(3);
			auto list_node_4 = std::make_shared<SinglyListNode>(4);

			list_node_1->next = list_node_2;
			list_node_2->next = list_node_3;
			list_node_3->next = list_node_4;

			auto head = removeNthFromEnd1(list_node_1, 2);
			REQUIRE(head == list_node_1);
			REQUIRE(head->next == list_node_2);
			REQUIRE(head->next->next == list_node_4);
		}

		SECTION("Remove First Node") {
			auto list_node_1 = std::make_shared<SinglyListNode>(1);
			auto list_node_2 = std::make_shared<SinglyListNode>(2);
			auto list_node_3 = std::make_shared<SinglyListNode>(3);
			auto list_node_4 = std::make_shared<SinglyListNode>(4);

			list_node_1->next = list_node_2;
			list_node_2->next = list_node_3;
			list_node_3->next = list_node_4;

			auto head = removeNthFromEnd1(list_node_1, 4);
			REQUIRE(head == list_node_2);
			REQUIRE(head->next == list_node_3);
			REQUIRE(head->next->next == list_node_4);
		}

		SECTION("Remove Last Node") {
			auto list_node_1 = std::make_shared<SinglyListNode>(1);
			auto list_node_2 = std::make_shared<SinglyListNode>(2);
			auto list_node_3 = std::make_shared<SinglyListNode>(3);
			auto list_node_4 = std::make_shared<SinglyListNode>(4);

			list_node_1->next = list_node_2;
			list_node_2->next = list_node_3;
			list_node_3->next = list_node_4;

			auto head = removeNthFromEnd1(list_node_1, 1);
			REQUIRE(head == list_node_1);
			REQUIRE(head->next == list_node_2);
			REQUIRE(head->next->next == list_node_3);
			REQUIRE(head->next->next->next == nullptr);
		}
	}

	SECTION("Solution 2") {
    SECTION("Simple Case") {
      auto list_node_1 = std::make_shared<SinglyListNode>(1);
      auto list_node_2 = std::make_shared<SinglyListNode>(2);
      auto list_node_3 = std::make_shared<SinglyListNode>(3);
      auto list_node_4 = std::make_shared<SinglyListNode>(4);

      list_node_1->next = list_node_2;
      list_node_2->next = list_node_3;
      list_node_3->next = list_node_4;

      auto head = removeNthFromEnd2(list_node_1, 2);
      REQUIRE(head == list_node_1);
      REQUIRE(head->next == list_node_2);
      REQUIRE(head->next->next == list_node_4);
    }

    SECTION("Remove First Node") {
      auto list_node_1 = std::make_shared<SinglyListNode>(1);
      auto list_node_2 = std::make_shared<SinglyListNode>(2);
      auto list_node_3 = std::make_shared<SinglyListNode>(3);
      auto list_node_4 = std::make_shared<SinglyListNode>(4);

      list_node_1->next = list_node_2;
      list_node_2->next = list_node_3;
      list_node_3->next = list_node_4;

      auto head = removeNthFromEnd2(list_node_1, 4);
      REQUIRE(head == list_node_2);
      REQUIRE(head->next == list_node_3);
      REQUIRE(head->next->next == list_node_4);
    }

    SECTION("Remove Last Node") {
      auto list_node_1 = std::make_shared<SinglyListNode>(1);
      auto list_node_2 = std::make_shared<SinglyListNode>(2);
      auto list_node_3 = std::make_shared<SinglyListNode>(3);
      auto list_node_4 = std::make_shared<SinglyListNode>(4);

      list_node_1->next = list_node_2;
      list_node_2->next = list_node_3;
      list_node_3->next = list_node_4;

      auto head = removeNthFromEnd2(list_node_1, 1);
      REQUIRE(head == list_node_1);
      REQUIRE(head->next == list_node_2);
      REQUIRE(head->next->next == list_node_3);
      REQUIRE(head->next->next->next == nullptr);
    }
	}
}