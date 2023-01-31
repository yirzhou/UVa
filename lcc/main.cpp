#include "1944.cpp"

void print(vi &res) {
    cout << "[" << res[0];
    for (int i = 1; i < res.size(); ++i)
        cout << "," << res[i];
    cout << "]" << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vi heights(n);
        for (int i = 0; i < n; ++i)
            cin >> heights[i];
        auto res = Solution().canSeePersonsCount(heights);
        print(res);
    }
}
