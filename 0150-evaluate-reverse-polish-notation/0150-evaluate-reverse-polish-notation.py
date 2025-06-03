class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ans = []

        for i in tokens:
            if i == '+' or i == '-' or i == '*' or i == '/':
                op1 = ans[-1] 
                ans.pop()
                op2 = ans[-1] 
                ans.pop()
                if i == '+':
                    num = op1 + op2
                elif i == '-':
                    num = op2 - op1
                elif i == '*':
                    num = op2 * op1
                else:
                    num = int(op2 / op1) 
                
                ans.append(num)
            else:
                ans.append(int(i))
        
        return ans[0]
