def solve(N,M,arr):
  l = []
  for i in range(M-1,-1,-1):
    for j in range(N):
      l.append(arr[j][i])
  for i in l:
    print(i, end = ' ')
