class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        data = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        if (row1 <= row2 && col1 <= col2) {
            for (int i = row1; i <= row2 ; ++i) {
                for (int j = col1; j <= col2; ++j) {
                    data[i][j] = newValue;
                }
            }
        }
        return;
    }

    int getValue(int row, int col) {
        return data[row][col];
    }
private:
    vector<vector<int> > data;
};
