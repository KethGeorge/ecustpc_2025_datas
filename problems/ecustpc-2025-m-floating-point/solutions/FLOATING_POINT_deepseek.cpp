#include <iostream>
#include <vector>
using namespace std;

// 生成满足条件的序列
vector<int> generate_sequence(int n) {
    vector<int> sequence;
    if (n < 2) {
        // 如果 n < 2，直接返回 -1
        sequence.push_back(-1);
        return sequence;
    }
    // 起始值为 4（可以是任意大于 2 的数）
    int start = 4;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(start + i);
    }
    return sequence;
}

int main() {
    ios::sync_with_stdio(false); // 加速输入输出
    cin.tie(nullptr);

    int T;
    cin >> T; // 读取测试数据组数
    while (T--) {
        int n;
        cin >> n; // 读取每组测试数据的 n
        vector<int> sequence = generate_sequence(n);
        if (sequence[0] == -1) {
            // 如果 n < 2，输出 -1
            cout << -1 << "\n";
        } else {
            // 输出生成的序列
            for (int i = 0; i < sequence.size(); ++i) {
                cout << sequence[i];
                if (i < sequence.size() - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}