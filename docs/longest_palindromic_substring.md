# Longest Palindromic Substring
Medium

Given a string s, return the longest 
palindromic substring in s.

### Example 1:

- Input: s = "babad"
- Output: "bab"
- Explanation: "aba" is also a valid answer.

### Example 2:

- Input: s = "cbbd"
- Output: "bb"

### Constraints:

- 1 <= s.length <= 1000
- s consist of only digits and English letters.

### Solutions:

Center expand:
- String with size `n` has `2n - 1` centers (`n` characters and `n - 1` interval between characters).
- Expand from each center to check if corresponding characters are same.