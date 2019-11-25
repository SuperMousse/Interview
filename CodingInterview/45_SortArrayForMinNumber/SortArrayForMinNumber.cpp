/* sort中的比较函数compare要声明为静态成员函数或全局函数，
   不能作为普通成员函数，否则会报错。因为非静态成员函数是
   依赖于具体对象的，而std::sort这类函数是全局的，因此无
   法再sort中调用非静态成员函数。静态成员函数或者全局函数
   是不依赖于具体对象的, 可以独立访问，无须创建任何对象实
   例就可以访问。同时静态成员函数不可以调用类的非静态成员。
*/

// cmp: [](string a, string b){return a + b < b + a;}

string PrintMinNumber(vector<int> numbers) {
	if (numbers.empty()) {
		return "";
	}
	int length = numbers.size();
	sort(numbers.begin(), numbers.end(), cmp); 
	string res;
	for (int i = 0; i < length; ++i) {
		res += to_string(numbers[i]);
	}
	return res;
}

static bool cmp(int a, int b) {
	string A = to_string(a) + to_string(b);
	string B = to_string(b) + to_string(a);
	return A < B;
}
