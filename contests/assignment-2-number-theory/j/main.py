while True:
  n = int(input())
  if n == 0:
    break
  print(list(filter(lambda x: n > 0 or x[0] % 2 == 1, filter(lambda x: abs(round(x[1]) - x[1]) < 0.0000000000001, map(lambda x: (x, abs(n) ** (1 / x)), [i for i in range(31, 0, -1)]))))[0][0])
