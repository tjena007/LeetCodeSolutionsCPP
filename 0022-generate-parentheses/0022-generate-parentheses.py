class Solution:
    def __init__(self):
        self.ans = set()

    def helper(self, n, s, open, close):
        if open == n and close == n:
            final = "".join(s)
            self.ans.add(final)
            return

        if open < n:
            s.append('(')
            self.helper(n, s, open + 1, close)
            s.pop()  # backtrack

        if close < open:
            s.append(')')
            self.helper(n, s, open, close + 1)
            s.pop()  # backtrack

    def generateParenthesis(self, n: int) -> List[str]:
        self.ans = set()
        self.helper(n, [], 0, 0)
        print(self.ans)
        return list(self.ans)
