#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define precision(a) \
    cout << fixed;   \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k)
    {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> freqs;
        int p = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == k) {
                p = i;
                break;
            }
        }
        if (p == -1)
            return 0;

        for (int i = p, bal = 0; i < n; ++i) {
            bal += nums[i] == k ? 0 : (nums[i] > k ? 1 : -1);
            freqs[bal]++;
        }

        for (int i = p, bal = 0; i >= 0; --i) {
            bal += nums[i] == k ? 0 : (nums[i] > k ? 1 : -1);
            ans += freqs[-bal] + freqs[-bal + 1];
        }

        return ans;
    }
};