// 解法一: 无序数组基于Quick Sort的Partition搜索中位数
// 插入一个数字时间复杂度O(1), 找到中位数时间复杂度O(N)


// 解法二: 有序数组
// 插入一个数字时间复杂度O(N), 找到中位数时间复杂度O(1)


// 解法三: 基于排序的链表
// 插入一个数字时间复杂度O(N), 找到中位数时间复杂度O(1)(维护两个指针指向链表中间节点)

// 解法四: 基于二叉搜索树
// 插入时间复杂度O(logN), 找到中位数时间复杂度O(1)

// 解法三: 基于平衡的二叉搜索树, AVL树(自平衡二叉查找树)
// 插入时间复杂度O(logN), 找到中位数时间复杂度O(1)


// 解法四最大堆&最小堆

// 最大堆: 每一个根节点的数值都比其子节点大, 堆顶为最大值, 底层实现为数组, 但展现出了二叉树的性能
// 最小堆: 与最大堆相反
// make_heap(vec.begin(), vec.end()) 创建堆, 默认为最大堆, 若不进行make_heap则不能进行sort_heap,但不影响push_heap的正常使用
// push_heap(vec.begin, vec.end()) 将vec处理成最大堆序列, greater<int>()用于创建最小堆, 原因是堆创建时使用了比较然后下沉的创建方法
// 若a>b则a下沉, 所以greater<int>(创建了最小堆)

// 若输入的vector = {1, 2, 3, 4, 5, 6, 7}
// make_heap/push_heap后序列转换为{7, 5, 6, 4, 2, 1, 3} 对应最大堆的广度优先遍历序列
// pop_heap后序列转换为{6, 5, 3, 4, 2, 1, 7}, 将堆顶元素放置到队尾
// push_heap与pop_heap都只能用于调整顺序，都不能真正的插入和删除元素, 必须结合push_back, pop_back进行使用

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
