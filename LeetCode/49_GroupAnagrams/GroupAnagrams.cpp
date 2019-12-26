// 时间复杂度O(N*排序)
// 使用排序的字符串作为key, 输出作为value

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > result;
    if(strs.empty()){
        return result;
    }
    unordered_map<string, vector<string> > map;
    for (string s : strs) {
        string temp = s;
        sort(temp.begin(), temp.end());
        map[temp].push_back(s);
    }
    for (pair<string, vector<string> > keyValue : map) {
        result.push_back(keyValue.second);
    }
    return result;
}


// 时间复杂度O(N*M)
//
