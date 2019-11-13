struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

bool Equal(double num1, double num2) {
	if (abs(num1 - num2) < 1e-7) {
		return true;
	}
	else {
		return false;
	}

}

bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (pRoot2 == nullptr) {
		return true;
	}
	if (pRoot1 == nullptr) {
		return false;
	}
	if (!Equal(pRoot1->val, pRoot2->val)) {
		return false;
	}
	return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool result = false;
	if (pRoot1 != nullptr && pRoot2 != nullptr) {
		if (Equal(pRoot1->val, pRoot2->val)) {
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		}
		if (!result) {
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		if (!result) {
			result = HasSubtree(pRoot1->right, pRoot2);
		}
	}
	return result;
}
