#include <bits/stdc++.h>
using namespace std;
const int N = 1024000;
/*
2 (T test cases)
2 (M pairs of lines)
5
10
2
1000
5 (Q queries)
F 0 17 (Change to 1)
I 0 5 (Inverse all)
S 1 10 (God's query)
E 4 9 (Change to 0)
S 2 10 (God's query)
3
3
1
4
0
2
0
2
I 0 2
S 0 8

F: change 0 to 1 -> s2 = j-i+1
E: change 1 to 0 -> s2 = 0
I: flip -> suppose original sum s1; after flipping, s2 = (j-i+1)-s1

Steps:
1. build ST (range sum) from pirate array.
2. update_range(p, L,R,i,j,t)
    - t=1 (set all to 1), delta=(j-i+1)-st[p]
    - t=0 (set all to 0), delta=-st[p]
    - t=-1 (flip), delta=(j-i+1)-2*s1
*/

int tree[N << 2];
int lazy[N << 2];
int A[N];

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }
int flip(int mode)
{
    if (mode == 3)
        return 2;
    if (mode == 2)
        return 3;
    return mode == 1 ? 0 : 1;
}

void flip_left(int p, int m, int i)
{
    if (lazy[left(p)] == 3) {
        // If one, make zero
        lazy[left(p)] = 2;
        tree[left(p)] = 0;
    } else if (lazy[left(p)] == 2) {
        lazy[left(p)] = 3;
        tree[left(p)] = m - i + 1;
    } else if (lazy[left(p)] == 1) {
        lazy[left(p)] = 0;
        tree[left(p)] = (m - i + 1) - tree[left(p)];
    } else {
        lazy[left(p)] = 1;
        tree[left(p)] = (m - i + 1) - tree[left(p)];
    }
}

void flip_right(int p, int m, int j)
{
    if (lazy[right(p)] == 3) {
        // If one, make zero
        lazy[right(p)] = 2;
        tree[right(p)] = 0;
    } else if (lazy[right(p)] == 2) {
        lazy[right(p)] = 3;
        tree[right(p)] = j - m;
    } else if (lazy[right(p)] == 1) {
        lazy[right(p)] = 0;
        tree[right(p)] = (j - m) - tree[right(p)];
    } else {
        lazy[right(p)] = 1;
        tree[right(p)] = (j - m) - tree[right(p)];
    }
}

void push_down(int p, int i, int j)
{
    // Flip
    int m = (i + j) >> 1;
    // If all one
    if (lazy[p] == 3) {
        tree[left(p)] = (m - i + 1);
        tree[right(p)] = (j - m);
        lazy[left(p)] = lazy[right(p)] = lazy[p];

    } else if (lazy[p] == 2) {
        // If all zero
        tree[left(p)] = tree[right(p)] = 0;
        lazy[left(p)] = lazy[right(p)] = lazy[p];
    } else if (lazy[p] == 1) {
        // If flip
        flip_left(p, m, i);
        flip_right(p, m, j);
    }
    lazy[p] = 0;
}

void push_up(int p) { tree[p] = tree[left(p)] + tree[right(p)]; }

void build(int p, int L, int R)
{
    if (L == R) {
        tree[p] = A[L];
    } else {
        build(left(p), L, (L + R) / 2);
        build(right(p), (L + R) / 2 + 1, R);
        tree[p] = tree[left(p)] + tree[right(p)];
    }
}

void update(int p, int L, int R, int i, int j, int mode)
{
    if (L > R || L > j || R < i || mode == 0)
        return;
    if (L >= i && R <= j) {
        if (mode == 3) {
            tree[p] = (R - L + 1);
            lazy[p] = 3;
        } else if (mode == 2) {
            tree[p] = 0;
            lazy[p] = 2;
        } else {
            if (lazy[p] == 3) {
                lazy[p] = 2;
                tree[p] = 0;
            } else if (lazy[p] == 2) {
                lazy[p] = 3;
                tree[p] = (R - L) + 1;
            } else if (lazy[p] == 0) {
                lazy[p] = 1;
                tree[p] = (R - L + 1) - tree[p];
            } else {
                lazy[p] = 0;
                tree[p] = (R - L + 1) - tree[p];
            }
        }
        return;
    }

    push_down(p, L, R);
    update(left(p), L, (L + R) / 2, i, j, mode);
    update(right(p), (L + R) / 2 + 1, R, i, j, mode);
    push_up(p);
}

int query(int p, int L, int R, int i, int j)
{
    if (L > R || L > j || R < i)
        return 0;
    if (L >= i && R <= j) {
        return tree[p];
    }
    push_down(p, L, R);
    int mid = (L + R) / 2;
    int ans = query(left(p), L, mid, i, j) + query(right(p), mid + 1, R, i, j);
    push_up(p);
    return ans;
}
char s[100];
int main()
{
    int c = 1;
    int T, M, Q, cnt;
    scanf("%d", &T);
    memset(A, 0, sizeof(A));
    while (T--) {
        printf("Case %d:\n", c++);
        scanf("%d", &M);
        cnt = 0;
        while (M--) {
            int rep;
            scanf("%d", &rep);
            scanf("%s", s);
            int len = strlen(s);
            while (rep--) {
                for (int i = 0; i < len; ++i) {
                    A[cnt++] = s[i] - '0';
                }
            }
        }
        memset(lazy, 0, sizeof(lazy));
        memset(tree, 0, sizeof(tree));
        build(1, 0, cnt - 1);
        char q[2];
        int i, j;
        scanf("%d", &Q);
        int n = cnt;
        cnt = 0;
        while (Q--) {
            scanf("%s%d%d", q, &i, &j);
            if (q[0] == 'F')
                update(1, 0, n - 1, i, j, 3);
            else if (q[0] == 'E')
                update(1, 0, n - 1, i, j, 2);
            else if (q[0] == 'I')
                update(1, 0, n - 1, i, j, 1);
            else
                printf("Q%d: %d\n", ++cnt, query(1, 0, n - 1, i, j));
        }
    }
    return 0;
}
