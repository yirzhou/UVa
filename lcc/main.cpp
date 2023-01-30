#include "1960.cpp"

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        cout << Solution().maxProduct(s) << endl;
    }
}
