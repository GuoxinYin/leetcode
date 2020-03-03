Description
--
Implement `int sqrt(int x)`.

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned. only.

Example
--
1. Input: 4 Output: 2
2. Input: 8 Output: 2 Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

cpp solutions 
---
#### First Attempt
```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int a = x / 2;
        while (a != 0) {
            if (a * a > 0) {
                if (a * a <= x) {
                    if ((a + 1) * (a + 1) < 0) continue;
                    if ((a + 1) * (a + 1) > x) return a;
                    else if ((a + 1) * (a + 1) == x) return a + 1;
                    a++;
                } else {
                    a /= 2;
                }
            } else {
                a /= 2;
            }

        }
        return a;
    }
};
```
#### Second Attempt:
```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int a = x / 2;
        while (a != 0) {
            if (a == x / a) return a;
            if (a < x / a) {
                int begin = a;
                int end = 2 * a + 1;
                while (begin < end) {
                    int mid = (begin + end) / 2;
                    if (mid > x / mid) end = mid;
                    else {
                        begin = mid + 1;
                    }
                }
                return begin - 1;
            } else {
                a /= 2;
            }
        }
        return a;
    }
};
```

Some Ideas
--
#### For First Attempt
To deal with integer overflow, I check whether `a*a > 0`. It works on Clion but not on LeetCode, not sure why, maybe because this is a tricky way to solve problem...

#### For Second Attempt
1. To overcome integer overflow, instead of using `a*a>x`, we should use `a>x/a`.
2. The first attempt uses linear search when knowing that the return value is within `[a,2a)`. However, the second attempt uses binary search to find the return value. Note that `int end = 2 * a + 1` is because the original `end` value can never be returned since we return `begin+1`. However, when the input is 6, 6/2 = 3, 3/2 = 1. When entering the while loop, `begin = 1, end = 2`, but the return value is 2, thus we need to add one to the original end value to let it detect 2.

#### [Tricky solution](https://leetcode.com/problems/sqrtx/discuss/25057/3-4-short-lines-Integer-Newton-Every-Language) using [Newton Method](https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division)
```cpp
    long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r;
```
Looks like it use `long` to deal with integer overflow.
