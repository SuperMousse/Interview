int firstUniqChar(string s) {
    unordered_map<char, int> hash;
    for (int i = 0; i < s.size(); ++i) {
        (hash.count(s[i]) == 0) ? hash[s[i]] == 0 : (hash[s[i]] += 1);
    }
    for (int i = 0; i < s.size(); ++i) {
        if (hash[s[i]] == 0) {
            return i;
        }
    }
    return -1;
}
