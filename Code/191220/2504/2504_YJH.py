import sys

s = sys.stdin.readline()
stack = []
tmp1 = 0
tmp2 = 0

for x in s:

    stack.append(x)

    if x == ')':
        stack.pop()
        if stack[-1] == '(':
            stack.pop()
            stack.append(str(2))

        elif stack[-1].isdecimal() and stack[-2] == '(':
            tmp1 += 2*int(stack.pop())
            stack.pop()
            stack.append(str(tmp1))
            tmp1 = 0

        elif stack[-1].isdecimal() and stack[-2] != '(':
            while stack[-1] != '(':
                tmp2 += int(stack.pop())
            stack.pop()
            stack.append(str(2*tmp2))
            tmp2 = 0

    elif x == ']':
        stack.pop()
        if stack[-1] == '[':
            stack.pop()
            stack.append(str(3))

        elif stack[-1].isdecimal() and stack[-2] == '[':
            tmp1 += 3*int(stack.pop())
            stack.pop()
            stack.append(str(tmp1))
            tmp1 = 0
            
        elif stack[-1].isdecimal() and stack[-2] != '[':
            stack.pop()
            while stack[-1] != '[':
                tmp2 += int(stack.pop())
            stack.pop()
            stack.append(str(3*tmp2))
            tmp2 = 0


print(sum(i) for i in stack)
