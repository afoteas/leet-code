class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ret = 0
        stack = []
        for token in tokens:
            if token in ["+","-","*","/"]:
                right = stack.pop()
                left = stack.pop()
                print(f"{left}{token}{right}")
                if token == "+":
                    stack.append(left + right)
                elif token == "-":
                    stack.append(left - right)
                elif token == "*":
                    stack.append(left * right)
                else:
                    stack.append(int(left / right))
            else:
                stack.append(int(token))
        print(stack)
        return stack[0]
        