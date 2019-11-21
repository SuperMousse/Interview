// 该题想要通过牛客网编译, 必须在size为偶数时插入最大堆, 否则报错
class Solution {
public:
	void Insert(int num)
	{
		int size = min.size() + max.size();
		// 奇数
		if ((size & 0x1) == 0) {
			// max.size()必须大于0才能对max中的元素进行pop
			if (max.size() > 0 && num < max[0]) {
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());
				num = max[0]; // 最大堆中的最大元素
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num); // 最大堆中最大元素插入最小堆
			push_heap(min.begin(), min.end(), greater<int>());
		}


		else {
			if (min.size() > 0 && num > min[0]) {
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}
	}

	double GetMedian()
	{
		int size = min.size() + max.size();
		if (size == 0) {
			return 0;
		}

		double median = 0;
		if ((size & 0x1) == 1) {
			median = min[0];
		}
		else {
			median = (min[0] + max[0]) / 2.0;
		}
		return median;
	}

private:
	vector<int> min; // 最小堆, 堆顶为最小值
	vector<int> max; // 最大堆, 堆顶为最大值

};
