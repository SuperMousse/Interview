1. 现有n个人, 要从这n个人中选任意数量的人组成一支队伍, 再在这些人中选出一名队长, 求不同的方案数对10^9 + 7取模的结果, 如果两个方案选取的人
的集合不同或选出的队长不同, 则认为这两个方案是不同的  
输入: 一行一个数字n, 1 <= n <= 10^9, 如2
输出: 一行一个数字表示答案, 如4

result = 0 * C_{N}^{0} + 1 * C_{N}^{1} + 2 * C_{N}^{2} + ... + N * C_{N}^{N}  
result = N * C_{N}^{N} + (N-1) * C_{N}^{N-1}           + ... + 0 * C_{N}^{0}  
2 * result = N * (C_{N}^{0} + C_{N}^{1} + ... + C_{N}^{N})  
    result = N * 2^{N-1}  


long long fastPow(long long base, long long N) {
    if(N == 0) {
        return 1;
    }
    if(N == 1) {
        return 2;
    }
    long long  result = 1.0;
    long long temp = base;
    
    while(N > 0) {
        if(N & 0x1 != 0) {
            result = (result % 1000000007) * (temp % 1000000007);
        }
        temp = (temp % 1000000007) * (temp % 1000000007);
        N >>= 1;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...



    long long N;
    cin >> N;
    cout << (N * fastPow(2, N - 1)) % 1000000007;

    
    return 0;
}

2. 小强在玩一个走迷宫的游戏, 他操纵的人物现在位于迷宫的起点, 他的目标是尽快的到达终点, 每一次他可以选择花费一个时间单位向上, 下, 左,右
走一格, 或是使用自己的对称飞行器花费一个时间单位瞬移到关于自己当前自己点中心对称的格子, 且每一次移动的目的地不能存在障碍物, 具体来说, 设
当前迷宫有n行m列, 如果当前小强操纵的人物位于点A(x, y), 那么关于点A中心对称的格子B(x', y')满足x+x'=n+1, y+y'=m+1, 需要注意的是: 对
称飞行器最多使用5次  
输入: 第一行两个空格分隔的正整数n, m, 分别代表迷宫的行数和列数, 接下来n行, 每一行长度为m,的字符串来表示这个迷宫, 其中: .代表通路, #代表
障碍, S代表起点, E代表终点, 保证只有一个S和一个E, 样例  
4 4  
#S..
E#..
#...
....
输出: 仅一行一个整数表示从起点最小花费多少时间单位到达终点, 如果无法到达终点, 输出-1  
如4


// BFS
// 1. 首先把起点坐标放入队列
// 2. 每一次访问队头元素，观察其1步可以到达的（上、下、左、右、中心对称位）的坐标：
//    如果该坐标当前记录的某一种飞行器使用次数k下的值>当前值+1，则更新该值，把这一坐标加入队列
//   （注意，上、下、左、右是同k值比较，中心对称位需要使用一次飞行器，所以是k+1和K比较）
// 3. 队列清空，更新完成

//定义坐标点
struct position{
    int x;
    int y;
};

int main(int argc, const char * argv[]) {
    // insert code here...


    int n = 4;
    int m = 4;
    position start;
    position end;
    position posTemp;
    char charTemp;
    vector<char> rowTemp;
    vector<vector<char>> map = {{'#', 'S', '.', '.'},
                                {'E', '#', '.', '.'},
                                {'#', '.', '.', '.'},
                                {'.', '.', '.', '.'}};
    queue<position> queuePos;
    
    // dp[i, j, k]表示第i, j个位置用了k个飞行器时, 到达需要的步数, 初始化较大数值
    int dp[n][m][6];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 6; ++k) {
                dp[i][j][k] = n * m + 1;
            }
        }
    }
    
    // 记录输入数据, 记录起点, 终点
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // cin >> charTemp;
            // rowTemp.push_back(charTemp);
            if (map[i][j] == 'S') {
                start.x = i;
                start.y = j;
                queuePos.push(start);
                for (int k = 0; k < 6; ++k) {
                    dp[i][j][k] = 0;
                }
            }
            else if(map[i][j] == 'E') {
                end.x = i;
                end.y = j;
            }
        }
        // map.push_back(rowTemp);
        // rowTemp.clear();
    }
    
    // BFS走完地图
    while (!queuePos.empty()) {
        posTemp = queuePos.front();
        // 左右上下走
        if (posTemp.x > 0 && map[posTemp.x - 1][posTemp.y] != '#') {
            bool flag = false;
            for (int k = 0; k < 6; ++k) {
                if (dp[posTemp.x - 1][posTemp.y][k] > dp[posTemp.x][posTemp.y][k] + 1) {
                    dp[posTemp.x - 1][posTemp.y][k] = dp[posTemp.x][posTemp.y][k] + 1;
                    flag = true;
                }
            }
            if (flag == true) {
                position pos;
                pos.x = posTemp.x - 1;
                pos.y = posTemp.y;
                queuePos.push(pos);
            }
        }
        if (posTemp.y > 0 && map[posTemp.x][posTemp.y - 1] != '#') {
            bool flag = false;
            for (int k = 0; k < 6; ++k) {
                if (dp[posTemp.x][posTemp.y - 1][k] > dp[posTemp.x][posTemp.y][k] + 1) {
                    dp[posTemp.x][posTemp.y - 1][k] = dp[posTemp.x][posTemp.y][k] + 1;
                    flag = true;
                }
            }
            if (flag == true) {
                position pos;
                pos.x = posTemp.x;
                pos.y = posTemp.y - 1;
                queuePos.push(pos);
            }
        }
        if (posTemp.x < (n - 1) && map[posTemp.x + 1][posTemp.y] != '#') {
            bool flag = false;
            for (int k = 0; k < 6; ++k) {
                if (dp[posTemp.x + 1][posTemp.y][k] > dp[posTemp.x][posTemp.y][k] + 1) {
                    dp[posTemp.x + 1][posTemp.y][k] = dp[posTemp.x][posTemp.y][k] + 1;
                    flag = true;
                }
            }
            if (flag == true) {
                position pos;
                pos.x = posTemp.x + 1;
                pos.y = posTemp.y;
                queuePos.push(pos);
            }
        }
        if (posTemp.y < (m - 1) && map[posTemp.x][posTemp.y + 1] != '#') {
            bool flag = false;
            for (int k = 0; k < 6; ++k) {
                if (dp[posTemp.x][posTemp.y + 1][k] > dp[posTemp.x][posTemp.y][k] + 1) {
                    dp[posTemp.x][posTemp.y + 1][k] = dp[posTemp.x][posTemp.y][k] + 1;
                    flag = true;
                }
            }
            if (flag == true) {
                position pos;
                pos.x = posTemp.x;
                pos.y = posTemp.y + 1;
                queuePos.push(pos);
            }
        }
        // 中心对称走
        if (map[n - 1 - posTemp.x][m - 1 - posTemp.y] != '#') {
            bool flag = false;
            for (int k = 0; k < 6; ++k) {
                if (dp[n - 1 - posTemp.x][m - 1 - posTemp.y][k + 1] > dp[posTemp.x][posTemp.y][k] + 1) {
                    dp[n - 1 - posTemp.x][m - 1 - posTemp.y][k + 1] = dp[posTemp.x][posTemp.y][k] + 1;
                    flag = true;
                }
            }
            if (flag == true) {
                position pos;
                pos.x = n - 1 - posTemp.x;
                pos.y = m - 1 - posTemp.y;
                queuePos.push(pos);
            }
        }
        queuePos.pop();
    }
    
    if (dp[end.x][end.y][5] == (n * m + 1)) {
        cout << -1 << endl;
    }
    else {
        cout << dp[end.x][end.y][5] << endl;
    }

    
    return 0;
}

