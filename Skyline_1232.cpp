#include <bits/stdc++.h>
#define MAXN 100005
#define SIZE 100000

using namespace std;

typedef vector<int> vi;

int tree[MAXN << 2];
int lazy[MAXN << 2];

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }

int ans = 0;

void push_down(int p)
{
    if (lazy[p]) {
        tree[left(p)] = tree[right(p)] = tree[p];
        lazy[left(p)] = lazy[right(p)] = lazy[p];
        lazy[p] = 0;
    }
}

void push_up(int p) { tree[p] = max(tree[left(p)], tree[right(p)]); }

void modify(int p, int L, int R, int i, int j, int val)
{
    if (L > R || L > j || R < i || lazy[p] > val)
        return;

    if (L >= i && R <= j) {
        if (val >= tree[p]) {
            tree[p] = lazy[p] = val;
            ans += (R - L + 1);
            return;
        }
    }

    push_down(p);
    modify(left(p), L, (L + R) / 2, i, j, val);
    modify(right(p), (L + R) / 2 + 1, R, i, j, val);
    push_up(p);
}

int main()
{
    int T;
    scanf("%d", &T);
    int q;
    while (T--) {
        scanf("%d", &q);
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        int sum = 0, i, j, val;
        while (q--) {
            ans = 0;
            scanf("%d %d %d", &i, &j, &val);
            modify(1, 1, MAXN, i, j - 1, val);
            sum += ans;
        }
        printf("%d\n", sum);
    }
    return 0;
}
