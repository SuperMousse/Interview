
// 快速排序
// 最优时间复杂度O(N logN), 平均时间复杂度O(N logN), 最差时间复杂度O(N^2)
// 顺序扫描O(N), 二分法O(logN), 总体时间复杂度O(N logN)
void swap_num(vector<int> &data, int a, int b) {
	int temp = data[a];
	data[a] =  data[b];
	data[b] = temp;
}

// 单端扫描Partition
int Partition(vector<int>& data, int start, int end)
{
	if (data.empty() || start < 0 || start >= end) {
		throw runtime_error("Invalid Parameters");
	}
	int base = (rand() % (end - start + 1)) + start;
	swap_num(data, base, end); // 随机选择基准数放到队尾方便操作, 此处可以直接将base换为end, 而且不进行数据交换, 但是不能为start
	                           // 因为数据是从左往右放的, base受到影响

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

// 双端扫描Partition
// 此处双端扫描不能使用随机的base, 原因就在于只有将base位于队尾或者队头的时候才能进行扫描，否则数据会乱
int Partition(vector<int>& data, int start, int end) {
	if (data.empty() || start < 0 || start >= end) {
		throw runtime_error("Invalid Input");
	}
	int base = start; //int base = rand() % (end - start + 1) + start; 
	int left = start;
	int right = end;
	while (true) {
		while (left < right && data[right] >= data[base]) // 右端扫描到第一个小于data[base]的数字停下来
			--right;
		while (left < right && data[left] <= data[base]) // 左端扫描到第一个大于data[base]的数字停下来
			++left;
		if (left == right)
			break;
		swap_num(data, left, right);
	}
	/*
	while (left != right) {
		while (left < right && data[right] >= data[base]) // 右端扫描到第一个小于data[base]的数字停下来
			--right;
		while (left < right && data[left] <= data[base]) // 左端扫描到第一个大于data[base]的数字停下来
			++left;
		if (left < right)
			swap_num(data, left, right);
	}
	*/
	// 基准数归位
	swap_num(data, base, left);

	return left;
}

void QuickSort(vector<int>& data, int start, int end) {
	if (data.empty() || start < 0 || start >= end) {
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
