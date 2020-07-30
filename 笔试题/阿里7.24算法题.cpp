// 题一
// 吃烧饼。有n个盘子，每个盘子内有w[i]个烧饼。每次选取一个1≤x≤n，可以在1~x盘子中每个盘子吃一个烧饼。若这x个盘子中有空盘时无法进行该操作
// 问经过任意多次这种操作后，最多可以吃掉多少烧饼。
// 分析：对每个盘子，最多可吃的数量为：它和它前面的盘子中最少的烧饼数。

// 输入：
// 3
// 2 1 3
// 输出：
// 4

// 对每个盘子，最多可吃的数量为：它和它前面的盘子中最少的烧饼数

int maxCake(vector<int> cake) {
    if (cake.empty()) {
        return 0;
    }
    int curCake = 0;
    int result = 0;
    for (auto c : cake) {
        curCake = min(curCake, c);
        result += curCake;
    }
    return result;
}


// 题二
// https://www.nowcoder.com/discuss/459193?type=1
