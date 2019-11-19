struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

char* Serialize(TreeNode* root) {
	char* result = nullptr;
	if (root == nullptr) {
		return result;
	}
	string str;
	Serialize(root, str);
	result = new char[str.length() + 1];
	int i = 0;
	for (i = 0; i < str.length(); i++) {
		result[i] = str[i];
	}
	result[i] = '\0';
	return result;
}

void Serialize(TreeNode* root, string& str) {
	if (root == nullptr) {
		str += '#';
		return;
	}
	string r = to_string(root->val);
	str += r;
	str += ',';
	Serialize(root->left, str);
	Serialize(root->right, str);
}
