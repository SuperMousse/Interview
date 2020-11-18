// Given a string, sort it in decreasing order based on the frequency of characters.

string frequencySort(string s) {
    int length = s.size();
    unordered_map<char, int> hash;
    vector<string> bucket(length + 1, "");
    string result = "";
    for (int i = 0; i < s.size(); ++i) {
        hash[s[i]]++; // count frequency;
    }
    // put character into frequency bucket
    unordered_map<char, int>::iterator iter;
    for (iter = hash.begin(); iter != hash.end(); ++iter) {
        char c = iter->first;
        int n = iter->second;
        bucket[n].append(n, c);
    }
    for (int i = length + 1; i >= 0; --i) {
        if (!bucket[i].empty()) {
            result.append(bucket[i]);
        }
    }
    return result;
}
