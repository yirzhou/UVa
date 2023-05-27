#include <bits/stdc++.h>
using namespace std;
class UF
{
    int n = 0;
    // idx, parent num
    vector<int> parent;

  public:
    UF(vector<int> &nums)
    {
        n = nums.size();
        parent.assign(n, 0);
        for (int i = 0; i < n; ++i) { parent[i] = i; }
    }

    int find(int x)
    {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void connect(int p, int q)
    {
        int rootp = find(p), rootq = find(q);
        if (rootp == rootq) return;

        parent[rootq] = rootp;
        n--;
    }

    int count()
    {
        return n;
    }
};

void factor(int idx, int num, unordered_map<int, vector<int>> &mp, UF &uf)
{
    int z = 2;

    while (z * z <= num)
    {
        if (num % z == 0)
        {
            if (mp.count(z)) { uf.connect(idx, mp[z][0]); }
            mp[z].push_back(idx);
            num /= z;
        }
        else { z++; }
    }
    if (num > 1)
    {
        if (mp.count(num)) { uf.connect(idx, mp[num][0]); }
        mp[num].push_back(idx);
    }
}

class Solution
{
  public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;

        UF uf(nums);
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            factor(i, num, mp, uf);
        }

        return uf.count() == 1;
    }
};
