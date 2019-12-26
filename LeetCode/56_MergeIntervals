// 排序O(NlogN), 合并空白间隔复杂度O(N)
// 总时间复杂度O(NlogN)

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int> > result;
    if(intervals.empty()){
        return result;
    }
    sort(intervals.begin(), intervals.end(), [](vector<int> i, vector<int> j)->bool {
                                                return i[0] < j[0];
                                                });
    int left = intervals[0][0];
    int right = intervals[0][1];
    for (auto interval : intervals) {
        // overlapping interval
        if(interval[0] <= right) {
            right = max(right, interval[1]);
        }
        // disjoint interval
        else{
            result.push_back({left, right});
            left = interval[0];
            right = interval[1];
        }
    }
    result.push_back({left, right});
    return result;
}
