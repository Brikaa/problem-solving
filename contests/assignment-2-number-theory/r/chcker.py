from collections import Counter
s = list(map(int, input().split('^')))
print(s)
print(len(s))
print(len(set(s)))
t = 0
for i in s:
  if i > 1e6:
    print(i)
  t ^= i
cnt = Counter(s)
print([k for k, v in cnt.items() if v > 1])
print(t)
