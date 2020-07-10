class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string outString = "";
        serializeCore(root, outString);
        return outString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string inString(data);
        return deserializeCore(inString);
    }

    void serializeCore(TreeNode* root, string& outString) {
        if (root == nullptr) {
            outString.append("#");
            return;
        }
        outString.append(to_string(root->val));
        outString.append(",");
        serializeCore(root->left, outString);
        outString.append(",");
        serializeCore(root->right, outString);
    }

    TreeNode* deserializeCore(string& inString) {
        if (inString[0] == '#') {
            if (inString.size() > 1) {
                inString = inString.substr(2);
                return nullptr;
            }
            return nullptr;
        }
        TreeNode* root = new TreeNode(helper(inString));
        root->left = deserializeCore(inString);
        root->right = deserializeCore(inString);
        return root;
    }

private:
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};
