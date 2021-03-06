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
	unordered_map<char, int> occurrence; // 也可以使用256大小的数组, char最多只有256个

	for (auto c : str2) {
		occurrence[c] += 1;
	}

	string result;
	for (auto c : str1) {
		if (occurrence[c] == 0) {
			result += c; // 注意此处不应该使用to_string, to_string是将数字转字符串,此处会把ascii码转字符串
		}
	}

	return result;
}



// 拓展二:
string delRepeatChar(string str) {
	if (str.empty()) {
		return str;
	}
	int occurrence[256];
	memset(occurrence, 0, sizeof(occurrence));

	for (auto c : str) {
		occurrence[c] += 1;
	}

	string result;
	for (auto c : str) {
		if (occurrence[c] == 1) {
			result += c;
		}
	}

	return result;
}

// 拓展三:
bool isAnagram(string str1, string str2) {
	int occurrence[256];
	memset(occurrence, 0, sizeof(occurrence));

	for (auto c : str1) {
		occurrence[c] += 1;
	}

	for (auto c : str2) {
		occurrence[c] -= 1;
	}

	for (int i = 0; i < 256;  ++i) {
		if (occurrence[i] != 0) {
			return false;
		}
	}
	return true;
}
