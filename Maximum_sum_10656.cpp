#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000
int N;

typedef pair<int, int> ii;

vector<pair<int, int>> A, B;

int sum()
{
    int s = 0;
    for (int i = 0; i < N; ++i) {
        s += A[i].first;
    }
    return s;
}

int main()
{
    while (scanf("%d", &N) && N) {
        int val;
        A = vector<ii>(N);
        B = vector<ii>();
        for (int i = 0; i < N; ++i) {
            scanf("%d", &val);
            A[i] = { val, i };
        }
        int s = sum();
        if (s == 0) {
            printf("%d\n", 0);
            continue;
        }
        sort(A.begin(), A.end());
        for (int i = N - 1; i >= 0; --i) {
            if (A[i].first != 0) {
                B.push_back({ A[i].second, A[i].first });
            } else {
                break;
            }
        }
        sort(B.begin(), B.end());
        printf("%d", B[0].second);
        for (int i = 1; i < B.size(); ++i) {
            printf(" %d", B[i].second);
        }
        printf("\n");
    }
}
