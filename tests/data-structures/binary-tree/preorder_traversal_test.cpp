#include "preorder_traversal.cpp"

#include <catch2/catch.hpp>

TEST_CASE("Preorder Traversal", "[Data Structures]") {
	auto root = std::make_shared<TreeNode>(0);
	root->left = std::make_shared<TreeNode>(1);
	root->left->left = std::make_shared<TreeNode>(2);
	root->left->right = std::make_shared<TreeNode>(3);
	root->left->right->left = std::make_shared<TreeNode>(4);
	root->left->right->right = std::make_shared<TreeNode>(5);
	root->right = std::make_shared<TreeNode>(6);
	root->right->right = std::make_shared<TreeNode>(7);
	root->right->right->left = std::make_shared<TreeNode>(8);

	REQUIRE_THAT(preorderTraversal(root), Catch::Matchers::Equals(std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8}));
}
