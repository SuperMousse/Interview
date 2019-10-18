bool find_num(vector<vector<int>>& array, int num){
	int rows = array.size();
	int columns = array[0].size();

	if (rows > 0 && columns > 0) {
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0) {
			if (array[row][column] == num) {
				return true;
			}
			else if (array[row][column] < num) {
				++row;
			}
			else {
				--column;
			}
		}
		return false;

	}
	return false;
}


int main(int argc, char* argv[]){
	//vector<int> num = {2, 3, 5, 4, 3, 2, 6, 7};

	int rows = 4, columns = 4;

	vector<vector<int>> array = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };

	bool result = find_num(array, 3);

	cout << result << endl;

	return 0;
}
