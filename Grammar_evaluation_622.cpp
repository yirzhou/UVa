#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

bool readop(string& str, int& ptr, char& op)
{
    if (str[ptr] != '+' && str[ptr] != '*')
        return false;
    op = str[ptr++];
    return true;
}

bool readnum(string& str, int& ptr, ll& ans)
{
    ans = 0;
    if (ptr == str.length())
        return false;
    if (!isdigit(str[ptr]))
        return false;
    while (ptr < str.length()) {
        char c = str[ptr];
        if (isdigit(c)) {
            ans = ans * 10 + str[ptr] - '0';
            ptr++;
        } else
            break;
    }

    return true;
}

bool solve(string& str, int& ptr, ll& ans, int flag = 0)
{
    vector<ll> v;
    string op;
    while (ptr < str.length()) {
        if (v.size() == op.length()) {
            ll x = 0;
            if (str[ptr] == '(') {
                ptr++;
                if (!solve(str, ptr, x, 1))
                    return false;
            } else if (!readnum(str, ptr, x))
                return false;

            if (op.length() > 0 && op.back() == '*') {
                op.pop_back();
                v.back() *= x;
            } else
                v.pb(x);
        } else {
            if (str[ptr] == ')') {
                ptr++;
                if (!flag)
                    return false;
                flag = 0;
                break;
            }

            char c = 0;
            if (!readop(str, ptr, c))
                return false;
            op.pb(c);
        }
    }
    if (flag)
        return false;
    if (v.size() != op.length() + 1)
        return false;
    ans = 0;
    for (auto& x : v)
        ans += x;
    return true;
}

int main()
{
    int n;
    cin >> n;
    string exp;
    while (n--) {
        cin >> exp;
        ll ans = 0;
        int ptr = 0;
        if (solve(exp, ptr, ans))
            printf("%lld\n", ans);
        else
            puts("ERROR");
    }
}