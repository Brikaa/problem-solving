s = input().split('^')
print(s)
print(len(s))
print(len(set(s)))
t = 0
for i in s:
  t ^= int(i)
print(t)
