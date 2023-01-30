#include "1948.cpp"

void print(vector<vector<string>> &paths) {
    cout << "BEGIN" << endl;
    for (auto &path : paths) {
        cout << "[" << path[0];
        for (int i = 1; i < path.size(); ++i)
            cout << "," << path[i];
        cout << "]" << endl;
    }
    cout << "END" << endl;
}

int main() {
    int t, n, cnt;

    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<string>> paths(n);
        for (int i = 0; i < n; ++i) {
            cin >> cnt;
            vector<string> path(cnt);
            for (int j = 0; j < cnt; ++j)
                cin >> path[j];
            paths[i] = path;
        }
        auto res = Solution().deleteDuplicateFolder(paths);
        print(res);
    }
}
