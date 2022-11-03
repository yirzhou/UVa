#include <bits/stdc++.h>
using namespace std;

int m;
vector<int> v;
unordered_map<int, int> f;
int n;

int main()
{
    int val;
    int t = 0;
    while (scanf("%d", &n) && n) {
        if (t++ > 0)
            printf("\n");
        m = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &val);
            v.push_back(val);
            f[val]++;
            m = max(m, f[val]);
        }

        for (auto& [k, o] : f) {
            if (m - o) {
                for (int i = 0; i < m - o; ++i) {
                    v.push_back(0);
                }
            }
        }

        sort(v.begin(), v.end());
        printf("%d\n", m);
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < v.size(); j += m) {
                if (v[j] != 0)
                    printf(j + m >= v.size() ? "%d" : "%d ", v[j]);
            }
            printf("\n");
        }
        v.clear();
        f.clear();
    }
}
