Description
--
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example
--
1. Input: 121 Output: true
2. Input: -121 Output: false Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
3. Input: 10 Output: false Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

cpp solutions
--
```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        if (x==0){
            return true;
        }
        long long int num = 0;//use int here will cause overflow
        int origin = x;
        while (x!=0){
            num = num*10 + x%10;
            x/=10;
        }
        if (num == origin){
            return true;
        } 
        return false; 
    }
};
```

Some Ideas
1. In my first attemp, the type of *num* is `int`, which will cause overflow since the largest number using `int` is 2147483647. When we reverse this number, it becomes 7463847412, which is larger than the `INT_MAX`.
2. After viewing the solution given by LeetCode, the solution can be simplified by only reverse half of the input number and then compare it with the remaining half. Also, the solution checks with the input number is a multiple of ten in the beginning, which will lead to false as the example #3 says. The solution is also great since it also saves the space to store the original input number. It should be notice that if the input number has odd digits, we should remove the middle one, just mod the *num* by ten. Revising my cpp code, it becomes

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || x%10 == 0){
            return false;
        }
        if (x==0){
            return true;
        }
        int num = 0;
        while (x>num){
            num = num*10 + x%10;
            x/=10;
        }
        //notice that we can simplify the following codes into
        //return num==origin || (num%10)==origin;
        if (num == origin || (num%10)==origin){
            return true;
        } 
        return false; 
    }
};
```
