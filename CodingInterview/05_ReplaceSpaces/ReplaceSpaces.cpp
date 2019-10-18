void replace_blank(string& str)
{
	size_t pos = 0;
	string search_str = " ";
	string replace_str = "%20";
	while ( (pos = str.find(search_str, pos)) != std::string::npos) {
		str.replace(pos, search_str.length(), replace_str);
		pos += replace_str.length();
	}
}

void replace_blank(string& str)
{
	cout << str << endl;
	string::iterator beg = str.begin();
	string::iterator end = str.end();
	char search_str = ' ';
	string replace_str = "%20";
	while ( (beg = find(str.begin(), str.end(), search_str)) != end) {
		str.replace(beg, beg+replace_str.length(), replace_str);
		beg += replace_str.length();
	}
}

void replace_blank(char *str, int length) {
	if (str == nullptr || length <= 0)
		return;
	int before = 0;
	int after = 0;
	int blank_count = 0;
	int real_length = 0;
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == ' ') {
			++blank_count;
		}
		++real_length;
		++i;
	}
	int new_length = real_length + blank_count * 2;
	if (new_length > length) {
		return;
	}
	before = real_length;
	after = real_length + blank_count * 2;

	while (before != after && before >=0 && after >= 0) {
		cout << before << after << endl;
		if (str[before] == ' ') {
			str[after--] = '0';
			str[after--] = '2';
			str[after--] = '%';
		}
		else {
			str[after--] = str[before];
		}
		--before;
	}

}

// fusion two ordered int array
void fusion(int *A1, int*A2, int length1, int length2) {

	int fusion_length = length1 + length2 - 1;
	--length1;
	--length2;
	while (fusion_length >= 0 && length2 >=0 && length1 >= 0) {
		if (A1[length1] >= A2[length2]) {
			A1[fusion_length] = A1[length1];
			--fusion_length;
			--length1;
		}
		else {
			A1[fusion_length] = A2[length2];
			--fusion_length;
			--length2;
		}
	}
}



int main(int argc, char* argv[]){
	//vector<int> num = {2, 3, 5, 4, 3, 2, 6, 7};
	const int length = 100;
	char words[length] = "We are the champion!";
	char* str = words;

	replace_blank(str, length);

	cout << str << endl;

	return 0;
}
