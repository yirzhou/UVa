#include "1259.cpp"

void print(vi &res) {
    cout << "[" << res[0];
    for (int i = 1; i < res.size(); ++i) cout << "," << res[i];
    cout << "]" << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;

        cout << Solution().numberOfWays(n) << endl;
    }
}
