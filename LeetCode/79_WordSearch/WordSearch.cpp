# 回溯
bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty()) {
            return false;
        }
        int rows = board.size();
        int cols = board[0].size();
        bool* visited = new bool[rows * cols];
        memset(visited, 0, rows * cols * sizeof(bool));
        
        int pathLength = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(existCore(board, word, i, rows, j, cols, pathLength, visited)) {
                    return true;
                }
            }
        }
        
        delete[] visited;
        return false;
    }

    bool existCore(vector<vector<char>>& board, string& word,
                   int row, int rows, int col, int cols, int& pathLength, bool* visited) {
        if(pathLength == word.size()) {
            return true;
        }
        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols
           && board[row][col] == word[pathLength]
           && !visited[row * cols + col]) {
            ++pathLength;
            visited[row * cols + col] = true;
            hasPath = existCore(board, word, row + 1, rows, col, cols, pathLength, visited) ||
                      existCore(board, word, row - 1, rows, col, cols, pathLength, visited) ||
                      existCore(board, word, row, rows, col + 1, cols, pathLength, visited) ||
                      existCore(board, word, row, rows, col - 1, cols, pathLength, visited);
            if(!hasPath) {
                --pathLength;
                visited[row * cols + col] = false;
            }
        }
        return hasPath;
    }
