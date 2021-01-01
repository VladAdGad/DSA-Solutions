#include "inorder_traversal.cpp"
#include "level_order_traversal.cpp"
#include "postorder_traversal.cpp"
#include "preorder_traversal.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Traversal", "[data structures][binary tree]") {
	auto root_0 = std::make_shared<TreeNode>(0);
	REQUIRE((root_0->left = std::make_shared<TreeNode>(1))->val == 1);
	REQUIRE((root_0->left->left = std::make_shared<TreeNode>(2))->val == 2);
	REQUIRE((root_0->left->right = std::make_shared<TreeNode>(3))->val == 3);
	REQUIRE((root_0->left->right->left = std::make_shared<TreeNode>(4))->val == 4);
	REQUIRE((root_0->left->right->right = std::make_shared<TreeNode>(5))->val == 5);
	REQUIRE((root_0->right = std::make_shared<TreeNode>(6))->val == 6);
	REQUIRE((root_0->right->right = std::make_shared<TreeNode>(7))->val == 7);
	REQUIRE((root_0->right->right->left = std::make_shared<TreeNode>(8))->val == 8);

	auto root_1 = std::make_shared<TreeNode>(0);
	REQUIRE((root_1->left = std::make_shared<TreeNode>(1))->val);
	REQUIRE((root_1->left->left = std::make_shared<TreeNode>(2))->val == 2);
	REQUIRE((root_1->left->left->left = std::make_shared<TreeNode>(3))->val == 3);
	REQUIRE((root_1->left->left->left->left = std::make_shared<TreeNode>(4))->val == 4);

	SECTION("preorder traversal") {
		const std::vector<int> expected_0{0, 1, 2, 3, 4, 5, 6, 7, 8};
		const std::vector<int> expected_1{0, 1, 2, 3, 4};

		SECTION("recursive preorder traversal") {
			REQUIRE_THAT(recursivePreorderTraversal(root_0), Catch::Matchers::Equals(expected_0));
			REQUIRE_THAT(recursivePreorderTraversal(root_1), Catch::Matchers::Equals(expected_1));
		}
		SECTION("iterative preorder traversal") {
			REQUIRE_THAT(iterativePreorderTraversal(root_0), Catch::Matchers::Equals(expected_0));
			REQUIRE_THAT(iterativePreorderTraversal(root_1), Catch::Matchers::Equals(expected_1));
		}
	}

	SECTION("inorder traversal") {
		const std::vector<int> expected_0{2, 1, 4, 3, 5, 0, 6, 8, 7};
		const std::vector<int> expected_1{4, 3, 2, 1, 0};

		SECTION("recursive inorder traversal") {
			REQUIRE_THAT(recursiveInorderTraversal(root_0), Catch::Matchers::Equals(expected_0));
			REQUIRE_THAT(recursiveInorderTraversal(root_1), Catch::Matchers::Equals(expected_1));
		}
		SECTION("iterative inorder traversal") {
			REQUIRE_THAT(iterativeInorderTraversal(root_0), Catch::Matchers::Equals(expected_0));
			REQUIRE_THAT(iterativeInorderTraversal(root_1), Catch::Matchers::Equals(expected_1));
		}
	}

	SECTION("postorder traversal") {
		const std::vector<int> expected_0{2, 4, 5, 3, 1, 8, 7, 6, 0};
		const std::vector<int> expected_1{4, 3, 2, 1, 0};

		SECTION("recursive postorder traversal") {
			REQUIRE_THAT(recursivePostorderTraversal(root_0), Catch::Matchers::Equals(expected_0));
			REQUIRE_THAT(recursivePostorderTraversal(root_1), Catch::Matchers::Equals(expected_1));
		}
		SECTION("iterative postorder traversal") {
			REQUIRE_THAT(iterativePostorderTraversal(root_0), Catch::Matchers::Equals(expected_0));
			REQUIRE_THAT(iterativePostorderTraversal(root_1), Catch::Matchers::Equals(expected_1));
		}
	}

	SECTION("level-order traversal") {
		const std::vector<std::vector<int>> expected_0{{0}, {1, 6}, {2, 3, 7}, {4, 5, 8}};
		const std::vector<std::vector<int>> expected_1{{0}, {1}, {2}, {3}, {4}};

		SECTION("recursive preorder traversal") {
			REQUIRE_THAT(levelOrder(root_0), Catch::Matchers::Equals(expected_0));
			REQUIRE_THAT(levelOrder(root_1), Catch::Matchers::Equals(expected_1));
		}
	}
}
