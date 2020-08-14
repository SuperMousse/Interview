struct number {
    int arrayIndex = 0;
    int ptr = 0;
    int val = 0;
    number(int a, int p, int v) : arrayIndex(a), ptr(p), val(v) {}
};

// 大于定义小顶堆
bool cmp(number& a, number& b) {
    return a.val > b.val;
}

vector<int> mergeKArrays(vector<vector<int> > arrays) {
    if (arrays.empty()) {
        return vector<int>();
    }
    vector<int> result;
    int k = arrays.size();
    vector<number> heap;

    for (int i = 0; i < k; ++i) {
        number temp(i, 0, arrays[i][0]);
        heap.push_back(temp);
    }
    make_heap(heap.begin(), heap.end(), cmp);
    while (!heap.empty()) {
        number n = heap[0];
        result.push_back(n.val);
        pop_heap(heap.begin(), heap.end(), cmp);
        heap.pop_back();
        ++n.ptr;
        if (n.ptr < arrays[n.arrayIndex].size()) {
            n.val = arrays[n.arrayIndex][n.ptr];
            heap.push_back(n);
            push_heap(heap.begin(), heap.end(), cmp);
        }
    }
    return result;
}



int main() {
    vector<vector<int>> arr1{
            { 2, 6, 12 },
            { 1, 9 },
            { 23, 34, 90, 2000 } };
    vector<int> output = mergeKArrays(arr1);
    cout << "Merged array is "<< endl;
    for(auto x : output)
        cout << x << " ";

    return 0;
}
