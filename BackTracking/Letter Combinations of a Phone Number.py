# Problem : Letter Combinations of a Phone Number
# Platform : LeetCode
class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        
        if (len(digits) == 0):
            return []
        
        digit_to_word = {"2": "abc", "3": "def", "4": "ghi",
                         "5": "jkl", "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
        ans = []

        def solve(index: int, digits: str, temp: list, ans: list):

            if index == len(digits):
                ans.append("".join(temp))
                return

            word = digit_to_word[digits[index]]

            for letter in word:
                temp.append(letter)
                solve(index+1, digits, temp, ans)
                temp.pop()

        solve(0, digits, [], ans)
        return ans
