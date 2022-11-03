#include <bits/stdc++.h>

using namespace std;
char s[8];
int values[11];
int n;

int opts[10] { 63, 6, 91, 79, 102, 109, 125, 7, 127, 111 };

bool dfs(int v, int j, int s)
{
    if (j == n) {
        return true;
    }

    for (int i = 0; i <= s; ++i) {
        // Try every subset of s.
        // No burnt seg will be ON.
        // Also make sure values[j] is a subset of i.
        if ((i & s) == i && (opts[v] & i) == values[j]) {
            if (dfs(v - 1, j + 1, i))
                return true;
        }
    }

    return false;
}

int main()
{
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            int val = 0;
            for (int j = 0; j < 7; ++j) {
                if (s[j] == 'Y') {
                    val |= (1 << j);
                }
            }
            values[i] = val;
        }
        bool res = false;
        for (int i = n - 1; i < 10; ++i) {
            if (dfs(i, 0, 127)) {
                res = true;
                break;
            }
        }
        if (res) {
            printf("MATCH\n");
        } else {
            printf("MISMATCH\n");
        }
    }
}
