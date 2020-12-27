#include "tree_node.cpp"

#include <stack>
#include <vector>

auto recursivePreorderTraversal(const std::shared_ptr<TreeNode>& root) -> std::vector<int> {
	std::vector<int> result, merge;
	if (root == nullptr) {
		return result;
	}

	result.push_back(root->val);

	merge = recursivePreorderTraversal(root->left);
	result.insert(result.end(), merge.begin(), merge.end());

	merge = recursivePreorderTraversal(root->right);
	result.insert(result.end(), merge.begin(), merge.end());

	return result;
}

auto iterativePreorderTraversal(const std::shared_ptr<TreeNode>& root) -> std::vector<int> {
	std::vector<int> result;
	if (root == nullptr) {
		return result;
	}

	std::stack<std::shared_ptr<TreeNode>> path;
	path.push(root);
	std::shared_ptr<TreeNode> cur_node;
	while (!path.empty()) {
		result.push_back(path.top()->val);
		cur_node = path.top();
		path.pop();
		if (cur_node->right != nullptr) {
			path.push(cur_node->right);
		}
		if (cur_node->left != nullptr) {
			path.push(cur_node->left);
		}
	}

	return result;
}
