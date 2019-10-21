
// 快速排序
// 最优时间复杂度O(N logN), 平均时间复杂度O(N logN), 最差时间复杂度O(N^2)
void swap_num(vector<int> &data, int a, int b) {
	int temp = data[a];
	data[a] =  data[b];
	data[b] = temp;
}

int Partition(vector<int>& data, int start, int end)
{
	if (data.empty() || start < 0 || start >= end) {
		throw runtime_error("Invalid Parameters");
	}
	int base = (rand() % (end - start + 1)) + start;
	swap_num(data, base, end); // 随机选择基准数放到队尾方便操作

	int small_num = start - 1; // 使用index顺序扫描序列, 并将其依次放在++small_num上
	for (int index = start; index < end; ++index) {
		if (data[index] < data[end]) {
			++small_num;
			if (small_num < base) {
				swap_num(data, small_num, index);
			}
		}
	}
	++small_num;
	swap_num(data, small_num, end);

	return small_num;
}

void QuickSort(vector<int>& data, int start, int end) {
	if (start >= end) {
		return;
	}
	int index = Partition(data, start, end);
	QuickSort(data, start, index - 1);
	QuickSort(data, index + 1, end);
}


int main(int argc, char* argv[]){
	vector<int> num = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
	int length = 10;
	int start = 0;
	int end = 9;
	QuickSort(num, start, end);

	for (auto c : num) {
		cout << c << endl;
	}
	return 0;
}
