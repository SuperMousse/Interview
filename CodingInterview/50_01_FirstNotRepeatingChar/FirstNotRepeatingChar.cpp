// 解法一: 此处手动进行了(int)c，但是其实也可以不进行转换, 使用char自动转int的ascii码
int FirstNotRepeatingChar(string str) {
	if (str.empty()) {
		return -1;
	}
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (unsigned int i = 0; i < tableSize; ++i) {
		hashTable[i] = 0;
	}

	for (auto c : str) {
		++hashTable[(int)c];
	}

	for (int i = 0; i < str.size(); ++i) {
		if (hashTable[(int)str[i]] == 1) {
			return i;
		}
	}

	return -1;
}


// 解法二: 不使用256的数组, 而是创建一个map
// 优点: 可以处理超出256的字符限制
  int FirstNotRepeatingChar(string str) {
      map<char, int> mp; // map底层红黑树， 时间复杂度O(logN), 使用unordered_map, 底层哈希, 时间复杂度O(1)
      for(int i = 0; i < str.size(); ++i)
          mp[str[i]]++;
      for(int i = 0; i < str.size(); ++i){
          if(mp[str[i]]==1)
              return i;
      }
      return -1;
  }



// 50题拓展:

// 拓展一:
string delStr2CharFromStr1(string str1, string str2) {
	if (str1.empty()) {
		return str1;
	}
	unordered_map<char, int> occurrence;

	for (auto c : str2) {
		occurrence[c] += 1;
	}

	string result;
	for (auto c : str1) {
		if (occurrence[c] == 0) {
			result += c;
		}
	}

	return result;
}



// 拓展二:


// 拓展三:
