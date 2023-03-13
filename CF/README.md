# CF

My solutions to some CF problems.

## Weak categories

- [ ] Greedy
- [ ] Constructive algorithms
- [ ] Number theory

## Journal

### 03/12/2023

- [x] 1528A

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
