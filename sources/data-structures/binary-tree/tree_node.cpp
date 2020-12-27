#ifndef LEETCODE_SOLUTIONS_TREE_NODE_I
#define LEETCODE_SOLUTIONS_TREE_NODE_I

#include <memory>

class TreeNode {
public:
	int val{0};
	std::shared_ptr<TreeNode> left{nullptr};
	std::shared_ptr<TreeNode> right{nullptr};

	TreeNode() = default;
	TreeNode(int x) : val(x) {}
	TreeNode(int x, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right) : val(x), left(std::move(left)), right(std::move(right)) {}
};

#endif  // LEETCODE_SOLUTIONS_TREE_NODE_I
