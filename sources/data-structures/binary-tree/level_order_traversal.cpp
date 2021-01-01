#include "tree_node.cpp"

#include <queue>
#include <vector>

auto levelOrder(const std::shared_ptr<TreeNode>& root) -> std::vector<std::vector<int>> {
	std::vector<std::vector<int>> result;

	if (root == nullptr) {
		return result;
	}

	std::shared_ptr<TreeNode> cur_node;
	std::queue<std::shared_ptr<TreeNode>> path;
	path.push(root);
	while (!path.empty()) {

		int size_level = path.size();
		std::vector<int> nodes_level(size_level);
		for (int i = 0; i < size_level; ++i) {
			cur_node = path.front();
			if (cur_node->left != nullptr) {
				path.push(cur_node->left);
			}
			if (cur_node->right != nullptr) {
				path.push(cur_node->right);
			}
			nodes_level[i] = cur_node->val;
			path.pop();
		}

		result.push_back(nodes_level);
	}

	return result;
}
