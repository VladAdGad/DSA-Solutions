#include "inorder_traversal.cpp"
#include "postorder_traversal.cpp"
#include "preorder_traversal.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Traversal", "[data structures][binary tree]") {
	auto root = std::make_shared<TreeNode>(0);
	root->left = std::make_shared<TreeNode>(1);
	root->left->left = std::make_shared<TreeNode>(2);
	root->left->right = std::make_shared<TreeNode>(3);
	root->left->right->left = std::make_shared<TreeNode>(4);
	root->left->right->right = std::make_shared<TreeNode>(5);
	root->right = std::make_shared<TreeNode>(6);
	root->right->right = std::make_shared<TreeNode>(7);
	root->right->right->left = std::make_shared<TreeNode>(8);

	REQUIRE(root->val == 0);
	REQUIRE(root->left->val == 1);
	REQUIRE(root->left->left->val == 2);
	REQUIRE(root->left->right->val == 3);
	REQUIRE(root->left->right->left->val == 4);
	REQUIRE(root->left->right->right->val == 5);
	REQUIRE(root->right->val == 6);
	REQUIRE(root->right->right->val == 7);
	REQUIRE(root->right->right->left->val == 8);

	SECTION("preorder traversal") {
		const std::vector<int> expected{0, 1, 2, 3, 4, 5, 6, 7, 8};

		SECTION("recursive preorder traversal") {
			REQUIRE_THAT(recursivePreorderTraversal(root), Catch::Matchers::Equals(expected));
		}
		SECTION("iterative preorder traversal") {
			REQUIRE_THAT(iterativePreorderTraversal(root), Catch::Matchers::Equals(expected));
		}
	}

	SECTION("inorder traversal") {
		const std::vector<int> expected{2, 1, 4, 3, 5, 0, 6, 8, 7};

		SECTION("recursive inorder traversal") {
			REQUIRE_THAT(recursiveInorderTraversal(root), Catch::Matchers::Equals(expected));
		}
		SECTION("iterative inorder traversal") {
			REQUIRE_THAT(iterativeInorderTraversal(root), Catch::Matchers::Equals(expected));
		}
	}

	SECTION("postorder traversal") {
		const std::vector<int> expected{2, 4, 5, 3, 1, 8, 7, 6, 0};

		SECTION("recursive postorder traversal") {
			REQUIRE_THAT(recursivePostorderTraversal(root), Catch::Matchers::Equals(expected));
		}
		SECTION("iterative postorder traversal") {
			REQUIRE_THAT(iterativePostorderTraversal(root), Catch::Matchers::Equals(expected));
		}
	}
}
