# Problem

The problem can be reduced to:
Given an array from which we _can_ construct a graph. In this graph, there's an edge between two nodes (indices `i` and `j`) iff `nums[i]` and `nums[j]` is not coprime. Is this graph connected?

# Main idea

We can use the disjoint-set union (aka. union-find algorithm) to solve this problem. For every index `i` and its number `nums[i]`, we perform prime factorization. For every prime factor `z` of `nums[i]`, we connect `i` to _any_ other index `j` where `nums[j]`'s prime factors also include `z`. We use a map `unordered_map<int, vector<int>>` to keep track of this information of which each key is a prime factor of some number we've seen and its value is a list of indices where the numbers positioned at them have such prime factor.

Then, the problem becomes straight-forward if one knows the standard implementation of the disjoint-set union.

# Impl

```cpp
// Disjoint-set/union-find
class UF
{
    int n = 0;
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

    // Returns the number of connected components.
    int count()
    {
        return n;
    }
};

// Prime factorization.
void factor(int idx, int num, unordered_map<int, vector<int>> &mp, UF &uf)
{
    int z = 2;

    while (z * z <= num)
    {
        if (num % z == 0)
        {
            // Connect idx to any node that has the prime factor z.
            if (mp.count(z)) { uf.connect(idx, mp[z][0]); }
            mp[z].push_back(idx);
            num /= z;
        }
        else { z++; }
    }
    // Connect idx to any node that has the prime factor num.
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
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            factor(i, num, mp, uf);
        }

        return uf.count() == 1;
    }
};
```
