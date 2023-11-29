# abs(x - y) <= abs(x) and abs(x + y) >= abs(y) or abs(x - y) >= abs(x) and abs(x + y) <= abs(y)
x = int(input())
y = int(input())

print(abs(x - y) <= abs(x) and abs(x + y) >= abs(y) or abs(x - y) >= abs(x) and abs(x + y) <= abs(y))
