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
	SerializeCore(root, str);
	result = new char[str.length() + 1];
	int i = 0;
	for (i = 0; i < str.length(); i++) {
		result[i] = str[i];
	}
	result[i] = '\0';
	return result;
}

void SerializeCore(TreeNode* root, string& str) {
	if (root == nullptr) {
		str += '#';
		return;
	}
	string r = to_string(root->val);
	str += r;
	str += ',';
	SerializeCore(root->left, str);
	SerializeCore(root->right, str);
}

TreeNode* Deserialize(char* str) {
	TreeNode* root = nullptr;
	if (str == nullptr) {
		return root;
	}
	root = DeserializeCore(&str);
	return root;
}


TreeNode* DeserializeCore(char** str) { // 递归时字符串指针还需要向后移动, 若只是使用指针则无法影响函数外部
	if (str == nullptr || *str == nullptr) {
		return nullptr;
	}
	if (**str == '#') {
		++(*str);
		return nullptr;
	}
	int num = 0;
	while (**str != '\0' && **str != ',') {
		num = num * 10 + ((**str) - '0');
		++(*str); // 跳过逗号
	}

	TreeNode* root = new TreeNode(num);
	if (**str == '\0') {
		return root;
	}
	else {
		++(*str);
	}
	root->left = DeserializeCore(str);
	root->right = DeserializeCore(str);
	return root;
}

