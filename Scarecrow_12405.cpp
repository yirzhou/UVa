#include <bits/stdc++.h>

using namespace std;

int T, N;
char S[100];

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        scanf("%s", S);
        int i = 0, cnt = 0;
        while (i < N) {
            if (S[i] == '.') {
                cnt++;
                i += 3;
            } else
                i++;
        }
        printf("Case %d: %d\n", t, cnt);
    }
}
