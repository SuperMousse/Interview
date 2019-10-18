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
