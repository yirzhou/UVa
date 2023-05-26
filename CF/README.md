# CF

My solutions to some CF problems.

## Weak categories

- [ ] Greedy
- [ ] Constructive algorithms
- [ ] Number theory

## Journal

## 05/21/2023

- [x] 1476C
- [x] 601A (memory limit exceeded on BFS; use floyd-warshall instead)

## 05/07/2023

- [x] 75C
- [x] \*1217B
- [x] 1539D
- [x] 1213D

## 04/22/2023

- [x] \*1481C
- [x] \*1555D

## 04/18/2023 - 04/21/2023

Too busy with work.

## 04/17/2023

- [x] \*1622C

## 04/16/2023

Google coding competition farewell round.

### 04/10/2023 - 04/15/2023

Too busy with work

### 04/09/2023

- [x] 343B (similar to bracket matching - find "++" or "--")
- [x] 1294D
- [x] 322B (such a weird one: only if `a % 3 == 0 && a >= 3 && b % 3 == 2 && c % 3 == 2` will we add 1)
- [x] 1251C (reduced to "given a list of odd digits and a list of even digits, reorganize them so that their relative order doesn't change and the final number is minimised")

### 04/03/2023 - 04/08/2023

Too busy with work.

### 04/02/2023

- [x] 165C
- [x] \*1632C (a real tough problem: we only apply 3rd op atmost once)
- [x] \*1537E1 (must be some prefix repeated for several times)

### 04/01/2023

- [x] \*1707A (start from the end)
- [x] 1633D

### 03/27/2023 - 03/31/2023

Too busy with work.

### 03/26/2023

- [x] _1455D_
- [x] 372A

### 03/25/2023

- [x] 1437D

### 03/22/2023 - 03/24/2023

Too busy with work.

### 03/21/2023

- [x] 1288C (non-decreasing sequence of `2m`)

### 03/21/2023

- [x] 1303C

### 03/20/2023

- [x] 1513C

### 03/19/2023

- [x] 1475E
- [x] 348A
- [x] 735D (Goldbach's conjecture)

### 03/18/2023

- [x] 1603B
- [x] 446A

### 03/17/2023

- [x] 1527C
- [x] 1542C

### 03/16/2023

- [x] 1295C
- [x] 1514C

### 03/14/2023 - 03/15/2023

Too busy with work + power outage.

### 03/13/2023

- [x] 1364C
- [x] 1514C

### 03/12/2023

- [x] 1528A
- [x] 1503A

### 03/11/2023

- [x] 1305C

### 03/10/2023

- [x] 1371D
- [x] 1234D

### 03/09/2023

- [x] 1327C
- [x] 1395C

### 03/08/2023

Busy with a problem at work.

### 03/07/2023

- [x] 1165D
- [x] 1374E1

### 03/06/2023

- [x] 510C
- [x] 1519D

### 03/05/2023

- [x] 1458A
- [x] 1342C

### 03/04/2023

- [x] 1373D
- [x] 1348C

### 03/03/2023

- [x] 1389B
- [x] 706C
- [x] 1396A

### 03/02/2023

- [x] 1497C2
- [x] 1349A

### 03/01/2023

- [x] 235A
- [x] 1344A
- [x] 1497C1

### 02/28/2023

- [x] 1363C
- [x] 1353D
- [x] 1334C

## Needs Revision

### 03/11/2023

- 1336A
- 1398C
- 1352G
- **1526C** (very simple and beautiful solution in the end)
- 1358C (draw the diagram and figure out paths where the current path is longer by 1 than its previous path)
- 1334C (think about the additional bullets required if we do NOT kill its previous one)
- 235A (intuition is to iterate all triplets within [n-50,n])
- 1497C1 (odd, n%2 but n%4 != 0, and n%2 and n%4 == 0)
- 1389B (was on the right idea - the maximum pair part is tricky: `mp[i]` can also be `nums[i]+nums[i+1]`)
- 1396A (the trick is to realize that the first number can be added with 0)
- 1348A (three cases, greedy)
- 1458A (solved on my own after knowing `gcd(x,y) == gcd(x-y,y)`)
- 1342C (solved on my own after knowing `(x % a) % b == [(ab + x)% a] % b`; given the small constraints on `a` and `b`, we only test numbers within `[0, ab-1]`)

### 03/18/2023

- 510C (almost solved it but I neglected a corner case)
- 1519D (expand from the center)
- 1165D (my initial approach was similar: computing the LCM of all, and check if number of divisors is the same as array length; the key is to realize `x = nums[0] * nums[n-1]`)
- 1374E1 (actually easy - just greedy)
- 1327C (ridiculous problem - bounded by the `2nm` which implies that it is always possible; snake-like traversal)
- 1395C (just do complete search given the low constraint `2^9`)
- 1371D (think about how to evenly distribute the 1's across all rows and columns)
- 1305C (the constraints are very tricky - if `n > m` then there must be duplicates, causing the final product to be zero)
- 1503A (a beautiful problem that tests my thinking - eventually realize that for all `1`s, we need half of them to be left and the other half to be right, so we construct them first)
- 1364C (I didn't see `0 <= ai <= i` - _need to come back to this_)
- 1514C (the sequence cannot contain a coprime)

### 03/31/2023

- 1527C (the key is to compute the sum of prefix sums for a number at an index `i`)
- 1542C (LCM... check out [this post](https://blog.csdn.net/tkkdouzi/article/details/118877468))
- 1603B (intuition is to imagine a number line for the case `x <= y`)
- 1475E (use 0-1 knapsack at initialization)
- 1513C (a really tough one - notice if the digit is already `10`, the resulting number of digits after `i` operations)
- 1303C (greedily check `pos+1` and `pos-1`)

### 04/09/2023

- 1455D (when we see `nums[i] > x` we need to swap; otherwise, we cannot swap it with `nums[j]` where `j>i` as `nums[j]` will become `x` but `nums[i] > x` and it won't be sorted.)
