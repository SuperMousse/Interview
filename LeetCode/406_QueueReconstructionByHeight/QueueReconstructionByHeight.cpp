// 首先把二维vector按照h降序, k升序排列
// 然后依次遍历排序后的二维vector, 其k值即为其要插入的位置
// 原因在于k表示等于或者大于当前h的元素个数, 之前加入的h均为比当前h更大的, 所以其前面的个数就是要插入的位置

// 注意: sort中的compare要么写成lambada表达式, 要么在类中声明为static， 因为如果不声明为static， 那么在没有类
// 的实例时是无法调用的

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    if (people.empty()) {
        return vector<vector<int>>();
    }
    int len = people.size();
    vector<vector<int>> peopleCopy(people);
    vector<vector<int>> result;
    sort(peopleCopy.begin(), peopleCopy.end(), compare);

    for(auto p : peopleCopy) {
        auto beg = result.begin();
        result.insert(beg + p[1], p);
    }

    for(auto i : result) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << ",";
    }

    return result;
}

bool compare(vector<int>& x, vector<int>& y) {
    if(x[0] > y[0]) return true;
    else if(x[0] < y[0]) return false;
    else return x[1] <= y[1] ? true : false;
}
