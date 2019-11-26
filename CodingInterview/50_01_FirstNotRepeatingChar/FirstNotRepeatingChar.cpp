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
      map<char, int> mp;
      for(int i = 0; i < str.size(); ++i)
          mp[str[i]]++;
      for(int i = 0; i < str.size(); ++i){
          if(mp[str[i]]==1)
              return i;
      }
      return -1;
  }
