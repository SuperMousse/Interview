// 时间复杂度O(N*M)
// 时间复杂度O(M*N)
// 使用前27个质数, 将字母转换成对应质数作为hash code
// 但是这种hash code编码效率比较低, 可以更换更高效的编码方法
class Solution {
public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string> > result;
            if(strs.empty()){
                return result;
            }
            unordered_map<unsigned long, vector<string> > map;
            for (string s : strs) {
                unsigned long key = calHash(s);
                map[key].push_back(s);
            }
            for (auto keyValue : map) {
                result.push_back(keyValue.second);
            }

            for (auto i: result) {
                for (auto j : i) {
                    cout << j << " ";
                }
                cout << endl;
            }

            return result;
        }

        unsigned long calHash(string s) {
            unsigned long hashCode = 1;
            for (char c : s) {
                hashCode *= hashTable[c-'a'];
            }
            return hashCode;
        }
    
private:
        unsigned long hashTable[27] = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43,
                                      47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};

};


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



