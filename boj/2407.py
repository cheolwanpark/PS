n, m = map(int, input().split())
memo = [0] * 101
memo2 = [0] * 101
memo[0] = memo[1] = 1
for i in range(2, n+1):
    memo2[0] = 1
    for j in range(1, m+1):
        memo2[j] = memo[j] + memo[j-1]
    memo, memo2 = memo2, memo
print(memo[m])

