// 不同于最小栈的只需要返回栈当前的最小值
// 栈排序需要让栈中的元素有序排列, 小的在栈顶, 大的在栈底

// 插入新的元素的时候, 把所有比当前元素小的值都暂时放到辅助栈中, 然后再挪回来

class SortedStack {
public:
    SortedStack() {

    }
    void push(int val) {
        if (!data.empty() && val > data.top()) {
            while (!data.empty() && val > data.top()) {
                int temp = data.top();
                data.pop();
                help.push(temp);
            }
            data.push(val);
            while (!help.empty()) {
                int temp = help.top();
                help.pop();
                data.push(temp);
            }
        }
        else {
            data.push(val);
        }
    }

    void pop() {
        if (!data.empty()) {
            data.pop();
        }
    }

    int peek() {
        if (!data.empty()) {
            return data.top();
        }
        return -1;
    }

    bool isEmpty() {
        return data.empty();
    }

private:
    stack<int> data;
    stack<int> help;
};
