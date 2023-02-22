#include "1482.cpp"

void print(vi &res) {
    cout << "[" << res[0];
    for (int i = 1; i < res.size(); ++i) cout << "," << res[i];
    cout << "]" << endl;
}

int main() {
    int t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vi nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        cout << Solution().minDays(nums, m, k) << endl;
    }
}
