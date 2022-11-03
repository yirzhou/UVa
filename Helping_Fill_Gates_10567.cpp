#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> M(52);
char S[(int)1e6 + 1];
char ss[101];
int Q;

int sid(char c)
{
    if ('A' <= c && 'Z' >= c)
        return c - 'A';
    return c - 'a' + 26;
}

int main()
{
    scanf("%s", S);
    for (int i = 0; i <= 1e6 && S[i] != '\0'; ++i) {
        M[sid(S[i])].push_back(i);
    }
    scanf("%d", &Q);
    while (Q--) {
        int start = -1, prev = -1, matched = 1;
        vector<int>::iterator res;
        scanf("%s", ss);
        for (int i = 0; i <= 100 && ss[i] != '\0'; ++i) {
            int id = sid(ss[i]);
            res = upper_bound(M[id].begin(), M[id].end(), prev);
            if (res == M[id].end()) {
                matched = 0;
                break;
            }
            if (i == 0)
                start = *res;
            prev = *res;
        }

        if (!matched) {
            printf("Not matched\n");
        } else {
            printf("Matched %d %d\n", start, prev);
        }
    }
}
