#include "tree_node.cpp"

#include <stack>
#include <vector>

class Solution1 {
public:
	auto inorderTraversal(const std::shared_ptr<TreeNode>& root) -> std::vector<int> {
		std::vector<int> result, merge;
		if (root == nullptr) {
			return result;
		}

		merge = inorderTraversal(root->left);
		result.insert(result.end(), merge.begin(), merge.end());

		result.push_back(root->val);

		merge = inorderTraversal(root->right);
		result.insert(result.end(), merge.begin(), merge.end());

		return result;
	}
};

class Solution2 {
public:
	auto inorderTraversal(const std::shared_ptr<TreeNode>& root) -> std::vector<int> {
		std::vector<int> result;
		if (root == nullptr) {
			return result;
		}

		std::stack<std::shared_ptr<TreeNode>> path;
		path.push(root);
		std::shared_ptr<TreeNode> cur_node;
		while (!path.empty()) {
			cur_node = path.top();

			if (cur_node->left != nullptr) {
				path.push(cur_node->left);
				cur_node->left = nullptr;
			} else {
				result.push_back(path.top()->val);
				path.pop();
				if (cur_node->right != nullptr) {
					path.push(cur_node->right);
				}
			}
		}

		return result;
	}
};
