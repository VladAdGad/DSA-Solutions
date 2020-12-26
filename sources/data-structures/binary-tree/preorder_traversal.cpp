#include "tree_node.cpp"

#include <vector>

auto preorderTraversal(const std::shared_ptr<TreeNode>& root) -> std::vector<int> {
	std::vector<int> result;
	if (root == nullptr) {
		return result;
	}

	result.push_back(root->val);

	std::vector<int> concatenate;
	concatenate = preorderTraversal(root->left);
	result.insert(result.end(), concatenate.begin(), concatenate.end());
	concatenate = preorderTraversal(root->right);
	result.insert(result.end(), concatenate.begin(), concatenate.end());

	return result;
}
