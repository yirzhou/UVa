#include <bits/stdc++.h>
#define N 100005

using namespace std;
int tree[N << 2];
int l[N << 2];
int r[N << 2];
int nums[N << 2];
int stats[N << 2];
int A[N];

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }
void build(int p, int L, int R)
{
    if (L == R) {
        tree[p] = stats[L];
    } else {
        build(left(p), L, (L + R) / 2);
        build(right(p), (L + R) / 2 + 1, R);
        tree[p] = max(tree[left(p)], tree[right(p)]);
    }
}

int rmq(int p, int L, int R, int i, int j)
{
    if (i > R || j < L) {
        return 0;
    }
    if (L >= i && R <= j) {
        return tree[p];
    }

    int p1 = rmq(left(p), L, (L + R) / 2, i, j);
    int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
    return max(p1, p2);
}

int main()
{
    int n, q;
    while (scanf("%d", &n) && n) {
        scanf("%d", &q);
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(tree, 0, sizeof(tree));
        memset(nums, 0, sizeof(nums));
        memset(stats, 0, sizeof(stats));

        int val;
        for (int i = 0; i < n; ++i) {
            cin >> val;
            A[i] = val;
        }
        int id = 0;
        l[id] = 0;
        nums[0] = id;
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] != A[i - 1]) {
                stats[id] = cnt;
                r[id++] = i - 1;
                l[id] = i;
                cnt = 1;
            } else {
                cnt++;
            }
            nums[i] = id;
        }

        stats[id] = cnt;
        r[id] = n - 1;
        build(1, 0, id);

        while (q--) {
            int i, j;
            scanf("%d %d", &i, &j);
            i--;
            j--;
            int L = nums[i], R = nums[j];
            if (L == R) {
                printf("%d\n", j - i + 1);
                continue;
            }
            int res = max(max(r[L] - i + 1, j - l[R] + 1), rmq(1, 0, id, L + 1, R - 1));
            printf("%d\n", res);
        }
    }
}
