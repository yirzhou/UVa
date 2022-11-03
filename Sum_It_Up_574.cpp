#include <bits/stdc++.h>

using namespace std;
int A[12];
int S[12];
int cnt, t, n;

void f(int ai, int si, int val) {
  if (val == 0) {
    printf("%d", S[0]);
    for (int i = 1; i < si; ++i) {
      printf("+%d", S[i]);
    }
    printf("\n");
    cnt++;
    return;
  }
  for (int i = ai; i < n; ++i) {
    if (i > ai && A[i] == A[i - 1])
      continue;
    if (val - A[i] >= 0) {
      S[si] = A[i];
      f(i + 1, si + 1, val - A[i]);
    }
  }
}

int main() {

  while (scanf("%d %d", &t, &n) && n) {
    memset(A, 0, sizeof(A));
    memset(S, 0, sizeof(S));
    cnt = 0;
    printf("Sums of %d:\n", t);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &A[i]);
    }
    f(0, 0, t);
    if (!cnt)
      printf("NONE\n");
  }
  return 0;
}
