Description
--

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example
--

```
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
```

```
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
```

```
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

cpp solutions
---

#### My ugli attempt
```cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0 || n == 1) return 0;

        int minv = prices[0];
        int profit = 0;
        int num = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] < minv) {
                if (prices[i]<prices[i-1]) {
                    profit += num;
                    num = 0;
                }
                minv = prices[i];
            } else {
                num = max(num, prices[i] - minv);
                if (prices[i] < prices[i - 1]) {
                    minv = prices[i];
                    profit += num;
                    num = 0;
                }
            }
        }
        if (num!=0) profit += num;
        return profit;
    }
};
```

#### Elegent [Code](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/39420/Three-lines-in-C%2B%2B-with-explanation) From Discussion

```cpp
int maxProfit(vector<int> &prices) {
    int ret = 0;
    for (size_t p = 1; p < prices.size(); ++p)
      ret += max(prices[p] - prices[p - 1], 0);
    return ret;
}
```

Some Ideas
--

For my solution, common mistake is

1. What if we never enter into the inner `if` loop within the `else` statement, which means we never update the `profit`. To solve this problem, I check whether `num` is nonzero in the end.
2. When updating the `minv`, we still need to check whether it is smaller than the previous value. For example, if the input is `[2,1,2,0,1]`, we cannot simply replace the `minv` with 0, we should first update the `profit` and then update `minv`.