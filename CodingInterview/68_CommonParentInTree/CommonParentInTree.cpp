// 一、
// 寻找二叉搜索树两个节点的最低公共祖先
// 事实上是在寻找第一个位于两个节点之间的一个节点
// 当前节点大于寻找的两个节点时, 最低公共祖先在左子树上,
// 反之, 在右子树上
// 若第一个介于两个搜索节点之间的节点已经找到, 该节点为两节点的最低公共祖先


struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) { };
};

TreeNode* GetLastCommonParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2) {
	TreeNode* pRes = nullptr;
	if (pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr) {
		return pRes;
	}

	if (pRoot->val > pNode1->val && pRoot->val > pNode2->val) {
		pRes = GetLastCommonParent(pRoot->left, pNode1, pNode2);
	}

	if (pRoot->val < pNode1->val && pRoot->val < pNode2->val) {
		pRes = GetLastCommonParent(pRoot->right, pNode1, pNode2);
	}

	if ((pRoot->val >= pNode1->val && pRoot->val <= pNode2->val) ||
		(pRoot->val >= pNode2->val && pRoot->val <= pNode1->val)) {
		return pRoot;
	}
	
}


// 二、
// 普通的树, 寻找两节点的最低公共祖先, 树含有指向父节点的指针
// 转化为求两个链表的第一个共同节点


// 三、
// 普通的树, 寻找两节点的最低公共节点, 树不含有指向父节点的指针
// 判断当前节点的子树中是否含有搜索的节点, 若某节点的子节点中含有待搜索的节点,
// 但其子节点内却不含有待搜索的节点, 则该节点即为最低公共祖先
// 缺点: 搜索存在重复


// 四、
// 普通的树, 寻找两节点的最低公共节点, 树不含有指向父节点的指针, 使用辅助内存
	
struct TreeNode
{
	int                  val;
	vector<TreeNode*>    children;
	TreeNode(int x) :val(x) { };
};

TreeNode* GetLastCommonParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2) {
	TreeNode* pRes = nullptr;
	if (pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr) {
		return pRes;
	}

	list<TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);

	list<TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);

	return GetLastCommonNode(path1, path2);
}

bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path) {
	if (pRoot == pNode) {
		return true;
	}
	path.push_back(pRoot);

	bool found = false;
	vector<TreeNode*>::iterator it = pRoot->children.begin();
	while (!found && it != pRoot->children.end()) {
		found = GetNodePath(*it, pNode, path);
		++it;
	}
	if (!found) {
		path.pop_back();
	}
	return found;
}

TreeNode* GetLastCommonNode(const list<TreeNode*>& path1, const list<TreeNode*>& path2) {
	TreeNode* pLast = nullptr;
	if (path1.empty() || path2.empty()) {
		return pLast;
	}
	list<TreeNode*>::const_iterator it1 = path1.begin();
	list<TreeNode*>::const_iterator it2 = path2.begin();

	while (it1 != path1.end() && it2 != path2.end()) {
		if (*it1 == *it2) {
			pLast = *it1;
		}
		++it1;
		++it2;
	}
	return pLast;
}
