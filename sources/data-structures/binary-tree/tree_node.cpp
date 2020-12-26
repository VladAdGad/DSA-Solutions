#include <memory>

class TreeNode {
public:
	int val{0};
	std::shared_ptr<TreeNode> left, right;

	TreeNode() : left(nullptr), right(nullptr) {}
	TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(char x, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right) : val(x), left(std::move(left)), right(std::move(right)) {}
};
